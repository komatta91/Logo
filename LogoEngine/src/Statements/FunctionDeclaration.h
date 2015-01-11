#pragma once
#include <string>
#include <list>

#include <Statements\Statement.h>

class FunctionDeclaration :
	public Statement
{
	std::string ident;
	std::list<std::string>* parameters;
	std::list<Statement*>* function;
public:
	FunctionDeclaration(std::string ident, std::list<std::string>* parameter, std::list<Statement*>* function);
	std::list<std::string>* GetParameters();
	int Execute();
	virtual ~FunctionDeclaration();
};

