
#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <cassert>
#include <cstdlib>

using std::cout;
using std::wcout;
using std::cin;
using std::wcin;
using std::string;
using std::wstring;
using std::ifstream;
using std::ofstream;
using std::wofstream;
using std::ios;
using std::hex;
using std::wcstombs;

/* Tra ve so nho nhat r = 2^n thoa man r >= x
Vi du: 	x = 31 => r = 32 = 2^5
		x = 33 => r = 64 = 2^5 */

int roundUpPower2(int x) {
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >>16);
    return x + 1;
}

int main(int argc, char **argv)
{
	int **p = new int*[8];
	return 0;
}

