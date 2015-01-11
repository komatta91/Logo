#include "Factor.h"
#include <iostream>
#include <Statements/SimpExpr.h>
#include <Stack.h>

int Factor::Execute(void)
{
	if (!name.empty())
	{
		return Stack::GetInstance().GetValue(name);
	}
	if (expr)
	{
		return expr->Execute();
	}
	return value;
}

Factor::~Factor()
{
    //SafeDelete(expr);
    /*
    if (expr)
    {
        delete expr;
    }
    */
}
