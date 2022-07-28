// implement Stack using single linked lists
// class Stack : public LinkList
#ifndef STACK_H_
#define STACK_H_
#include "LinkList\LinkList.h"
#include "LinkList\LinkList.cpp"

class Stack : public LinkList
{
    public:
        Stack();                                                    // create a empty Stack
        Stack(DataType ar[],int n);                                 // using ar[] to create a Stack
        ~Stack();                                                   // delete Stack
        bool push(const DataType &d);                               // enter a Node
        bool pop(DataType &d);                                      // delete a Node
        // you can also use the following method defined in LinkList
        // bool isempty() const;                                    // judge it's empty or not
        // bool display() const;                                    // show all the Node
};

#endif