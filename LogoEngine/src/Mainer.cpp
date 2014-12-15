#include <iostream>
#include <Scan.h>
#include <Stack.h>
#include <Statements\AllStatements.h>
#include <Parser.h>

int main(int argc, const char* argv[])
{
	Scan scan("np 12\n" 
			  //"lw 90\n" 
			  //"np 10\n" 
			  //"lw 90\n" 
			  //"lw ((4 + 6 ) * 5) + pies\n" 
			  //"lw ((4 + 6 ) * 5) + kot\n" 
			  //"opu     \n"
			  //"pod\n" 
			  //"lw ((4 + 6 ) * 5) + 10\n"
			  "jesli (((4 + 6 ) * 5) + kot > ((4 + 6 ) * 5) + pies) [ lw 1 ] [ jesli (1 > 2) [ lw 2 ] [ lw 3 pod ] ]\n"
			  );
	
	
	/*
	SysType type;
	while(error != (type = scan.NextSymbol()))
	{
		if (nl == type)
		{
			std::cout << "LineNum: " << scan.LineNum() - 1 << std::endl;
		}
	}
	*/

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
	if (p.Parse())
	{
		p.GetProgram()->Execute();
	}


	//Factor* fac = new Factor(10);
	//Term* term = new Term(fac, '*', fac);
	//SimpExpr* exp = new SimpExpr(term, '+', term);

	//std::cout << "SimpExpr: " << exp->Execute() << std::endl;
	


	std::cout << "Hello!!!" << std::endl;

#if defined(DEBUG) || defined(_DEBUG)
	system("Pause");
#endif
}

