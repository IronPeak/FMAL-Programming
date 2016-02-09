#include "Lexer.h"
#include "Parser.h"

int main()
{
    Lexer* myLexer = new Lexer();
	Parser* myParser = new Parser(myLexer);
	myParser->parse();
	delete myLexer;
	delete myParser;
	return 0;
}
