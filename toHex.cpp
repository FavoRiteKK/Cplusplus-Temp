#include <iostream>
#include <fstream>
#include <iomanip>

std::ifstream ipf;
std::ofstream opf;

void handler()
{
	opf.setf(std::ios::hex, std::ios::basefield);
	opf.fill('0');
	
	char c = ' ';
	int period = 0;

	while (!ipf.eof())
	{
		ipf.get(c);
		if (!ipf.eof())
			opf << std::setw(2) << (short)(unsigned char)c;
		++period;

		if (period == 8)
			opf << '\t';
		else if (period == 16)
		{
			opf << '\n';
			period = 0;
		}
		else opf << ' ';
			
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
		
	ipf.open(argv[1], std::ios::binary);
	if (!ipf)
		return 1;
		
	opf.open("r.txt");
	if (!opf)
		return 1;
		
	handler();
//	char c = 0x90;
//	std::cout.setf(std::ios::hex, std::ios::basefield);
//	std::cout.fill('0');
//	std::cout << std::setw(2) << (short)(unsigned char)c;
//
	return 0;
}
