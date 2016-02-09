#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

using namespace std;

class Parser
{
    public:
        Parser(Lexer* lexer);

        void parse();
    private:
        Lexer* lexer;
        Token token;

        void parseStatement();
        void parseExpr();
        void parseTerm();
        void parseFactor();

        void expect(TokenCode expectation, string msg);
        void error(string msg);
};

#endif // PARSER_H
