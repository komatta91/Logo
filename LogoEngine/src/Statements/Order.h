#pragma once
#include <Statements\statement.h>
#include <SysType.h>
class Order :
	public Statement
{
	SysType type;
public:
	Order(SysType type);
	virtual ~Order(void);
	virtual int Execute();
};

