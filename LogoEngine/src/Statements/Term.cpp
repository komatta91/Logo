#include "Term.h"
#include <iostream>
#include <Statements/Factor.h>

int Term::Execute(void)
{
	//std::cout << "Term\n";
	if (factor1 && factor2 && times == op)
	{
		return factor1->Execute() * factor2->Execute();
	}
	if (factor1 && factor2 && divop == op)
	{
		return factor1->Execute() / factor2->Execute();
	}
	if (factor1)
	{
		return factor1->Execute();
	}
	return 0;
}

Term::~Term()
{
    /*
    if (factor1)
    {
        delete factor1;
    }
    if (factor2)
    {
        delete factor1;
    }
    */
}
