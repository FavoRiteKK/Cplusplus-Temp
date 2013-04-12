#include <iostream>
#include <fstream>
using namespace std;

void CvTxt2Html(char* s)
{
	ifstream ipf(s);
	if (!ipf)
	{
		cout << "\nFile not exist";
		return;
	}
	
	char *pts = (char*)memchr(s, '.', strlen(s));
	if (pts != 0)
		s[pts - s] = '\0';

	char c = 0;
	strcat(s, ".htm");
	ofstream opf(s);
	
	string firspart = "<html>\n\t<head>\n\t\t<title>CvTxt2Html</title>\n\t</head>";
	firspart += "\n\t<body>\n\t\t<p>\n";
	
	string secondpart = "\n\t\t</p>\n\t</body>\n</html>";
	
	opf << firspart;
	while (ipf.get(c))
	{
		if (c == 13 || c == '\n')	//LF - LineFeed or
			opf << "<br />\n";
		else if (c == '\t')
			opf << "&#160&#160&#160&#160&#160&#160";	//1 tab in html = 6 Spaces
		else if (!ipf.eof())
			opf << c;
	}
	opf << secondpart;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "\nUsage: CvTxt2Html <filename>";
		return 0;
	}
	
	CvTxt2Html(argv[1]);
	return 0;
}
