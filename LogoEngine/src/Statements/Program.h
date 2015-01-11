#pragma once
#include <Statements/Statement.h>
#include <Statements\FunctionDeclaration.h>
#include <list>
#include <map>
class Program :	public Statement
{
	std::list<Statement*> statements;
	std::map<std::string, FunctionDeclaration*>* functions;
public:
	Program(void);
	void AddFunction(std::string name, FunctionDeclaration* func);
	FunctionDeclaration*GetFunction(std::string ident);
	virtual ~Program(void);
	virtual int Execute(void);
	void AddStatement(Statement* statement);
};

