#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int x=0;
	char nam[] = "khongbiet_dau";
	char res[40];
	int i, j;
	i=j=0;
	do {
		cin >> hex >> x;
		res[i] = nam[j]^x;
		i++;
		j = (j+1)%13;
	}while (x != -1);
	res[i]='\0';
	cout << res;
	return 0;
}
