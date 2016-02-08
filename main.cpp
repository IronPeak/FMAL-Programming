#include "Lexer.h"
#include "Parser.h"

int main()
{
    Parser* myParser = new Parser(new Lexer());
    myParser->parse();
    return 0;
}
