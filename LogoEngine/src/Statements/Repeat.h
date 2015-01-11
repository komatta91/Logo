#pragma once

#include <list>
#include <Statements\Statement.h>
#include <Statements\SimpExpr.h>

class Repeat :
	public Statement
{
	SimpExpr* expr;
	std::list<Statement*>* list;
public:
	Repeat(SimpExpr* expr, std::list<Statement*>* list);
	virtual int Execute();
	virtual ~Repeat();
private:
	int executeList();
};

