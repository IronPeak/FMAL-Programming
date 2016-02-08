#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <iostream>

using namespace std;

enum TokenCode {ID, ASSIGN, SEMICOL, INT, ADD, SUB, MULT, LPAREN, RPAREN, PRINT, END, ERROR};

class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();

        TokenCode nextToken();
        string lastLexeme() const;
        TokenCode lastTokenCode() const;

        bool isID(string& token) const;
        bool isASSIGN(string& token) const;
        bool isSEMICOL(string& token) const;
        bool isINT(string& token) const;
        bool isADD(string& token) const;
        bool isSUB(string& token) const;
        bool isMULT(string& token) const;
        bool isLPAREN(string& token) const;
        bool isRPAREN(string& token) const;
        bool isPRINT(string& token) const;
        bool isEND(string& token) const;
    private:
        string lexeme;
        TokenCode tCode;
};

#endif // LEXER_H
