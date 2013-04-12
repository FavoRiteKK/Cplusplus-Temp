#include <stdafx.h>
#include <iostream>
#include <fstream>
#include "MAPobj.h"
#include "MAPobj.cpp"

using namespace std;

int main()
{
	OBJ_LIST *ol = new OBJ_LIST();
	ol->Add(new Chest(20, 40, "Potion"));
	MapObj *m = new MapObj(2, ol);
	m->InnerObj();

	ofstream fo("t.txt");
	fo.write((const char*)m, sizeof(*m));
	fo.close();

    MapObj map1(0,0);
    ifstream fi("t.txt");
    if (!fi)
    	return 0;
    fi.read((char*)(&map1), sizeof(map1));	//Use sizeof(object). not sizeof(pointer)
    									//because we need full object
    fi.close();
    map1.InnerObj();
    return 0;
}
