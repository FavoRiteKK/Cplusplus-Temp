#include <iostream>
using namespace std;
int main()
{
	char s[1000];
	while (true)
	{
		cin.getline(s, 100);
		cout << "\nI read: " << s;
	}
	return 0;
}
