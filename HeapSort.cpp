#include <iostream>
#include <algorithm>
#include "TreeVector.cpp"
using namespace std;

void BUILD(int* a, int index, int n_elem)
{
	int val = a[index];
	int jndex = index*2+1;
	while (jndex < n_elem)
	{
		if (jndex+1 < n_elem && a[jndex] < a[jndex+1])
			jndex++;
		if (val >= a[jndex])
			return ;
		a[ (jndex-1)/2 ] = a[jndex];
		a[jndex] = val;
		jndex = jndex*2+1;
	}
}

void show(int* a, int n_elem)
{
	cout.put('\n');
	for (register int index = 0; index < n_elem; ++index)
		cout << a[index] << ' ';
}

void H_Sort(int *a, int n_elem)
{
	register int index;
	for (index = 4; index >= 0; --index)
		BUILD(a, index, 10);
//	show(a, 10);
	graph_tree(a, 0, 9);
	//Sap xep
	for (index = n_elem - 1; index > 0; --index)
	{
		a[0] ^= a[index];
		a[index] ^= a[0];
		a[0] ^= a[index];
		BUILD(a, 0, index);
//		show(a, 10);
		graph_tree(a, 0, 9);
	}
}

int main()
{
	InitTrGr();
	int a[] = {4, 10, 9, 7, 8, 6, 1, 3, 5, 2};
	graph_tree(a, 0, 9);
	H_Sort(a, 10);
	return 0;
}
