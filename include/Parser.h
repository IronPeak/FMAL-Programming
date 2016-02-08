#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

using namespace std;

class Parser
{
    public:
        Parser(Lexer* lexer);
        virtual ~Parser();

        void parse();
    private:
        Lexer* lexer;
        TokenCode tCode;

        void parseStatement();
        void parseExpr();
        void parseTerm();
        void parseFactor();

        void expect(TokenCode expectation);
};

#endif // PARSER_H
