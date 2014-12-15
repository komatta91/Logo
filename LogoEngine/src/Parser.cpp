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
				if (!ParseLine())
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
	return true;
}

bool Parser::ParseLine()
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
				program->AddStatement(c);
				break;
			}
		case pod: 
		case opu:
		case zmaz: 
		case wroc:
		case czysc:
			{
				Order* o = parseOrder();
				program->AddStatement(o);
				break;
			}
		case jesli:
			{
				Condition* c = parseCondition();
				program->AddStatement(c);
				break;
			}
	}

	setOnTop();
	if (actual.top() == nl)
	{
		actual.pop();
		return true;
	}
	//sendError();
	if (actual.top() == error)
	{
		actual.pop();
	}
	return false;
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
