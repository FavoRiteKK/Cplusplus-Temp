#include <iostream>
using namespace std;

int *A = 0, n;

int Duyet(int at, int *arr, int last, int level)
{
	if (at > last)	return 0;

	Duyet(at*2+1, arr, last, level+1);
	//Xu ly
	for (register int sp = 0; sp < level; ++sp)
		cout << "      ";

	if (at == 0)	cout << arr[0] << "ÄÄÄÄ" << (char)0xb4 << '\n';
	else if (at%2 && at*2+1 <= last)	cout << (char)0xda << arr[at] << "ÄÄÄ" << (char)0xb4 << '\n';
	else if (at%2)	cout << (char)0xda << arr[at] << '\n';
	else if ( !(at%2) && at*2+1 <= last )	cout << (char)0xc0 << arr[at] << "ÄÄÄ" << (char)0xb4 << '\n';
	else if ( !(at%2) )	cout << (char)0xc0 << arr[at] << '\n';
	else return 0;
	
	Duyet(at*2+2, arr, last, level+1);
}

int main()
{
	int a[15] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	Duyet(0, a, 14, 0);
	return 0;
}
