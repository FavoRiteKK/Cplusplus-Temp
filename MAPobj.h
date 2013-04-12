#ifndef _MAPobj_H
#define _MAPobj_H
class OBJECT
{
public:
    virtual void Display() = 0;
};

class Portal: public OBJECT
{
    int atx, aty;
    int tox, toy;
public:
    Portal(int a = 0, int b = 0, int c = 0, int d = 0);
    void Display();
};

class Chest: public OBJECT
{
    int atx, aty;
    char item[20];
public:
    Chest(int a = 0, int b = 0, char *p = "Unknown");
    void Display();
};

struct node
{
    OBJECT *obj;
    node* next;
};

class OBJ_LIST
{
    node *head;
public:
    OBJ_LIST();
    void Show();
    void Add(OBJECT* ob);
};

class MapObj
{
    int level;
    OBJ_LIST *obj_list;
public:
    MapObj(int a, OBJ_LIST* p);
    void InnerObj();
};
#endif
