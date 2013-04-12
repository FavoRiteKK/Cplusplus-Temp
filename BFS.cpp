#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

const int GRAY = 1;
const int WHITE = 0;
const int BLACK = 2;

const int INF = -1;
const int NUL = 0;

int d[20], par[20], col[20];
int a[20][20];

int s, f, n;

void BFS()
{
//All vertexs belong to Graph
	int u, v;
	for (u = 1; u <= n; ++u)
	{
		col[u] = WHITE;
		d[u] = -1;
		par[u] = NUL;
	}
//Except s
	col[s] = GRAY;
	d[s] = 0;
//Start BFS
	queue <int> MyQ;
	MyQ.push(s);
	while ( !MyQ.empty() )
	{
		u = MyQ.front();	MyQ.pop();
		for (v = 1; v <= n; ++v)
			if (a[u][v] == 100 && col[v] == WHITE)
			{
				col[v] = GRAY;
				d[v] = 1 + d[u];
				par[v] = u;
				MyQ.push(v);
			}
		col[u] = BLACK;
	}
}

int main()
{
	istringstream iss("8 1 5 1 2 1 3 2 3 2 4 3 5 4 6 7 8");
	n = 8;
	int u, v;
	iss >> n >> s >> f;
	while (iss >> u >> v)
		a[u][v] = 100;

	BFS();
	
	cout << "Cost: " << d[f] << '\n';
	for ( ; ; )
	{
		cout << f << "<-";
		f = par[f];
		if (f == NUL)
			break;
	}
	return 0;
}
