#include <iostream>
#include <iterator>
using namespace std;
#define n 11
template <typename Ty>
void ouscr(Ty FI, Ty LA)
{
	while (FI != LA)
		cout << *FI++ << ' ';
}

template <typename Ty>
void ouscrln(Ty FI, Ty LA)
{
	cout << endl;
	while (FI != LA)
		cout << *FI++ << ' ';
	cout << endl;
}

using namespace std;
int main()
{
	const int a[] = {0, 5, 2, 3, 4, 9, 10, 5, 6, 7, 8};
	int *max_at_index = new int[n];
	int *track = new int[n];
	
	int i, k, to_track;
	
	fill(max_at_index, max_at_index+n, 0);
	copy(max_at_index, max_at_index+n, track);

	for (i = 1; i < n; ++i)
	{
//		cout << "Trong xau con: "; ouscrln(a+1, a+i+1);
		for (k = 0; k < i; ++k)
		{
			if (a[k] <= a[i] && max_at_index[k]+1 > max_at_index[i])
			{
				max_at_index[i] = max_at_index[k]+1;
				to_track = k;
			}
		}
		track[to_track] = i;
		track[i] = n;
//		cout << "\tDo dai lon nhat hien tai: " << max_at_index[i] << endl;
	}

	cout << "Ket qua: " << *max_element(max_at_index, max_at_index+n);
	cout << "\nDay con do la: ";
	
	i = 0;
	while (track[i] != n)
	{
		cout << a[ track[i] ] << ' ';
		i = track[i];
	}
	return 0;
}
