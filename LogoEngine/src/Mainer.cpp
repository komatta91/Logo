#include <iostream>
#include <Scan.h>
#include <Stack.h>
#include <Statements\AllStatements.h>
#include <Parser.h>

int main(int argc, const char* argv[])
{
	Scan scan(
			  



			  "oto kwadrat bok\n"
			  "powtorz 4[np bok lw 90 bok = bok / 2]\n"
			  "juz\n"
			  ":bok 100\n"
			  "powtorz 4[kwadrat bok bok = bok / 2 czekaj 2000]\n"
			  "np 10\n"
			  );

	/*



	"oto test pies mis\n"
	"np 10\n"
	":kot 10\n"
	":pies 5\n"
	"jesli (((4 + 6 ) * 5) + kot > ((4 + 6 ) * 5) + pies) [ lw 1 ] [ jesli (1 > 2) [ lw 2 ] [ lw 3 pod ] ]\n"
	"juz\n"
	":kot 10\n"
	":pies 5\n"
	"np 12\n"
	//"lw 90\n"
	//"np 10\n"
	//"lw 90\n"
	//"lw ((4 + 6 ) * 5) + pies\n"
	//"lw ((4 + 6 ) * 5) + kot\n"
	//"opu     \n"
	//"pod\n"
	//"lw ((4 + 6 ) * 5) + 10\n"
	"jesli (((4 + 6 ) * 5) + kot > ((4 + 6 ) * 5) + pies) [ lw 1 ] [ jesli (1 > 2) [ lw 2 ] [ lw 3 pod ] ]\n"
	"powtorz kot [ lw 3 pod ]\n"
	"kotek = ((4 + 6 ) * 5) + kot\n"
	"test 10 ((4 + 6 ) * 5) + kot\n"








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
	
	

	try
	{
/*		Stack& s = Stack::GetInstance();

		s.SetValue("kot", 10);
		s.SetValue("pies", 5);
		std::cout << "kot: " << s.GetValue("kot") << std::endl;
		std::cout << "pies: " << s.GetValue("pies") << std::endl;
		s.Enter();
		s.SetValue("kot", 15);
		s.SetValue("pies", 55);
		std::cout << "kot: " << s.GetValue("kot") << std::endl;
		std::cout << "pies: " << s.GetValue("pies") << std::endl;
		s.Leave();
		std::cout << "kot: " << s.GetValue("kot") << std::endl;
		std::cout << "pies: " << s.GetValue("pies") << std::endl;
		s.SetValue("kot", 20);
		std::cout << "kot: " << s.GetValue("kot") << std::endl;
		std::cout << "pies: " << s.GetValue("pies") << std::endl;


		std::cout << "qwert: " << s.GetValue("qwert") << std::endl;
		*/
		Parser p(&scan);
		if (p.Parse())
		{
			p.GetProgram()->Execute();
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Hello!!!" << std::endl;

#if defined(DEBUG) || defined(_DEBUG)
	system("Pause");
#endif
}

