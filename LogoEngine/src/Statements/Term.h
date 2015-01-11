#pragma once
#include <Statements\Statement.h>
#include <SysType.h>

class Factor;
class Term : public Statement
{
	Factor* factor1;
	Factor* factor2;
	SysType op;
public:
	Term(Factor* factor) : factor1(factor), factor2(0) {}
	Term(Factor* factor1, SysType op, Factor* factor2)  : factor1(factor1), factor2(factor2), op(op) {}
    ~Term();
	virtual int Execute(void);
};

