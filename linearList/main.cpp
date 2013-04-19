#include <iostream>
#include "include//LinkList.h"
using namespace std;

int main()
{
    LinkList *L = new LinkList;

    L->InsertElem(1,10);
    L->InsertElem(2,25);
    L->InsertElem(2,35);
    L->InsertElem(4,45);
    DataType e=0;
    L->DeleteElem(1,e);
    L->PrintList();
    cout<<"Delete element:"<<e<<endl;

    L->CreateListHead(7);
    L->PrintList();
    L->CreateListTail(7);
    L->PrintList();
    L->DeleteList();
    L->PrintList();



    return 0;
}
