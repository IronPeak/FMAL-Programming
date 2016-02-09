#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum TokenCode {ID, ASSIGN, SEMICOL, INT, ADD, SUB,
				MULT, LPAREN, RPAREN, PRINT, END, ERROR};

class Token
{
	public:
		Token()
		{
			lexeme = "";
			code = ERROR;
		}
		Token(string l, TokenCode c)
		{
			lexeme = l;
			code = c;
		}

		string getLexeme() const
		{
			return lexeme;
		}

		TokenCode getCode() const
		{
			return code;
		}

	private:
		string lexeme;
		TokenCode code;
};

#endif // TOKEN_H
