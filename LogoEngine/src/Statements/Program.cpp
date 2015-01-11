#include "Program.h"


Program::Program(void)
{
	functions = new std::map<std::string, FunctionDeclaration*>();
}


Program::~Program(void)
{
    /*
    for(auto it = functions->begin(); it != functions->end(); ++it)
	{
        delete it->second;
    }
    delete functions;
    for(auto statement = statements.begin(); statement != statements.end(); ++statement)
    {
        delete (*statement);
    }
    */
}

int Program::Execute(void)
{
	for(auto statement = statements.begin(); statement != statements.end(); ++statement)
	{
		(*statement)->Execute();
	}
	return 0;
}

void Program::AddFunction(std::string name, FunctionDeclaration* func)
{
	(*functions)[name] = func;
}

void Program::AddStatement(Statement* statement)
{
	statements.push_back(statement);
}

FunctionDeclaration* Program::GetFunction(std::string ident)
{
	return (*functions)[ident];
}
