#pragma once
#include <Statements/Statement.h>

class Term;
class SimpExpr : public Statement
{
	Term* term1;
	Term* term2;
	char op;
public:
	SimpExpr(Term* term) : term1(term), term2(0) {}
	SimpExpr(Term* term1, char op, Term* term2) : term1(term1), term2(term2), op(op) {}
	virtual int Execute(void);
};

