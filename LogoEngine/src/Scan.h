#pragma once
#include <string>
#include <map>
#include <SysType.h>

class Scan
{
	std::string source;
	std::map<std::string, SysType> maper;
	std::string  spell;      // Ostatnio wczytany ident 
	int intConst;     // Wartoœæ ostatniej sta³ej liczbowej
	int textPos;
	int lineNum;
public:
	Scan(std::string source);
	~Scan(void);
	SysType NextSymbol();
	inline std::string Spell() { return spell; }
	inline int IntConst() { return intConst; }
	inline int LineNum() { return lineNum; } 
private:
	bool isKeyword(std::string test, SysType& out);
	bool nextChar(char& c, bool pass = true);
};

