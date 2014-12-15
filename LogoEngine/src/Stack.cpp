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

int Stack::GetValue(const std::string& name)
{
	std::cout << "method\n";
	if (name == "kot")
	{
		return 10;
	}
	return 0;
}

