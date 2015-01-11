#include "FunctionCall.h"
#include <iostream>
#include <Statements\FunctionDeclaration.h>
#include <Stack.h>

#include <vector>

FunctionCall::FunctionCall(Program* program, std::string ident, std::list<SimpExpr*>* exprList) 
	: ident(ident), exprList(exprList), program(program)
{
}


FunctionCall::~FunctionCall()
{
    /*
    if (exprList)
    {
        for each (auto expr in *exprList)
        {
            if (expr)
            {
                delete expr;
            }
        }

        delete exprList;
    }
    */
}

int FunctionCall::Execute()
{
	std::cout << "FunctionCall: " << ident << std::endl;
	FunctionDeclaration* function = program->GetFunction(ident);
	std::list<std::string>* parametersNames = function->GetParameters();

	

	if (parametersNames->size() == exprList->size())
	{
		Stack::GetInstance().Enter(); //nowy poziom
		Stack& s = Stack::GetInstance();
		auto expr = exprList->begin();
		for each (auto parameterName in *parametersNames)
        {
			Stack::GetInstance().SetValue(parameterName, (*expr)->Execute()); //wpisanie zmiennej wartoœci
			expr++;
		}
		function->Execute();
		Stack::GetInstance().Leave(); // zdjêcie poziomu
		return 0;
	}
	return -1;
}
