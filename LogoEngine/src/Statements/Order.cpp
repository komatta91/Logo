#include "Order.h"
#include <iostream>
#include <Turtle.h>

Order::Order(SysType type) : type(type)
{
}

Order::~Order(void)
{
}

int Order::Execute()
{
	std::cout << "Order: (" << type << ")" << std::endl;

	switch (type)
	{
		case pod:
		{
			Turtle::GetInstance().SetMark(true);
		}
		case opu:
		{
			Turtle::GetInstance().SetMark(false);
		}
		case zmaz:
		{
			Turtle::GetInstance().Clean();
		}
		case wroc:
		{
			Turtle::GetInstance().Reset();
		}
		case czysc:
		{
			Turtle::GetInstance().Restart();
		}
	}
	return 0;
}
