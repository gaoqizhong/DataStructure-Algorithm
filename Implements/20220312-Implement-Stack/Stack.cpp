#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() : LinkList()
{
    // call LinkList::LinkList()
}
Stack::Stack(DataType ar[], int n)
{
    // create a temp point to first Node
    Node *ptemp = new Node; 
    ptemp->data = ar[n-1];
    ptemp->next = NULL;
    // create the head point to temp
    head = new Node;
    head->data = n;
    head->next = ptemp;
    // add all Node
    for (int i = n - 2; i >= 0; i--)
    {
		Node *pnew = new Node;
        pnew->data = ar[i];
        pnew->next = NULL;
        ptemp->next = pnew;
        ptemp = pnew;
    }
    ptemp->next = NULL;
    // create the tail point to last Node
    tail = new Node;
    tail->data = 0;
    tail->next = ptemp;
}
Stack::~Stack()
{
    // do nothing
}
bool Stack::push(const DataType &d)
{
    // call LinkList::insert(DataType d1, int location)
    LinkList::insert(d, 0);
    return true;
}
bool Stack::pop(DataType &d)
{
    // call bool LinkList::remove(int location, DataType &d1)
    return LinkList::remove(1, d);
}