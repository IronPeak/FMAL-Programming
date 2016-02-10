#include <iostream>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

int getValue(map<string, int>& variables, string var);
bool isInt(const string& str);
bool isID(const string& str);
int toInt(const string& str);
string toString(int n);
bool isNumber(char c);
bool isLetter(char c);

int main()
{
    map<string, int> variables;
    stack<string> thestack;

	string cmd;
    while(cin >> cmd)
	{
		if(cmd == "PUSH")
		{
			string var;
			cin >> var;
			if(isInt(var) || isID(var))
			{
				thestack.push(var);
			}
			else
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
		}
		else if(cmd == "ADD")
		{
			if(thestack.size() < 2)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
			string var1 = thestack.top();
			thestack.pop();
			string var2 = thestack.top();
			thestack.pop();
			try
			{
				int n1 = getValue(variables, var1);
				int n2 = getValue(variables, var2);
				thestack.push(toString(n2 + n1));
			}
			catch(...)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
		}
		else if(cmd == "SUB")
		{
			if(thestack.size() < 2)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
			string var1 = thestack.top();
			thestack.pop();
			string var2 = thestack.top();
			thestack.pop();
			try
			{
				int n1 = getValue(variables, var1);
				int n2 = getValue(variables, var2);
				thestack.push(toString(n2 - n1));
			}
			catch(...)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
		}
		else if(cmd == "MULT")
		{
			if(thestack.size() < 2)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
			string var1 = thestack.top();
			thestack.pop();
			string var2 = thestack.top();
			thestack.pop();
			try
			{
				int n1 = getValue(variables, var1);
				int n2 = getValue(variables, var2);
				thestack.push(toString(n2 * n1));
			}
			catch(...)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
		}
		else if(cmd == "ASSIGN")
		{
			if(thestack.size() < 2)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
			string src = thestack.top();
			thestack.pop();
			string dst = thestack.top();
			thestack.pop();
			if(isID(dst))
			{
				variables[dst] = getValue(variables, src);
			}
			else
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
		}
		else if(cmd == "PRINT")
		{
			if(thestack.size() < 1)
			{
				cout << "Error for operator: " << cmd << endl;
				return 0;
			}
			string var1 = thestack.top();
			thestack.pop();
			if(variables.count(var1) == 1)
			{
				cout << variables[var1] << endl;
			}
			else
			{
				cout << "Error" << endl;
				return 0;
			}
		}
		else if(cmd == "")
		{

		}
		else
		{
			cout << "Error for operator: " << cmd << endl;
			return 0;
		}
	}
    return 0;
}

int getValue(map<string, int>& variables, string var)
{
	if(isInt(var))
	{
		return toInt(var);
	}
	if(variables.count(var) == 1)
	{
		return variables[var];
	}
	//if var is not a number or a variable we've encountered an error
	throw;
}

bool isInt(const string& str)
{
	if(str.length() == 0)
	{
		return false;
	}
	if(str[0] != '-' && !isNumber(str[0]))
	{
		return false;
	}
	for(unsigned int i = 1; i < str.length(); i++)
	{
		if(isNumber(str[i]) == false)
		{
			return false;
		}
	}
	return true;
}

bool isID(const string& str)
{
	if(str.length() == 0)
	{
		return false;
	}
	for(unsigned int i = 0; i < str.length(); i++)
	{
		if(isLetter(str[i]) == false)
		{
			return false;
		}
	}
	return true;
}

int toInt(const string& str)
{
	istringstream buffer(str);
	int value;
	buffer >> value;
	return value;
}

string toString(int n)
{
	stringstream buffer;
	buffer << n;
	return buffer.str();
}

bool isNumber(char c)
{
    return '0' <= c && c <= '9';
}

bool isLetter(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
