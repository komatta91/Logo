#include "Command.h"
#include <iostream>

Command::Command(SysType type, SimpExpr* simpExpr) : simpExpr(simpExpr), type(type)
{
}


Command::~Command(void)
{
}

int Command::Execute(void)
{
	//std::cout << "Command: " << simpExpr->Execute() << std::endl;
	std::cout << "Command: (" << type << ")" << simpExpr->Execute() << ""<< std::endl;
	return 0;
}
