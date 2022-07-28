#include <iostream>
#include "LinkList.h"
using namespace std;

LinkList::LinkList()
{
    // create the head
    head = new Node;
    head->data = 0;
    head->next = NULL;
    // create the tail
    tail = new Node;
    tail->data = 0;
    tail->next = NULL;
}
LinkList::LinkList(DataType ar[], int n)
{
    // create a temp point to first Node
    Node *ptemp = new Node; 
    ptemp->data = ar[0];
    ptemp->next = NULL;
    // create the head point to temp
    head = new Node;
    head->data = n;
    head->next = ptemp;
    // add all Node
    for (int i = 1; i < n; i++)
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
LinkList::~LinkList()
{
    delete head;
    delete tail;
}
bool LinkList::isempty() const
{
    if(head->data == 0)
        return true;
    else
        return false;
}
bool LinkList::display() const
{
    if(head->data == 0)
    {
        cout << "NULL";
        return false;
    }
    Node *ptemp = head->next;
    while(ptemp)
    {
        cout << ptemp->data << " -> ";
        ptemp = ptemp->next;
    }
    cout << "NULL " << "(the length is "<<head->data<<")";
    return true;
}
inline Node *LinkList::search(int location) const
{
    if (location == 0)
        return head;
    Node *ptemp = head->next;
    int n = 1;
    while(n != location)
    {
        ptemp = ptemp->next;
        n++;
    }
    return ptemp;
}
inline Node *LinkList::search(DataType value) const
{
    Node *ptemp = head->next;
    while (ptemp && ptemp->data != value)
        ptemp = ptemp->next;
    return ptemp;             // will return a *Node or NULL
}
bool LinkList::insert(DataType d1, DataType d2)
{
    if(search(d2) == NULL)
        return false;
    Node *pd2 = search(d2);
    Node *pnew = new Node;
    pnew->data = d1;
    pnew->next = pd2->next;
    pd2->next = pnew;
    // if pnew is the new tail, move tail
    if(pnew->next == NULL)
        tail->next = pnew;
    head->data++;
    return true;
}
bool LinkList::insert(DataType d1, int location)
{
    if(location < 0)
        return false;
    // first insertion
    if(location == 0)
    {
        Node *pnew = new Node;
        pnew->data = d1;
        pnew->next = head->next;
        head->next = pnew;
    }
    // middle insertion
    else if (location <= head->data)
    {
        Node *ploc = search(location);
        Node *pnew = new Node;
        pnew->data = d1;
        pnew->next = ploc->next;
        ploc->next = pnew;
    }
    // tail insertion
    else
    {
        Node *plast = search(int(head->data));
        Node *pnew = new Node;
        pnew->data = d1;
        pnew->next = NULL;
        plast->next = pnew;
        // pnew is the new tail, move tail
        tail->next = pnew;
    }
    head->data++;
    return true;
}
bool LinkList::remove(DataType d1)
{
    if(search(d1) == NULL)
    {
        cout << d1 << " is not in the list...";
        return false;
    }
    else
    {
        Node *pd1 = search(d1);
        int i;
        for (i = 1; i <= head->data; i++)
            if (search(i) == pd1)
                break;
        Node *pr = search(--i);
        pr->next = pd1->next;
        // if pr is new tail, move tail
        if (pr->next == NULL)
            tail->next = pr;
        head->data--;
        return true;
    }
}
bool LinkList::remove(int location, DataType &d1)
{
    if (location < 0 || location > head->data)
    {
        cout << "The list isn't so long...";
        return false;
    }
    else
    {
        Node *ploc = search(location);
        d1 = ploc->data;
        Node *pr = search(--location);
        pr->next = ploc->next;
        // if pr is new tail, move tail
        if (pr->next == NULL)
            tail->next = pr;
        head->data--;
        return true;
    }
}