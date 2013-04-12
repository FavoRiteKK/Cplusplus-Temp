#include <iostream>
using namespace std;

void quickSort(int Lo, int Hi, int *a)
{
	if (Lo >= Hi)
		return;
	int med = (Lo+Hi)/2;
	int key = a[med];
	
	int i = Lo, j = Hi;
	
	while (i <= j)
	{
		while (a[i] > key) ++i;
		while (a[j] < key) --j;
		
		if (i <= j)
		{
			if (i < j)
			{
				a[i] ^= a[j];
				a[j] ^= a[i];
				a[i] ^= a[j];
				
				for (int i = 0; i < 8; ++i)
					cout << a[i] << ' ';
				cout << '\n';
			}
			++i;
			--j;
		}
	}
		
	if (Lo < j)
		quickSort(Lo, j, a);
	if (i < Hi)
		quickSort(i, Hi, a);
}

int main()
{
	int a[] = {1,2,4,5,6,8,12,15};
	quickSort(0, 7, a);

	return 0;
}