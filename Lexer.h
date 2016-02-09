#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>
#include <queue>
#include "Token.h"

using namespace std;

class Lexer
{
    public:
        Lexer();

        Token nextToken();
        Token getToken() const;

        bool isID(const string& lexeme) const;
        bool isINT(const string& lexeme) const;
        bool isPRINT(const string& lexeme) const;
        bool isEND(const string& lexeme) const;

        bool isNumber(char c) const;
        bool isLetter(char c) const;
    private:
        Token token;
};

#endif // LEXER_H
