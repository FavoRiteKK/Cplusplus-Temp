#include <iostream>
#include "TreeGraph.cpp"

using namespace std;

template <typename Ty>
struct Node
{
	Ty info;
	Node *le, *ri;
} ;

typedef Node <int>* ITREE;

void BinTree(ITREE &tree, int& data);

void ParseTree(ITREE &tree, int* arr, unsigned pos);

int* GetArray(ITREE &tree);

void GetNecessary(ITREE &tree, unsigned level, unsigned &max);

void PreOrder(ITREE &tree)
{
	if (tree == NULL)
		return;
	cout << tree->info << ' ';
	PreOrder(tree->le);
	PreOrder(tree->ri);
}
//
int main()
{
	int a[] = {
		1, 4, 3, 9, 7, 5, 2, 8
	};
	
	ITREE Tree = NULL;
	
	for (unsigned i = 0; i < 8; ++i)
		BinTree(Tree, a[i]);

	unsigned last = 0;
	GetNecessary(Tree, 0, last);
	
	int *t = GetArray(Tree);
	
	Duyet(0, t, last, 0);
	return 0;
}
//
void BinTree(ITREE &tree, int &data)
{
	if (tree == NULL)
	{
		tree = new Node<int>;
		assert(tree != NULL);
		tree->info = data;
		tree->le = tree->ri = NULL;
		return;
	}
	
	if (tree->info == data)
		return;

	if (tree->info > data)
		BinTree(tree->le, data);
	else if (tree->info < data)
		BinTree(tree->ri, data);
	
	return;
}

int* GetArray(ITREE &tree)
{
	if (tree == NULL)
		return NULL;
	unsigned n = 0;
	GetNecessary (tree, 0, n);
	int *arr = new int[n];
	assert(arr != NULL);
	
	ParseTree (tree, arr, 0);
	return arr;
}

void GetNecessary(ITREE &tree, unsigned level, unsigned &max)
{
	if (tree == NULL)
		return;

	max = (level > max ? level : max);
	
	GetNecessary (tree->le, level*2+1, max);
	GetNecessary (tree->ri, level*2+2, max);

}

void ParseTree(ITREE &tree, int* arr, unsigned pos)
{
	if (tree == NULL)
	{
		arr[pos] = 0;
		return;
	}
	else arr[pos] = tree->info;
	
	ParseTree(tree->le, arr, pos*2 + 1);
	ParseTree(tree->ri, arr, pos*2 + 2);
}
