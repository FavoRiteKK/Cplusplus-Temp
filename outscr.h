#ifndef OUT_H
#define OUT_H
#include <iostream>
using namespace std;

template <typename Ty>
void outscr(Ty FI, Ty LA)
{
	while (FI != LA)
		cout << *FI++ << ' ';
}

template <typename Ty>
void outscrln(Ty FI, Ty LA)
{
	cout << endl;
	while (FI != LA)
		cout << *FI++ << ' ';
	cout << endl;
}
#endif
