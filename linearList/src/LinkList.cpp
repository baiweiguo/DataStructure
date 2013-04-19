#include "..//include//LinkList.h"

LinkList::LinkList()
{
    next = NULL;

}

LinkList::~LinkList()
{

}

//获取第 i 个位置的元素，并存放于 e中
Status LinkList::GetElem(int i, DataType& e)
{
    //以下几行，获取第 i-1 个结点的地址（i不大于链表长度时）
    LinkList* p = this;//头结点指针（即头指针）
    int j = 1;
    while(p!=NULL && j<i)
    {
        p=p->next;
        j++;
    }

    //如果 i大于链表的长度：p到达链表尾
    if(p==NULL)
    {
        return ERROR;
    }

    e = (p->next)->data;
    return OK;
}

//在线性表位置 i 处插入值为e的结点
Status LinkList::InsertElem(int i, DataType e)
{
    LinkList* p = this;
    int j=1;
    while(p!=NULL && j<i)
    {
        p=p->next;
        j++;
    }

    LinkList* q = new LinkList;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

//删除线性表中的第 i个元素，将其元素的值存于e中
Status LinkList::DeleteElem(int i, DataType& e)
{
    LinkList* p=this;
    int j = 1;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }

    LinkList* q;
    q = p->next; //p 为第 i 个结点前一个结点的地址
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}


//打印链表
Status LinkList::PrintList()
{
    LinkList* p= this->next;
    while(p!=NULL)
    {
        std::cout<<p->data<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
    return OK;
}

//完整的创建一个n个结点的链表，创建方式为:首结点前加入元素的方式
Status LinkList::CreateListHead(int n)
{
    int i=0;
//    LinkList* p = this;
    srand((unsigned)time(NULL));
    for(i=0; i<n; i++)
    {
        LinkList* r = new LinkList;
        r->data = rand()%100 + 1;

        r->next = this->next;
        this->next = r;
    }
    return OK;
}

//完整的创建一个n个结点的链表，创建方式为：尾结点增加元素的方式
Status LinkList::CreateListTail(int n)
{
    int i=0;
    LinkList* p = this;
    for(i=0; i<n; i++)
    {
        LinkList* r = new LinkList;
        r->data = rand()%100 + 1;

        p->next = r;
        r->next = NULL;
        p=p->next;
    }
    return OK;
}

//删除整个链表
Status LinkList::DeleteList()
{
    LinkList* p = this->next;
    LinkList*q;
    while(p!=NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
    this->next = NULL;
}
