#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int getdir (string dir, vector<string> &files, string crit)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
    	if (strstr(dirp->d_name, crit.c_str()) != NULL)
        {
        	files.push_back(string(dirp->d_name));
        }
    }

    closedir(dp);

    if (files.size() == 0)
    	return 11;

    return 0;
}

int BuilBatch(vector<string> &files, string dir, string newname)
{
	int ID = 0;
	char BuildPath[dir.length()+12];
	
	strcpy(BuildPath, dir.data());
	strcat(BuildPath, "\\build.bat");
	
	ofstream opf;
	opf.open(BuildPath);
	if (!opf)
		return 0;
		
	vector<string>::iterator iter = files.begin();

	for ( ; iter != files.end(); ++iter)
		opf << "rename " << '\"' << *iter << '\"'
			<< ' ' << '\"' << newname << '_' << ID++ << ".jpg\"" << endl;

	return 1;
}

int main(int argc, char *argv[])
{
    string dir = string("");
    string newname = string("");
    string criteria = string("");
    vector<string> files = vector<string>();

    if (argc == 3 || argc == 4) {
    	dir.assign(argv[1]);
    	newname.assign(argv[2]);
    	if (argc == 4)
    		criteria.assign(argv[3]);
    }
    else {
		cout << "\nUsage: Rener [path]directory newname [criteria]"
			<< "\ncriteria is part(s) of source file(s)";
		return 0;
    }

   	if (getdir(dir, files, criteria) != 0) {
	   	cout << "Error!";
	   	return 0;
   	}

	sort(files.begin(), files.end());

   	if (BuilBatch(files, dir, newname) != 1)
   		cout << "\nError build batch file!";

    return 0;
}
