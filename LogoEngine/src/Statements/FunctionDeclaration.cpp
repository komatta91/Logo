#include "FunctionDeclaration.h"
#include <iostream>


FunctionDeclaration::FunctionDeclaration(std::string ident, std::list<std::string>* parameter, std::list<Statement*>* function)
	: ident(ident), parameters(parameter), function(function)
{
}


FunctionDeclaration::~FunctionDeclaration()
{
    /*
    if (parameters)
    {
        delete parameters;
    }
    if (function)
    {
        for each (auto st in (*function))
        {
            if (st)
            {
                delete st;
            }
        }
    }
    */
}

std::list<std::string>* FunctionDeclaration::GetParameters()
{
	return parameters;
}

int FunctionDeclaration::Execute()
{
	std::cout << "FunctionDeclaration: " << ident << std::endl;
	for (auto s = function->begin(); s != function->end(); ++s)
	{
		(*s)->Execute();
	}
	return 0;
}
