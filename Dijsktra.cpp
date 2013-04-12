#include <iostream>
using namespace std;
#define NUM 6
int main()
{
	int d[NUM], tr[NUM], st[NUM];
	int c[NUM][NUM] = {
		{9999, 1, 9999, 9999, 9999, 20},
		{9999, 9999, 2, 9999, 9999, 9999},
		{9999, 9999, 9999, 20, 9999, 3},
		{9999, 9999, 9999, 9999, 9999, 9999},
		{9999, 9999, 9999, 5, 9999, 9999},
		{9999, 9999, 9999, 9999, 4, 9999}
	};
	
	register int u, v, i, j;
	for (i = 0; i < NUM; ++i)
	{
		d[i] = c[0][i];
		tr[i] = -1;
		st[i] = 0;
	}
	//Rieng dinh 1 da co trong stack
	st[0] = 1;
	
	int n = NUM;
	while (n--)
	{
		//Tim dinh u co trong so nho nhat ma di duoc tu i
		int min = 9999;
		for (j = 0; j < NUM; ++j)
			if (st[j] == 0 && d[j] < min)
			{
				min = d[j];
				u = j;
			}
		
		//Nap u vao satck
		st[u] = 1;
		
		for (v = 0; v < NUM; ++v)
			if (st[v] == 0 && d[u] + c[u][v] < d[v])
			{
				d[v] = d[u] + c[u][v];
				tr[v] = u;
			}
	}
	
	if (d[3] == 9999)
		cout << "No paths!";
	else {
		u = 0;
		while (u != 3)
		{
			cout << u+1 << "->";
			u = tr[u];
		}
	}
	return 0;
}