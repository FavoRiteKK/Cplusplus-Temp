#include <iostream>
#include <list>
using namespace std;

class A
{
protected:
	int att;
	virtual void func() = 0;
	A(int _att = 0): att(_att) {}
public:
	void callFunc()
	{
		this->func();
	}
};

class B: public A
{
	
public:
	B(int _att): A(_att) {}
	void func()
	{
		cout << att << '\n';
	}
};

int main()
{
	list <A*> A_Holder;
	B m(7), n(8), p(9);
	A_Holder.push_front(&m);
	A_Holder.push_front(&n);
	A_Holder.push_front(&p);

	list <A*>::iterator it = A_Holder.begin();
//	for ( ; it != A_Holder.end(); ++it)
//		(*it)->callFunc();
	A_Holder.remove(&n);

	for ( ; it != A_Holder.end(); ++it)
		(*it)->callFunc();
	return 0;
}
