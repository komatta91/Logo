#pragma once
#include <Statements/Statement.h>
#include <Statements/SimpExpr.h>
#include <SysType.h>

class Command :
	public Statement
{
	SysType type;
	SimpExpr* simpExpr;
public:
	Command(SysType type, SimpExpr* statement);
	virtual ~Command(void);
	virtual int Execute(void);
};

