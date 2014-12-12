#include "Stack.h"
#include <iostream>

Stack::Stack(void)
{
}


Stack::~Stack(void)
{
}

Stack& Stack::GetInstance()
{
	static Stack instance;
    return instance;
}

int Stack::GetValue(std::string& name)
{
	std::cout << "method\n";
	return 0;
}

