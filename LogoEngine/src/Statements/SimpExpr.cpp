#include "SimpExpr.h"
#include <iostream>
#include <Statements/Term.h>

int SimpExpr::Execute(void)
{
	//std::cout << "SimpExpr\n";
	if (term1 && term2 && plus == op)
	{
		return term1->Execute() + term2->Execute();
	}
	if (term1 && term2 && minus == op)
	{
		return term1->Execute() - term2->Execute();
	}
	if (term1)
	{
		return term1->Execute();
	}
	return -1;
}

SimpExpr::~SimpExpr()
{
    /*
    if (term1)
    {
        delete term1;
    }
    if (term2)
    {
        delete term2;
    }
    */
}
