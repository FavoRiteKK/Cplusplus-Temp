#include <iostream>
#include <stack>
using namespace std;

int prio(char *c)
{
	switch (*c)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '\\':
			return 2;
		case '(':
			return 0;
	}
}

void convert(char *s, char* d)
{
	stack <char> oper;
	int pos = 0;
	char getit;
	
	while (*s)
	{
		if (isdigit(*s))
		{
			while (isdigit(*s))
				d[pos++] = *s++;
			d[pos++] = ' ';
		}
		if (!*s)
			break;
			switch (*s)
			{
				case '(':
					oper.push(*s);
					break;
				case ')':
					do
					{
						getit = oper.top();
						oper.pop();
						if (getit != '(')
						{
							d[pos++] = getit;
							d[pos++] = ' ';
						}
					}while (!oper.empty() && getit != '(');
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '\\':
					while (!oper.empty() && prio(s) <= prio(&oper.top()))
					{
						getit = oper.top();
						oper.pop();
						d[pos++] = getit;
						d[pos++] = ' ';
					}
					oper.push(*s);
					break;
			}

		++s;
	}
	
	while (!oper.empty())
	{
		d[pos++] = oper.top();
		d[pos++] = ' ';
		oper.pop();
	}
	d[pos] = '\0';
}

int main()
{
	char *infix = new char[20];
	char *postfix = new char[20];
	
	cout << "Formula: ";
	cin.getline(infix, 20, '\n');
	convert(infix, postfix);
	
	cout << postfix;
	
	delete []infix;
	delete []postfix;
	return 0;
}
