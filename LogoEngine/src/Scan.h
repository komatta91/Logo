#pragma once
#include <string>
#include <map>
#include <SysType.h>

class Scan
{
	std::string source;
	std::map<std::string, SysType> maper;
	std::string  spell;      // Ostatnio wczytany ident 
	int intConst;     // Warto�� ostatniej sta�ej liczbowej
	int textPos;
	
public:
	Scan(std::string source);
	~Scan(void);
	SysType NextSymbol();
	inline std::string Spell() { return spell; }
	inline int IntConst() { return intConst; }
public:
	bool isKeyword(std::string test, SysType& out);
	bool nextChar(char& c, bool pass = true);
};

