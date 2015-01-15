#include "Parser.h"
#include <iostream>
#include <sstream>



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
	setOnTop();
	
        Statement* s = parseFunctionDec();
        while (s != nullptr)
        {
            FunctionDeclaration* func = static_cast<FunctionDeclaration*>(s);
            program->AddFunction(func->GetName(), func);
			setOnTop();
            s = parseFunctionDec();
        }
        s = ParseLine();
        while (s != nullptr)
        {
            program->AddStatement(s);
			setOnTop();
            s = ParseLine();
        }
	return status;
}

FunctionDeclaration* Parser::parseFunctionDec()
{
    if (actual.top() == oto)
    {
        FunctionDeclaration* dec = nullptr;
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
		            dec = new FunctionDeclaration(name, divs, func);
		            //program->AddFunction(name, dec);

				}
		        return dec;
			}

		}
    }
    return nullptr;
}

Statement* Parser::ParseLine()
{
	Statement* s = nullptr;

	s = parseCommand();
	if (s == nullptr)
	{
		s = parseOrder();
	}
	if (s == nullptr)
	{
		s = parseIdent();
	}
	if (s == nullptr)
	{
		s = parseCondition();
	}
	if (s == nullptr)
	{
		s = parseRepeat();
	}
	if (s == nullptr)
	{
		s = parseVariableDeclaration();
	}
	setOnTop();
    if (actual.top() == nl || actual.top() == end)
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

Statement* Parser::parseIdent()
{
	if (actual.top() ==  ident)
	{
		Statement* s = nullptr;
		std::string ident = scan->Spell();
		actual.pop();
		setOnTop();
		s = parseVariableAssignment(ident);
		if (s == nullptr)
		{
			s = parseFunctionCall(ident);
		}
		return s;
	}
	return nullptr;
}

Repeat* Parser::parseRepeat()
{
	if (actual.top() == powtorz)
	{
	//Repeat* repeat = nullptr;
	SimpExpr* expr;
	std::list<Statement*>* list;
	actual.pop();
	expr = parseSimpleExpr();
	list = parseList();
	return new Repeat(expr, list);
	}
	return nullptr;
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
	if (actual.top() == define)
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
	return nullptr;
}

VariableAssignment* Parser::parseVariableAssignment(std::string ident)
{
		if (actual.top() == becomes)
		{
		actual.pop();
		SimpExpr* expr = parseSimpleExpr();
		return new VariableAssignment(ident, expr);
		}
		return nullptr;

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
	switch (actual.top())
	{
	case np:
	case wst:
	case pw:
	case lw:
	case czekaj:
	{
		SysType type = actual.top();
		actual.pop();
		return new Command(type, parseSimpleExpr());
	}
	}
	return nullptr;
	//actual.pop();
}

Order* Parser::parseOrder()
{
	switch (actual.top())
	{
	case pod:
	case opu:
	case zmaz:
	case wroc:
	case czysc:
	{
		SysType type = actual.top();
		actual.pop();
		return new Order(type);
	}
	}
	return nullptr;
}

Condition* Parser::parseCondition()
{
	if (actual.top() == jesli)
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
	return nullptr;
	} 
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
			Statement* s = nullptr;

			s = parseCommand();
			if (s == nullptr)
			{
				s = parseOrder();
			}
			if (s == nullptr)
			{
				s = parseIdent();
			}
			if (s == nullptr)
			{
				s = parseCondition();
			}
			if (s == nullptr)
			{
				s = parseRepeat();
			}
			if (s != nullptr)
			{
				temp->push_back(s);
			} else
			{
				actual.push(error);
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
    std::ostringstream osstream;
    osstream << "ERROR: " << actual.top() << " at line " << (actual.top() == nl ? scan->LineNum() - 1 : scan->LineNum()) << "\n" ;
    errors.push_back(osstream.str());
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

std::list<std::string> Parser::GetErrors() const
{
    return errors;
}
