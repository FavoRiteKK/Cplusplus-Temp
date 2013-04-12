#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class C
{
	public:
	int x;
	char ten[20];
	C(int __x = 1, char* __ten = "UNNAMED"):x(__x)
	{
		strcpy(ten, __ten);
	}
	friend ostream& operator<< (ostream& os, const C& obj);
	friend istream& operator>> (istream& is, C& obj)
	{
		cout << "\nTen & Tuoi: ";
		cin >> obj.ten >> obj.x;
		return is;
	}
};

ostream& operator<<(ostream& os, const C& obj)
{
	os << obj.x << ' ' << obj.ten << endl;
	return os;
}

void ReadF()
{
	ifstream fi("test.txt");
	if (!fi)
		return;
	C objr;
	while (!fi.eof())
	{
//		cout << fi.tellg() << '\n';
		fi.read((char*)(&objr), sizeof(objr));
		if (!fi.eof())
			cout << objr;
	}
	fi.close();
}

void WriteF()
{
	ofstream fo("test.txt",ios::app);
	fo.seekp(0,ios::end);
	cout << fo.tellp() << '\n';
	C objc;
	cin >> objc;
	fo.write((const char*)(&objc), sizeof(objc));
	fo.close();
}

int main()
{
	char choice = '0';
	do {
		cout << "\nMenu 1: Enter to write\nMenu 2: Read to see";
		cout << "\nYour choice: ";
		cin >> choice;
		switch (choice)
		{
			case '1':
				WriteF();
				break;
			case '2':
				ReadF();
				break;
			default:
				break;
		}
	} while (choice != '0');

	return 0;
}
