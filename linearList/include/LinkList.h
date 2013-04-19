#ifndef LINKLIST_H
#define LINKLIST_H

typedef int DataType ;
typedef int Status;
#define OK    1
#define ERROR 0

#include <stdlib.h>
#include <ctime>
#include <iostream>
//链表线性表类结点
class LinkList
{
public:
    LinkList();
    virtual ~LinkList();
    //获取第 i 个位置的元素，并存放于 e中
    Status GetElem(int i, DataType& e);

    //在线性表位置 i 处插入值为e的结点
    Status InsertElem(int i, DataType e);

    //删除线性表中的第 i个元素，将其元素的值存于e中
    Status DeleteElem(int i, DataType& e);

    //完整的创建一个n个结点的链表，创建方式为:首结点前加入元素的方式
    Status CreateListHead(int n);

    //完整的创建一个n个结点的链表，创建方式为：尾结点增加元素的方式
    Status CreateListTail(int n);

    //打印链表
    Status PrintList();

    //删除整个链表
    Status DeleteList();


private:
    DataType data;
    LinkList* next;
};

#endif // LINKLIST_H
