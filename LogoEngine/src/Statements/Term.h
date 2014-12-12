#pragma once
#include <Statements\Statement.h>

class Factor;
class Term : public Statement
{
	Factor* factor1;
	Factor* factor2;
	char op;
public:
	Term(Factor* factor) : factor1(factor), factor2(0) {}
	Term(Factor* factor1, char op, Factor* factor2)  : factor1(factor1), factor2(factor2), op(op) {}
	virtual int Execute(void);
};

