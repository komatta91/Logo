#pragma once
#include <Scan.h>
#include <Statements/AllStatements.h>
#include <stack>
class Parser
{
	Scan* scan;
	Program* program;
	std::stack<SysType> actual;
public:
	Parser(Scan* scan);
	~Parser(void);
	void Parse(void);
	Program* GetProgram(void) { return program; };

private:
	SimpExpr* parseSimpleExpr();
	Term* parseTerm();
	Factor* parseFactor();
	bool parseCommand();
};

