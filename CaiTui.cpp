#include <iostream>
#include <fstream>
using namespace std;

int n = 0, m = 0;
int* w, *v;
int **f;

void enter()
{
	int i;
	ifstream ipf;
	ipf.open("test.txt");
	ipf >> n >> m;
	w = new int[n+1];
	v = new int[n+1];
	f = new int*[n+1];
	
	for (i = 0; i != n+1; ++i)
		f[i] = new int[m+1];
	
	for (i = 1; i != n+1; ++i)
		ipf >> w[i] >> v[i];
	ipf.close();
}

void Opti()
{
	int i, k;
	fill (f[0], f[0]+m+1, 0);
	for (i = 1; i != n+1; ++i)
		for (k = 0; k != m+1; ++k)
		{
			f[i][k] = f[i-1][k];
			if (k >= w[i] && f[i][k] < f[i-1][k-w[i]]+v[i])
				f[i][k] = f[i-1][k-w[i]]+v[i];
		}
}

void trace()
{
	cout << f[n][m] << endl;
	while (n)
	{
		if (f[n][m] != f[n-1][m])
		{
			m = m-w[n];
			cout << n << ' ';
		}
		--n;
	}
}

int main()
{
	enter();
	Opti();
	
	for (unsigned i = 0; i != n+1; ++i)
	{
		for (unsigned k = 0; k != m+1; ++k)
		{
			cout << f[i][k];
			cout.width(3);
		}
		cout << '\n';
	}
	
	trace();
	return 0;
}
