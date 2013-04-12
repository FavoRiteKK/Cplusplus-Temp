#include "Mapobj.h"
#include <iostream>
using namespace std;
Portal::Portal(int a, int b, int c, int d)
{
    atx = a;
    aty = b;
    tox = c;
    toy = d;
}
void Portal::Display()
{
    cout << "\n\tI'm a Portal from (" << atx << ", " << aty << ") to ("
         << tox << ", " << toy << ")...";
}

Chest::Chest(int a, int b, char *p)
{
    atx = a;
    aty = b;
    strcpy(item, p);
}

void Chest:: Display()
{
    cout << "\n\tI'm a Chest from (" << atx << ", " << aty << ") holding "
         << item;
}


OBJ_LIST::OBJ_LIST(): head(0) {}
void OBJ_LIST:: Show()
{
    if (head == 0)
        return;
    node* p = head;
    while (p != 0)
    {
        p->obj->Display();
        p = p->next;
    }
}
void OBJ_LIST:: Add(OBJECT* ob)
{
    node *p = new node;
    p->obj = ob;
    p->next = 0;
    if (head == 0)
        head = p;
    else
    {
        node *q = head;
        while (q->next != 0)
            q = q->next;
        q->next = p;
    }
}

MapObj::MapObj(int a, OBJ_LIST* p)
{
    level = a;
    obj_list = p;
}
void MapObj:: InnerObj()
{
    if (obj_list == 0)
    {
        cout << "\n\nThis map level " << level << " contains nothing.";
        return;
    }
    cout << "\n\nThis map level " << level << " contains: ";
    obj_list->Show();
}
