#include "Parser.h"


Parser::Parser(Scan* scan) : scan(scan)
{
	program = new Program();
}


Parser::~Parser(void)
{
	delete program;
}

void Parser::Parse(void)
{
	actual.push(scan->NextSymbol());
	switch (actual.top())
	{
		case np: 
		case ws: 
		case pw: 
		case lw: 
		case czekaj:
			parseCommand();
	}
}

SimpExpr* Parser::parseSimpleExpr()
{
	Term* term1 = parseTerm();
	//SysType token = scan->NextSymbol();
	//actual.push(token);
	//if (token == times)
	//{
	//	actual = scan->NextSymbol();
	//	Term* term2 = parseTerm();
	//	return
	//}
	return new SimpExpr(term1);
}

Term* Parser::parseTerm()
{
	Factor* factor1 = parseFactor();
	return new Term(factor1);
}

Factor* Parser::parseFactor()
{
	actual.push(scan->NextSymbol());
	switch(actual.top())
	{
		case ident : 
			actual.pop();
			return new Factor(scan->Spell());
		case intconst: 
			actual.pop();
			return new Factor(scan->IntConst());
		case lparent:
			SimpExpr* exp = parseSimpleExpr();
			if (rparent == scan->NextSymbol())
			{
				actual.pop();
				return new Factor(exp);
			}
	}
	return 0;
}

bool Parser::parseCommand()
{
	program->AddStatement(new Command(actual.top(), parseSimpleExpr()));
	actual.pop();
	return actual.empty();
}
