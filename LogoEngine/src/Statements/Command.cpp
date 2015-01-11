#include "Command.h"
#include <iostream>
#include <Turtle.h>

Command::Command(SysType type, SimpExpr* simpExpr) : simpExpr(simpExpr), type(type)
{
}


Command::~Command(void)
{
	delete simpExpr;
}

int Command::Execute(void)
{
	//std::cout << "Command: " << simpExpr->Execute() << std::endl;
	std::cout << "Command(" << type << "): " << simpExpr->Execute() << ""<< std::endl;
	switch (type)
	{
		case np :
		{
			Turtle::GetInstance().Move(simpExpr->Execute());
			break;
		}
		case wst:
		{
			Turtle::GetInstance().Move(-simpExpr->Execute());
			break;
		}
		case pw:
		{
			Turtle::GetInstance().Rotate(simpExpr->Execute());
			break;
		}
		case lw:
		{
			Turtle::GetInstance().Rotate(-simpExpr->Execute());
			break;
		}
		case czekaj:
		{
            _sleep(simpExpr->Execute());
		}
	}



	return 0;
}
