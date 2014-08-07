#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n = 0;
	cout << "How many cases in switch? ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cout << "case " << i << ":\treturn sh->SetMyBoard(my_map_" << i << ");\n";
	system("pause");
	return 0;
}