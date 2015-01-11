#include "Repeat.h"
#include <iostream>

Repeat::Repeat(SimpExpr* expr, std::list<Statement*>* list) : expr(expr), list(list)
{
}


Repeat::~Repeat()
{
    /*
    if (list)
    {
        for each (auto it in (*list))
        {
            if (it)
            {
                delete it;
            }
        }
    }
    if (expr)
    {
        delete expr;
    }
    */
}

int Repeat::Execute()
{
	std::cout << "Repeat, Expr: " << expr->Execute() << std::endl;
	
	int lenght = expr->Execute();
	for (int i = 0; i < lenght; i++)
	{
		executeList();
	}
	return 0;
}

int Repeat::executeList()
{
	for (auto s = list->begin(); s != list->end(); ++s)
	{
		(*s)->Execute();
	}
	return 0;
}
