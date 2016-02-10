#include "Parser.h"

Parser::Parser(Lexer* lexer)
{
    this->lexer = lexer;
}

void Parser::parse()
{
    try {
    token = lexer->nextToken();
    parseStatement();
    }
    catch(...) {
        return;
    }
}

void Parser::parseStatement()
{
    switch(token.getCode())
    {
    case END:
        return;
    case ID:
        cout << "PUSH " << token.getLexeme() << endl;
        token = lexer->nextToken();
        expect(ASSIGN, "Syntax error!");
        token = lexer->nextToken();
        parseExpr();
        cout << "ASSIGN" << endl;
        break;
    case PRINT:
        token = lexer->nextToken();
        expect(ID, "Syntax error!");
        cout << "PUSH " << token.getLexeme() << endl;
        cout << "PRINT" << endl;
        token = lexer->nextToken();
        break;
    default:
        error("Syntax error!");
        return;
    }
    expect(SEMICOL, "Syntax error!");
    token = lexer->nextToken();
    parseStatement();
}

void Parser::parseExpr()
{
    parseTerm();
    switch(token.getCode())
    {
    case ADD:
        token = lexer->nextToken();
        parseExpr();
        cout << "ADD" << endl;
        break;
    case SUB:
        token = lexer->nextToken();
        parseExpr();
        cout << "SUB" << endl;
        break;
    default:
        return;
    }
}

void Parser::parseTerm()
{
    parseFactor();
    switch(token.getCode())
    {
    case MULT:
        token = lexer->nextToken();
        parseTerm();
        cout << "MULT" << endl;
        return;
    default:
        return;
    }
}

void Parser::parseFactor()
{
    switch(token.getCode())
    {
    case INT:
        cout << "PUSH " << token.getLexeme() << endl;
        token = lexer->nextToken();
        return;
    case ID:
        cout << "PUSH " << token.getLexeme() << endl;
        token = lexer->nextToken();
        return;
    case LPAREN:
        token = lexer->nextToken();
        parseExpr();
        expect(RPAREN, "Syntax error!");
        token = lexer->nextToken();
        break;
    default:
        error("Syntax error!");
        return;
    }
}

void Parser::expect(TokenCode expectation, string msg)
{
    if(token.getCode() != expectation)
    {
        error(msg);
    }
}

void Parser::error(string msg)
{
    cout << msg << endl;
    throw;
}
