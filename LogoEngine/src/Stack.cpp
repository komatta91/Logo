#include "Stack.h"
#include <iostream>
#include <exception>;

Stack::Stack(void) : level(0)
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
	//std::cout << "method\n";
	//if (name == "kot")
	//{
	//	return 10;
	//}
	int l = level;
	while (l >= 0)
	{
		if (stack[l].find(name) != stack[l].end())
		{
			return stack[l][name];
		}
		l--;
	}
	std::string err = "Zmienna " + name + " nie zosta³a znaleziona.";
	throw std::exception(err.c_str());
}

void Stack::SetValue(const std::string& name, const int value)
{
	stack[level][name] = value;
}

void Stack::Enter()
{
	level++;
}

void Stack::Leave()
{
	stack[level] = std::map<std::string, int>();
	level--;

}

