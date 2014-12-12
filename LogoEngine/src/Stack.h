#pragma once
#include <string>

class Stack
{
	Stack(void);
	Stack(const Stack& other);
	Stack& operator=(const Stack&);
	~Stack(void);
public:
	static Stack& GetInstance();
	int GetValue(std::string& name);
};

