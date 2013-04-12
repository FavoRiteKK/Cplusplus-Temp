
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

void shout(const char *data)
{
	cout << sizeof(*data) << ": ";
	
	while (*data)
	{
		int ch = *data;
		cout << hex << ch << ", ";
		data++;
	}
	
	cout << '\n';
}

void shout(const wchar_t *data)
{
	cout << sizeof(*data) << ": ";
	while (*data)
	{
		int hi = (*data & 0xFF00) >> 8;
		int lo = (*data & 0x00FF);
		cout << hex << hi << " - " << lo << ", ";
		data++;
	}
	
	cout << '\n';
}

int main(int argc, char **argv)
{
	wstring s = L"bái";
	string sub = "bai";

	cout << "wstring: ";
	shout(s.c_str());
	
	cout << "string: ";
	shout(sub.c_str());
	
	cout << "wstring converted: ";
	char *des = new char[10];
	wcstombs(des, s.c_str(), 10);
	shout(des);
	
	// unsigned int loc = s.find(sub);
	// if (loc != string::npos)
		// cout << "Found at " << loc << '\n';
	// else cout << "! Found\n";
	
	return 0;
}

