#pragma once
#include <Scan.h>
#include <Statements/AllStatements.h>
#include <stack>
#include <list>

class Parser
{
	Scan* scan;
	Program* program;
	std::stack<SysType> actual;
	std::list<std::string> errors;
	bool status;
public:
	Parser(Scan* scan);
	~Parser(void);
	bool Parse(void);
	Program* GetProgram(void) { return program; };

private:
	bool parseFunctionDec();
	bool ParseLine();
	
	Command* parseCommand();
	Order* parseOrder();
	Condition* parseCondition();


	SimpExpr* parseSimpleExpr();
	Term* parseTerm();
	Factor* parseFactor();
	std::list<Statement*>* parseList();

	void sendError();
	bool setOnTop();
};

