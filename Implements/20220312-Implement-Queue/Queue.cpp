#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue():LinkList()
{
    // call LinkList::LinkList()
}
Queue::Queue(DataType ar[],int n):LinkList(ar, n)
{
    // call LinkList::LinkList(DataType ar[], int n)
}
Queue::~Queue()
{
    // do nothing
}
bool Queue::enqueue(const DataType &d)
{
    // call LinkList::insert(DataType d1, int location)
    LinkList::insert(d, int(head->data) + 1);
    return true;
}
bool Queue::dequeue(DataType &d)
{
    // call bool LinkList::remove(int location, DataType &d1)
    return LinkList::remove(1, d);
}
