#include <iostream>
#include <Scan.h>
#include <Stack.h>
#include <Statements\AllStatements.h>
#include <Parser.h>

int main(int argc, const char* argv[])
{
	Scan scan(//"np 10\n" 
			  //"lw 90\n" 
			  //"np 10\n" 
			  //"lw 90\n" 
			  //"np 10\n" 
			  //"lw 90\n"
			  //"np 10\n" 
			  "lw 90\n");
	
	//char c;
	//SysType type;
	//while(error != (type = scan.NextSymbol()))
	//{
	//	if (type == ident)
	//	{
	//		std::cout << "NextChar: (" << type << ")\"" << scan.Spell() << "\""<< std::endl;
	//	}
	//	if (type == intconst)
	//	{
	//		std::cout << "NextChar: (" << type << ")" << scan.IntConst() << ""<< std::endl;
	//	}
	//	if (type != ident && type != intconst)
	//	{
	//		std::cout << "NextChar: (" << type << ")" << std::endl;
	//	}
	//}
	Parser p(&scan);
	p.Parse();
	p.GetProgram()->Execute();

	Factor* fac = new Factor(10);
	Term* term = new Term(fac, '*', fac);
	SimpExpr* exp = new SimpExpr(term, '+', term);

	std::cout << "SimpExpr: " << exp->Execute() << std::endl;



	std::cout << "Hello!!!" << std::endl;

#if defined(DEBUG) || defined(_DEBUG)
	system("Pause");
#endif
}

