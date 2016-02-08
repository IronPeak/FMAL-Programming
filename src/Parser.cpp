#include "Parser.h"

Parser::Parser(Lexer* lexer)
{
    this->lexer = lexer;
}

Parser::~Parser()
{
    delete lexer;
}

void Parser::parse()
{
    tCode = lexer->nextToken();
    parseStatement();
}

void Parser::parseStatement()
{
    switch(tCode)
    {
    case ERROR:
        return;
    case END:
        return;
    case ID:
        cout << "PUSH " << lexer->lastLexeme() << endl;
        tCode = lexer->nextToken();
        expect(ASSIGN);
        tCode = lexer->nextToken();
        parseExpr();
        cout << "ASSIGN" << endl;
        break;
    case PRINT:
        tCode = lexer->nextToken();
        expect(ID);
        cout << "PUSH " << lexer->lastLexeme() << endl;
        break;
    default:
        cout << "ERROR" << endl;
        return;
    }
    tCode = lexer->nextToken();
    expect(SEMICOL);
    tCode = lexer->nextToken();
    parseStatement();
}

void Parser::parseExpr()
{
    parseTerm();
    tCode = lexer->nextToken();
    switch(tCode)
    {
    case ADD:
        tCode = lexer->nextToken();
        parseExpr();
        cout << "ADD" << endl;
        break;
    case SUB:
        tCode = lexer->nextToken();
        parseExpr();
        cout << "SUB" << endl;
        break;
    default:
        cout << "ERROR" << endl;
        return;
    }
}

void Parser::parseTerm()
{
    parseFactor();
    tCode = lexer->nextToken();
    switch(tCode)
    {
    case MULT:
        tCode = lexer->nextToken();
        parseTerm();
        cout << "MULT" << endl;
        return;
    default:
        return;
    }
}

void Parser::parseFactor()
{
    switch(tCode)
    {
    case INT:
        cout << "PUSH " << lexer->lastLexeme() << endl;
        tCode = lexer->nextToken();
        return;
    case ID:
        cout << "PUSH " << lexer->lastLexeme() << endl;
        tCode = lexer->nextToken();
        return;
    case LPAREN:
        tCode = lexer->nextToken();
        parseExpr();
        expect(RPAREN);
        break;
    default:
        cout << "ERROR" << endl;
        return;
    }
}

void Parser::expect(TokenCode expectation)
{
    if(tCode != expectation)
    {
        cout << "ERROR" << endl;
        throw;
    }
}
