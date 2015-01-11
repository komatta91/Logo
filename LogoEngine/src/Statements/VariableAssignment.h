#pragma once
#include <Statements\Statement.h>
#include <string>
#include <Statements\SimpExpr.h>


class VariableAssignment :
	public Statement
{
	std::string ident;
	SimpExpr* expr;
public:
	VariableAssignment(std::string ident, SimpExpr* expr);
	int Execute();
	virtual ~VariableAssignment();
};

