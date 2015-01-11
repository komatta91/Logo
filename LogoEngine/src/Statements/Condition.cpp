#include "Condition.h"
#include <iostream>

Condition::Condition(SimpExpr* expr1, SysType op, SimpExpr* expr2, std::list<Statement*>* list1)
	: expr1(expr1), expr2(expr2), op(op), list1(list1)
{
	list2 = new std::list<Statement*>();
}

Condition::Condition(SimpExpr* expr1, SysType op, SimpExpr* expr2, std::list<Statement*>* list1, std::list<Statement*>* list2)
	: expr1(expr1), expr2(expr2), op(op), list1(list1), list2(list2)
{

}


Condition::~Condition(void)
{
    /*
    if (expr1)
    {
        delete expr1;
    }
    if (expr2)
    {
        delete expr2;
    }
    if (list1)
    {
        for each (Statement* st in (*list1))
        {
            if (st)
            {
                delete st;
            }
        }
        delete list1;
    }
    if (list2)
    {
        for each (Statement* st in (*list2))
        {
            if (st)
            {
                delete st;
            }
        }
        delete list2;
    }
    */
}

int Condition::Execute()
{
	std::cout << "Condition, Expr1: " << expr1->Execute() << ", Expr2: " << expr2->Execute() << ", List1.size(): " << list1->size() << ", List2.size(): " << list2->size() << std::endl;
	switch (op)
	{
		case ltop:
			{
				if (expr1->Execute() < expr2->Execute())
				{
					return executeList(list1);
				} else
				{
					return executeList(list2);
				}
			} // '<'
			
		case leop:
			{
				if (expr1->Execute() <= expr2->Execute())
				{
					return executeList(list1);
				} else
				{
					return executeList(list2);
				}
			}// '<='
		case gtop:
			{
				if (expr1->Execute() > expr2->Execute())
				{
					return executeList(list1);
				} else
				{
					return executeList(list2);
				}
			}// '>'
		case geop:
			{
				if (expr1->Execute() >= expr2->Execute())
				{
					return executeList(list1);
				} else
				{
					return executeList(list2);
				}
			}			// '>='
		case eqop:
			{
				if (expr1->Execute() == expr2->Execute())
				{
					return executeList(list1);
				} else
				{
					return executeList(list2);
				}
			}// '=='
		case neop:
			{
				if (expr1->Execute() != expr2->Execute())
				{
					return executeList(list1);
				} else
				{
					return executeList(list2);
				}
			}// '<>'
	}
}

int Condition::executeList(std::list<Statement*>* list)
{
	for (auto s = list->begin(); s != list->end(); ++s)
	{
		(*s)->Execute();
	}
	return 0;
}
