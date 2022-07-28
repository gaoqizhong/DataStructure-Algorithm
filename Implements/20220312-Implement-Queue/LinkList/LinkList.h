// LinkList with head and tail
#ifndef LINKLIST_H_
#define LINKLIST_H_
#include <iostream>
typedef double DataType;                                              // DataType can't be int

struct Node
{
	DataType data;
	Node *next;
};
class LinkList
{
    protected:
	    Node *head;                                                   // head->next == first Node, head->data == size
        Node *tail;                                                   // tail->next == last Node, tail->next == 0
        inline Node *search(int location) const;                      // search by location
        inline Node *search(DataType value) const;                    // search by value
    public:
        LinkList();                                                   // create a empty LinkList
        LinkList(DataType ar[],int n);                                // using ar[] to create a LinkList
        virtual ~LinkList();                                          // destructor prepare for inheritance
        bool isempty() const;                                         // judge it's empty or not
        bool insert(DataType d1, DataType d2);                        // insert d1 after d2
        bool insert(DataType d1, int location);                       // insert d1 to a location
        bool remove(DataType d1);                                     // remove d1 from LinkList
        bool remove(int location, DataType &d1);                      // remove location's Node and return to d1
        bool display() const;                                         // show all the Node
};

#endif