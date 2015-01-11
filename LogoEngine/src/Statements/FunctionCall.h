#pragma once
#include <Statements\Statement.h>

#include <list>
#include <string>
#include <Statements\SimpExpr.h>
#include <Statements\Program.h>

class FunctionCall :
	public Statement
{
	std::string ident;
	std::list<SimpExpr*>* exprList;
	Program* program;
public:
	FunctionCall(Program* program, std::string ident, std::list<SimpExpr*>* exprList);
	int Execute();
	virtual ~FunctionCall();
};

