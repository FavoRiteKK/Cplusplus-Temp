#include <iostream>
using std::cout;
using std::fill;
using std::endl;
int *A, n;
void InitTrGr()
{
	A = new int[20];
	fill(A, A+20, 0);
	n = 1;
}

void graph_tree(int *tree, int at, int last)
{
	for (unsigned i = 1; i < n-1; ++i)
	{
		if (A[i])
			cout << char(-77);	//	for |
		else cout << ' ';
	
		cout << "   ";
	}
	
	if (n > 1)
	{	
		if (at%2 && at+1 <= last)		//Neu co Nibble
			cout << "ÃÄÄÄ" << tree[at] << endl;	//for |----
		else cout << "ÀÄÄÄ" << tree[at] << endl;	//for '----
	}
	else cout << tree[at] << endl;
	
	if ( (at*2+1 <= last) && (at%2 && at+1 <= last) )	//Neu co Child va co Nibble
	{
		A[n-1] = 1;
		++n;
		graph_tree(tree, at*2+1, last);		//Xet Child
		--n;
		A[n-1] = 0;
		graph_tree(tree, at+1, last);		//Xet Nibble
	}
	else if ( (at*2+1 <= last) )	//Co Child nhung ko co Nibble
	{
		++n;
		graph_tree(tree, at*2+1, last);		//Xet Child
		--n;
	}
	else if ( (at%2 && at+1 <= last) )	//Ko Child nhung co Nibble
		graph_tree(tree, at+1, last);
	else return;		
}
