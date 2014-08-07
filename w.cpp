
#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <cassert>
#include <cstdlib>

#include "init.h"
#include "my.h"

using std::cout;
using std::wcout;
using std::cin;
using std::wcin;
using std::string;
using std::wstring;
using std::ifstream;
using std::ofstream;
using std::wofstream;
using std::ios;
using std::hex;
using std::wcstombs;

/* Tra ve so nho nhat r = 2^n thoa man r >= x
Vi du: 	x = 31 => r = 32 = 2^5
		x = 33 => r = 64 = 2^5 */

int roundUpPower2(int x) {
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >>16);
    return x + 1;
}

class Object
{
protected:
	int x, y;
	virtual void collide(int x, int y, int w, int h)
	{
		cout << "Base rect\n";
	}
	
	virtual void collide(int x, int y, int rad)
	{
		cout << "Base cir\n";
	}
	
public:	
	virtual void collide(Object *o) = 0;
};

class Rect : public Object
{
	int w, h;
		
public:
	void collide(int x, int y, int rad)
	{
		cout << "Rect cir\n";
	}
	
	void collide(Object *o)
	{
		o->collide(x, y, w, h);
	}
};

class Circle : public Object
{
	int r;
	
public:
	void collide(int x, int y, int w, int h)
	{
		cout << "Circle rect\n";
	}
	
	void collide(Object *o)
	{
		o->collide(x, y, r);
	}
};

class Util
{
public:
	void func(Object *a, Object *b)
	{
		a->collide(b);
	}

};

int main(int argc, char **argv)
{
	Util u;
	Object *a = new Rect();
	Object *b = new Circle();
	u.func(a, b);
	u.func(b, a);
	u.func(b, b);
	
	system("pause");
	return 0;
}

