#pragma once
#include <Statements/Statement.h>
#include <list>
class Program :	public Statement
{
	std::list<Statement*> statements;
public:
	Program(void);
	virtual ~Program(void);
	virtual int Execute(void);
	void AddStatement(Statement* statement);
};

