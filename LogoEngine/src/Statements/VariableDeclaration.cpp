#include "VariableDeclaration.h"
#include <Stack.h>
#include <iostream>

VariableDeclaration::VariableDeclaration(std::string name, SimpExpr* expr)
	: name(name), expr(expr)
{
}


VariableDeclaration::~VariableDeclaration()
{
}

int VariableDeclaration::Execute()
{
	std::cout << "VariableDeclaration: " << name << " = " << expr->Execute() << std::endl;
	Stack::GetInstance().SetValue(name, expr->Execute());
	return 0;
}