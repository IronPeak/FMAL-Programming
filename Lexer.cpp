#include "Lexer.h"

Lexer::Lexer()
{

}

Token Lexer::nextToken()
{
    string lexeme;
    char c;
    cin >> c;
    lexeme += c;
    if(isNumber(c))
    {
        c = cin.peek();
        while(isNumber(cin.peek()))
        {
            cin >> c;
            lexeme += c;
        }
        return Token(lexeme, INT);
    }
    else if(isLetter(c))
    {
        c = cin.peek();
        while(isLetter(cin.peek()))
        {
            cin >> c;
            lexeme += c;
        }
        if(isPRINT(lexeme))
        {
            return Token(lexeme, PRINT);
        }
        else if(isEND(lexeme))
        {
            return Token(lexeme, END);
        }
        else
        {
            return Token(lexeme, ID);
        }
    }
    else
    {
        while(true)
        {
            switch(c)
            {
            case '=':
                return Token("=", ASSIGN);
                break;
            case '+':
                return Token("+", ADD);
                break;
            case '-':
                return Token("-", SUB);
                break;
            case '*':
                return Token("*", MULT);
                break;
            case '(':
                return Token("(", LPAREN);
                break;
            case ')':
                return Token(")", RPAREN);
                break;
            case ';':
                return Token(";", SEMICOL);
                break;
            case '\t':
            case '\n':
            case ' ':
                return nextToken();
                break;
            default:
                lexeme += c;
                return Token(lexeme, ERROR);
                break;
            }
        }
    }
}

Token Lexer::getToken() const
{
    return token;
}

bool Lexer::isID(const string& token) const
{
    for(unsigned int i = 0; i < token.size(); i++)
    {
        if(isLetter(token[i]))
        {
            return false;
        }
    }
    return token.size() > 0;
}

bool Lexer::isINT(const string& token) const
{
    for(unsigned int i = 0; i < token.size(); i++)
    {
        if(isNumber(token[i]))
        {
            return false;
        }
    }
    return token.size() > 0;
}

bool Lexer::isPRINT(const string& token) const
{
    return token == "print";
}

bool Lexer::isEND(const string& token) const
{
    return token == "end";
}

bool Lexer::isNumber(char c) const
{
    return '0' <= c && c <= '9';
}

bool Lexer::isLetter(char c) const
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
