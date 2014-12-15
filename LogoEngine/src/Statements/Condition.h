#pragma once
#include <Statements\Statement.h>
#include <Statements\SimpExpr.h>
#include <list>

class Condition : public Statement
{
	SimpExpr* expr1;
	SimpExpr* expr2;
	SysType op;
	std::list<Statement*>* list1;
	std::list<Statement*>* list2;
public:
	Condition(SimpExpr* expr1, SysType op, SimpExpr* expr2, std::list<Statement*>* list1);
	Condition(SimpExpr* expr1, SysType op, SimpExpr* expr2, std::list<Statement*>* list1, std::list<Statement*>* list2);
	virtual ~Condition(void);
	virtual int Execute();
private:
	int executeList(std::list<Statement*>* list);
};

