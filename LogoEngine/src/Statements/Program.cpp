#include "Program.h"


Program::Program(void)
{
}


Program::~Program(void)
{
	for(auto statement = statements.begin(); statement != statements.end(); ++statement)
	{
		delete (*statement);
	}
}

int Program::Execute(void)
{
	for(auto statement = statements.begin(); statement != statements.end(); ++statement)
	{
		(*statement)->Execute();
	}
	return 0;
}

void Program::AddStatement(Statement* statement)
{
	statements.push_back(statement);
}
