#include "SimpExpr.h"
#include <iostream>
#include <Statements/Term.h>

int SimpExpr::Execute(void)
{
	//std::cout << "SimpExpr\n";
	if (term1 && term2 && op == '+')
	{
		return term1->Execute() + term2->Execute();
	}
	if (term1 && term2 && op == '-')
	{
		return term1->Execute() - term2->Execute();
	}
	if (term1)
	{
		return term1->Execute();
	}
	return -1;
}
