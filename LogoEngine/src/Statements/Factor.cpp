#include "Factor.h"
#include <iostream>
#include <Statements/SimpExpr.h>
#include <Stack.h>
int Factor::Execute(void)
{
	//std::cout << "Factor\n";
	if (!name.empty())
	{
		Stack::GetInstance().GetValue(name);
	}
	if (expr)
	{
		return expr->Execute();
	}
	return value;
}
