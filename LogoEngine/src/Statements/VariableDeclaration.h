#pragma once
#include <string>
#include <Statements\Statement.h>
#include <Statements\SimpExpr.h>


class VariableDeclaration :
	public Statement
{
	std::string name;
	SimpExpr* expr;
public:
	VariableDeclaration(std::string name, SimpExpr* expr);
	virtual ~VariableDeclaration();
	int Execute();
};

