#pragma once
#include <string>
#include <map>

enum SysType {
		np, 
		ws, 
		pw, 
		lw, 
		czekaj, 
		pod, 
		opu, 
		zmaz, 
		wroc, 
		czysc, 
		powtorz, 
		oto, 
		juz, 
		jesli,
		ident,      //napis
		intconst,   //sta³a
		becomes,    // '='
		define,     // ':'
		nl,         // '\n'
					// operatory arytmetyczne
		times,      // '*'
		divop,        // '/'
		plus,       // '+'
		minus,      // '-'
					// operatory logiczne
		ltop,       // '<'
		leop,            // '<='
		gtop,			// '>'
		geop,			// '>='
		eqop,			// '=='
		neop,			// '<>'
					// nawiasy
		lbracket,	// '['
		rbracket,	// ']'
		lparent,	// '('
		rparent,	    // ')'
		error
	};

class Scan
{
	std::string source;
	std::map<std::string, SysType> maper;
	std::string  spell;      // Ostatnio wczytany ident 
	int intConst;     // Wartoœæ ostatniej sta³ej liczbowej
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

