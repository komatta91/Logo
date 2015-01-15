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
    std::list<std::string> GetErrors() const;

private:
    FunctionDeclaration* parseFunctionDec();
	Statement* ParseLine();
	
	Statement* parseIdent();
	Command* parseCommand();
	Order* parseOrder();
	Condition* parseCondition();
	Repeat* parseRepeat();
	FunctionCall* parseFunctionCall(std::string ident);
	VariableAssignment* parseVariableAssignment(std::string ident);
	VariableDeclaration* parseVariableDeclaration();


	SimpExpr* parseSimpleExpr();
	Term* parseTerm();
	Factor* parseFactor();
	std::list<Statement*>* parseList();

	void sendError();
	bool setOnTop();
};

