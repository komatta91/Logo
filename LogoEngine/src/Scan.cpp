#include "Scan.h"
#include <sstream>

Scan::Scan(std::string source) : source(source), textPos(0), lineNum(1)
{
	maper["np"] = np;
	maper["ws"] = ws; 
	maper["pw"] = pw;
	maper["lw"] = lw; 
	maper["czekaj"] = czekaj; 
	maper["pod"] = pod;
	maper["opu"] = opu; 
	maper["zmaz"] = zmaz; 
	maper["wroc"] = wroc; 
	maper["czysc"] = czysc; 
	maper["powtorz"] = powtorz;
	maper["oto"] = oto;
	maper["juz"] = juz; 
	maper["jesli"] = jesli;
}


Scan::~Scan(void)
{
}

SysType Scan::NextSymbol()
{
	char c;
	
	if (nextChar(c))
	{

		while(isspace(c))
		{
			if (c == '\n')
			{
				++lineNum;
				return nl;
			}
			nextChar(c);
		}

		if(isalpha(c))
		{
			std::string temp;
			temp.push_back(c);
			while(nextChar(c, false) && isalpha(c))
			{
				nextChar(c);
				temp.push_back(c);
			}
			SysType s;
			if (isKeyword(temp, s))
			{
				return s;
			} else
			{
				spell = temp;
				return ident;
			}
		}

		if(isdigit(c))
		{
			std::string temp;
			temp.push_back(c);
			while(nextChar(c, false) && isdigit(c))
			{
				nextChar(c);
				temp.push_back(c);
			}
			std::istringstream iss(temp);
			iss >> intConst; 
			return intconst;
		}

		switch(c)
		{
			case '=':
				if (nextChar(c, false) && c == '=')
				{
					nextChar(c);
					return eqop;
				} else
				{
					return becomes;
				}
			case ':': return define;
			case '<': 
				if(nextChar(c, false) && c == '=') 
				{ 
					nextChar(c);
					return leop;
				}
				else if(c=='>') 
				{ 
					nextChar(c);
					return neop; 
				}
				return ltop;
			case '>':
				if(nextChar(c, false) && c == '=') 
				{ 
					nextChar(c);
					return geop;
				}
				return gtop;

				case '+': return plus;
				case '-': return minus;
				case '*': return times;
				case '/': return divop;
				case '(': return lparent;
				case ')': return rparent;
				case '[': return lbracket;
				case ']': return rbracket;
		}
	} else 
	{
		return end;
	}
	return error;
}

bool Scan::isKeyword(std::string test, SysType& out)
{
	std::map<std::string, SysType>::iterator it = maper.find(test);
	if(it != maper.end())
	{
		//element found;
		out = it->second;
		return true;
	}
	return false;
}

bool Scan::nextChar(char& c, bool pass)
{
	if (textPos < source.length())
	{
		c = source[textPos];
		if (pass)
		{
			textPos++;
		}
		return true;
	}
	return false;
}