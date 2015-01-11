#pragma once
#include <string>
#include <map>


class Stack
{
	Stack(void);
	Stack(const Stack& other);
	Stack& operator=(const Stack&);
	~Stack(void);

	int level;
	std::map<int, std::map<std::string, int>> stack;

public:
	static Stack& GetInstance();
	int GetValue(const std::string& name);
	void SetValue(const std::string& name, const int value);
	void Enter();
	void Leave();
};

