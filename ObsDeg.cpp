#include <iostream>
#include <list>
using namespace std;

class Subcriber;

class Subject
{
	public:
		virtual void AddSubcriber(Subcriber& sub) = 0;
		virtual void RemoveSubcriber(Subcriber& sub) = 0;
		virtual void NotifySubs(int& a, int& b) = 0;
};

class Subcriber
{
	protected:
		virtual void Display() = 0;
	public:
		virtual void Update(int& a, int &b) = 0;
};

class ThuDoND: public Subject
{
	public:
		void AddSubcriber(Subcriber& sub)
		{
			SubHolder.push_front(&sub);
		}
		void RemoveSubcriber(Subcriber& sub)
		{
			SubHolder.remove(&sub);
		}
		void NotifySubs(int& a, int& b)
		{
			list <Subcriber*>::const_iterator cit = SubHolder.begin();
			for ( ; cit != SubHolder.end(); ++cit)
				(*cit)->Update(a, b);
		}
		void setAB(int a, int b)
		{
			this->a = a;
			this->b = b;
			this->NotifySubs(a, b);
		}
	private:
		list <Subcriber*> SubHolder;
		int a, b;
};

class Household: public Subcriber
{
	public:
		Household(Subject *sub)
		{
			this->subject = sub;
			this->subject->AddSubcriber(*this);
			a = b = 0;
		}
	private:
		int a, b;
		Subject *subject;
		void Update(int&a, int& b)
		{
			this->a = a;
			this->b = b;
			this->Display();
		}
		void Display()
		{
			cout << "\n\ta = " << this->a << "\tb = " << this->b << '\n';
		}
};

int main()
{
	ThuDoND* tdnd = new ThuDoND();
	Household* hh = new Household(tdnd);
	tdnd->setAB(8, 9);
	tdnd->setAB(7,10);
	return 0;
}
