#pragma once

class Statement
{
public:
	Statement(void);
	virtual ~Statement(void);
	virtual int Execute(void) = 0;
};

