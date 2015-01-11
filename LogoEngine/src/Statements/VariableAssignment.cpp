#include "VariableAssignment.h"
#include <iostream>
#include <Stack.h>

VariableAssignment::VariableAssignment(std::string ident, SimpExpr* expr) : ident(ident), expr(expr)
{
}


VariableAssignment::~VariableAssignment()
{
    /*
    if (expr)
    {
        delete expr;
    }
    */
}

int VariableAssignment::Execute()
{
	std::cout << "VariableAssignment: " << ident << " = " << expr->Execute() << std::endl;
	Stack::GetInstance().SetValue(ident, expr->Execute());
	return 0;
}
