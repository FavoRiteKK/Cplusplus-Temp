#include <iostream>
#include <sstream>
using namespace std;

void Evaluate(string *sub)
{
	int loc, f1, f2, len;
	loc = f1 = f2 = 0;
	int i = 0, k = 0;
	double sotrai, sophai, num;
	
	ostringstream oss;
	
	char tok[] = "*\\/+-";
	
	for (i = 0; tok[i]; ++i)
	{
		len = sub->size();
		
		sotrai = sophai = 0;
		loc = sub->find(tok[i], 0);
		
		if (loc != string::npos)
		{
			i = 0;
			
			f1 = loc-1;
			f2 = loc+1;
			k = 1;
			
			if (f1 == -1)
				return;
			
			while (f1 >= 0 && isdigit(sub->at(f1)) )
			{
				sotrai = sotrai + k*(sub->at(f1)-'0');
				k*=10;
				--f1;
			}
			while ( f2 < len && isdigit(sub->at(f2)))
			{
				sophai = sophai*10 + sub->at(f2) - '0';
				++f2;
			}
			switch (sub->at(loc))
			{
				case '*':	num = sotrai*sophai;	break;
				case '/':
				case '\\':	num = sotrai/sophai;	break;
				case '+':	num = sotrai+sophai;	break;
				case '-':	num = sotrai-sophai;	break;
			}
			oss << num;
			sub->replace(f1+1, f2-f1-1, oss.str());
		}
	}
}

double Parse(string *s)
{
	int f1 = 0, f2 = 0;
	int len = 0;
	
	string sub;
	while ( f2 = s->find(')', 0) )
	{
		if (f2 != string::npos)
		{
			f1 = f2;
			while ( s->at(f1) != '(' )
				--f1;
			
			if (f1 < f2 && f1 >= 0)
			{
				len = f2-f1;
				sub.assign(*s, f1+1, len-1);
				cout << sub << endl;
				Evaluate(&sub);
				s->replace(f1, len+1, sub);
			}
		}
		else break;
	}
	Evaluate(s);
	cout << *s;
	return 0;
}

int main()
{
	string fml;
	char s[81];
	cout << "Enter formula: ";	cin.getline(s, 80, '\n');
	fml.assign(s);
	Parse(&fml);
	return 0;
}
