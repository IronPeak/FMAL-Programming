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
        bool isASSIGN(const char& lexeme) const;
        bool isSEMICOL(const char& lexeme) const;
        bool isINT(const string& lexeme) const;
        bool isADD(const char& lexeme) const;
        bool isSUB(const char& lexeme) const;
        bool isMULT(const char& lexeme) const;
        bool isLPAREN(const char& lexeme) const;
        bool isRPAREN(const char& lexeme) const;
        bool isPRINT(const string& lexeme) const;
        bool isEND(const string& lexeme) const;

        bool isNumber(char c) const;
        bool isLetter(char c) const;
    private:
        Token token;
};

#endif // LEXER_H
