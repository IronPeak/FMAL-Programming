#include "Lexer.h"

Lexer::Lexer()
{

}

Lexer::~Lexer()
{

}

TokenCode Lexer::nextToken()
{
    string token;
    cin >> token;
    if(isASSIGN(token))
    {
        cout << token << " " << "ASSIGN" << endl;
        lexeme = token;
        tCode = ASSIGN;
        return ASSIGN;
    }
    if(isSEMICOL(token))
    {
        cout << token << " " << "SEMICOL" << endl;
        lexeme = token;
        tCode = SEMICOL;
        return SEMICOL;
    }
    if(isINT(token))
    {
        cout << token << " " << "INT" << endl;
        lexeme = token;
        tCode = INT;
        return INT;
    }
    if(isADD(token))
    {
        cout << token << " " << "ADD" << endl;
        lexeme = token;
        tCode = ADD;
        return ADD;
    }
    if(isSUB(token))
    {
        cout << token << " " << "SUB" << endl;
        lexeme = token;
        tCode = SUB;
        return SUB;
    }
    if(isMULT(token))
    {
        cout << token << " " << "MULT" << endl;
        lexeme = token;
        tCode = MULT;
        return MULT;
    }
    if(isLPAREN(token))
    {
        cout << token << " " << "LPAREN" << endl;
        lexeme = token;
        tCode = LPAREN;
        return LPAREN;
    }
    if(isRPAREN(token))
    {
        cout << token << " " << "RPAREN" << endl;
        lexeme = token;
        tCode = RPAREN;
        return RPAREN;
    }
    if(isPRINT(token))
    {
        cout << token << " " << "PRINT" << endl;
        lexeme = token;
        tCode = PRINT;
        return PRINT;
    }
    if(isEND(token))
    {
        cout << token << " " << "END" << endl;
        lexeme = token;
        tCode = END;
        return END;
    }
    if(isID(token))
    {
        cout << token << " " << "ID" << endl;
        lexeme = token;
        tCode = ID;
        return ID;
    }
    //ERROR:
    cout << token << " " << "ERROR" << endl;
    lexeme = token;
    tCode = ERROR;
    return ERROR;
}

string Lexer::lastLexeme() const
{
    return lexeme;
}

TokenCode Lexer::lastTokenCode() const
{
    return tCode;
}

bool Lexer::isID(string& token) const
{
    for(unsigned int i = 0; i < token.size(); i++)
    {
        if(isalpha(token[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool Lexer::isASSIGN(string& token) const
{
    return token == "=";
}

bool Lexer::isSEMICOL(string& token) const
{
    return token == ";";
}

bool Lexer::isINT(string& token) const
{
    for(unsigned int i = 0; i < token.size(); i++)
    {
        if(isdigit(token[i]) != true)
        {
            return false;
        }
    }
    return true;
}

bool Lexer::isADD(string& token) const
{
    return token == "+";
}

bool Lexer::isSUB(string& token) const
{
    return token == "-";
}

bool Lexer::isMULT(string& token) const
{
    return token == "*";
}

bool Lexer::isLPAREN(string& token) const
{
    return token == "(";
}

bool Lexer::isRPAREN(string& token) const
{
    return token == ")";
}

bool Lexer::isPRINT(string& token) const
{
    return token == "print";
}

bool Lexer::isEND(string& token) const
{
    return token == "end";
}
