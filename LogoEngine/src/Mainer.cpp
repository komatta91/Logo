#include <iostream>
#include <Scan.h>

int main(int argc, const char* argv[])
{
	Scan scan("oto kwadrat :bok\n" 
			  "powtorz 4 [ np bok lw 90 ]\n" 
			  "juz\n" 
			  ":bok 100\n" 
			  "powtorz 4 [ kwadrat bok bok = bok / 2 czekaj 2 ]");
	
	char c;
	SysType type;
	while(error != (type = scan.NextSymbol()))
	{
		if (type == ident)
		{
			std::cout << "NextChar: (" << type << ")\"" << scan.Spell() << "\""<< std::endl;
		}
		if (type == intconst)
		{
			std::cout << "NextChar: (" << type << ")" << scan.IntConst() << ""<< std::endl;
		}
		if (type != ident && type != intconst)
		{
			std::cout << "NextChar: (" << type << ")" << std::endl;
		}
	}


	std::cout << "Hello!!!" << std::endl;

#if defined(DEBUG) || defined(_DEBUG)
	system("Pause");
#endif
}

