#include "Parser.h"
#include <iostream>



Parser::Parser(Scan* scan) : scan(scan)
{
	program = new Program();
}


Parser::~Parser(void)
{
	delete program;
}

bool Parser::Parse(void)
{
	status = true;
	//SysType type;
	setOnTop();
	while(end != actual.top())
	{
		switch (actual.top())
		{
			case oto: 
				if (!parseFunctionDec())
				{
					sendError();
				}
				break;
			//case error:
				//sendError();
				//actual.push(end);
				//break;
			default:
				Statement* s = ParseLine();
				if (s)
				{
					program->AddStatement(s);
				} else
				{
					sendError();
				}
		}
		setOnTop();
	}
	return status;
}

bool Parser::parseFunctionDec()
{
	actual.pop();
	setOnTop();
	std::list<std::string>* divs = new std::list<std::string>();
	std::list<Statement*>* func = new std::list<Statement*>();
	if (actual.top() == ident)
	{
		std::string name = scan->Spell();
		actual.pop();
		setOnTop();
		while (actual.top() != nl)
		{
			if (actual.top() == ident)
			{
				std::string div = scan->Spell();
				divs->push_back(div);
				actual.pop();
				setOnTop();
			}
			else
			{
				while (actual.top() != juz && actual.top() != end)
				{
					actual.pop();
					setOnTop();
				}
				return false;
			}
		}
		actual.pop();
		setOnTop();
		while (actual.top() != juz && actual.top() != error && actual.top() != end)
		{
			Statement* s = ParseLine();
			func->push_back(s);
			setOnTop();
		}
		if (actual.top() == juz)
		{
			actual.pop();
			setOnTop();
			if (actual.top() == nl)
			{
				actual.pop();
				FunctionDeclaration* dec = new FunctionDeclaration(name, divs, func);
				program->AddFunction(name, dec);
				return true;
			}
			return true;
		}

	}
	return false;
}

Statement* Parser::ParseLine()
{
	Statement* s = nullptr;
	switch (actual.top())
	{
		case np: 
		case ws: 
		case pw: 
		case lw: 
		case czekaj:
			{
				s = parseCommand();
				break;
			}
		case pod: 
		case opu:
		case zmaz: 
		case wroc:
		case czysc:
			{
				s = parseOrder();
				break;
			}
		case jesli:
			{
				s = parseCondition();
				break;
			}
		case powtorz:
		{
			s = parseRepeat();
			break;
		}
		case ident:
		{
			std::string ident = scan->Spell();
			actual.pop();
			setOnTop();
			if (actual.top() == becomes)
			{
				s = parseVariableAssignment(ident);
				break;
			}
			s = parseFunctionCall(ident);
			break;
		}
		case define:
		{
			s = parseVariableDeclaration();
			break;
		}
	}

	setOnTop();
	if (actual.top() == nl)
	{
		actual.pop();
		return s;
	}
	//sendError();
	if (actual.top() == error)
	{
		actual.pop();
	}
	return nullptr;
}

Repeat* Parser::parseRepeat()
{
	//Repeat* repeat = nullptr;
	SimpExpr* expr;
	std::list<Statement*>* list;
	actual.pop();
	expr = parseSimpleExpr();
	list = parseList();
	return new Repeat(expr, list);
}

FunctionCall* Parser::parseFunctionCall(std::string ident)
{
	std::list<SimpExpr*>* list = new std::list<SimpExpr*>();
	FunctionDeclaration* func = program->GetFunction(ident);
	int count;
	if (func)
	{
		count = func->GetParameters()->size();
		for (int i = 0; i < count; ++i)
		{
			SimpExpr* expr = parseSimpleExpr();
			list->push_back(expr);
			setOnTop();
		}
		return new FunctionCall(program, ident, list);
	} 
	return nullptr;
	//while (actual.top() != nl)
	
}

VariableDeclaration* Parser::parseVariableDeclaration()
{
	actual.pop();
	setOnTop();
	if (actual.top() == ident)
	{
		std::string name = scan->Spell();
		actual.pop();
		SimpExpr* expr = parseSimpleExpr();
		return new VariableDeclaration(name, expr);
	}
	return nullptr;
}

VariableAssignment* Parser::parseVariableAssignment(std::string ident)
{
	actual.pop();
	SimpExpr* expr = parseSimpleExpr();
	return new VariableAssignment(ident, expr);
}

SimpExpr* Parser::parseSimpleExpr()
{
	Term* term1 = parseTerm();
	setOnTop();
	if (plus == actual.top() || minus == actual.top())
	{
		SysType type = actual.top();
		actual.pop();
		Term* term2 = parseTerm();
		return new SimpExpr(term1, type, term2);
	}

	return new SimpExpr(term1);
}

Term* Parser::parseTerm()
{
	Factor* factor1 = parseFactor();
	setOnTop();
	SysType token = actual.top();
	if (times == token || divop == token)
	{
		actual.pop();
		Factor* factor2 = parseFactor();
		return new Term(factor1, token, factor2);
	}
	return new Term(factor1);
}

Factor* Parser::parseFactor()
{
	setOnTop();
	switch(actual.top())
	{
		case ident : 
			actual.pop();
			return new Factor(scan->Spell());
		case intconst: 
			actual.pop();
			return new Factor(scan->IntConst());
		case lparent:
			actual.pop();
			SimpExpr* exp = parseSimpleExpr();
			setOnTop();
			if (rparent == actual.top())
			{
				actual.pop();
				return new Factor(exp);
			}
	}
	actual.push(error);
	return 0;
}

Command* Parser::parseCommand()
{
	SysType type = actual.top();
	actual.pop();
	return new Command(type, parseSimpleExpr());
	//actual.pop();
}

Order* Parser::parseOrder()
{
	SysType type = actual.top();
	actual.pop();
	return new Order(type);
}

Condition* Parser::parseCondition()
{
	SysType type = actual.top();
	actual.pop();
	setOnTop();
	if (lparent == actual.top())
	{
		SysType op;
		SimpExpr* expr1;
		SimpExpr* expr2;
		std::list<Statement*>* list1;
		std::list<Statement*>* list2;		
		actual.pop();
		expr1 = parseSimpleExpr();
		setOnTop();
		if (ltop <= actual.top() && neop >= actual.top())
		{
			op = actual.top();
			actual.pop();
			expr2 = parseSimpleExpr();
			setOnTop();
			if (rparent == actual.top())
			{
				actual.pop();
			}
			list1 = parseList();
			list2 = parseList();
			if (list2)
			{
				return new Condition(expr1, op, expr2, list1, list2);
			} else 
			{
				return new Condition(expr1, op, expr2, list1);
			}
		}
		
	} 
	//SimpExpr* se1 = parseSimpleExpr();
	//SimpExpr* se1 = parseSimpleExpr();

	//return new Condition(parseSimpleExpr(), parseSimpleExpr, 
	
	return 0;
}

std::list<Statement*>* Parser::parseList()
{
	setOnTop();
	std::list<Statement*>* list = NULL;
	if (lbracket == actual.top())
	{
		actual.pop();
		setOnTop();
		std::list<Statement*>* temp = new std::list<Statement*>();
		while(true)
		{
			switch (actual.top())
			{
				case np: 
				case ws: 
				case pw: 
				case lw: 
				case czekaj:
					{
						Command* c = parseCommand();
						temp->push_back(c);
						break;
					}
				case pod: 
				case opu:
				case zmaz: 
				case wroc:
				case czysc:
					{
						Order* o = parseOrder();
						temp->push_back(o);
						break;
					}
				case jesli:
					{
						Condition* c = parseCondition();
						temp->push_back(c);
						break;
					}
				case powtorz:
					{
						Repeat* r = parseRepeat();
						temp->push_back(r);
						break;
					}
				case ident:
					{
						std::string ident = scan->Spell();
						actual.pop();
						setOnTop();
						if (actual.top() == becomes)
						{
							VariableAssignment* a = parseVariableAssignment(ident);
							temp->push_back(a);
							break;
						}
						FunctionCall* f = parseFunctionCall(ident);
						temp->push_back(f);
						break;
					}
				case define:
				{
					break;
				}
				default:
					{
						//std::cout << "Error" << std::endl;
						actual.push(error);
					}
			}
			setOnTop();
			if (rbracket == actual.top())
			{
				actual.pop();
				list = temp;
				break;
			}
			if (error == actual.top())
			{
				actual.pop();
				break;
			}

		}
	}
	return list;
}

void Parser::sendError()
{
	status = false;
	
	setOnTop();
	std::cout << "ERROR: " << actual.top() << " at line " << (actual.top() == nl ? scan->LineNum() -1 : scan->LineNum()) << std::endl;
	SysType token = actual.top();
	while (!(nl == token || end == token))
	{
		token = scan->NextSymbol();
	}
	actual = std::stack<SysType>();
}

bool Parser::setOnTop()
{
	SysType type;
	if (actual.empty())
	{
		type = scan->NextSymbol();
		actual.push(type);
		return true;
	}
	return false;
}
