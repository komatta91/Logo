#pragma once
#include <string>
#include <Statements/Statement.h>

class SimpExpr;
class Factor : public Statement
{
	SimpExpr* expr;
	std::string name;
	int value;
public:
	Factor(SimpExpr* expr) : expr(expr), value(-1) {}
	Factor(std::string name) : expr(NULL), name(name), value(-1) {}
	Factor(int value) : expr(NULL), value(value) {}
	virtual int Execute(void);
};

