#include "Order.h"
#include <iostream>

Order::Order(SysType type) : type(type)
{
}


Order::~Order(void)
{
}

int Order::Execute()
{
	std::cout << "Order: (" << type << ")" << std::endl;
	return 0;
}
