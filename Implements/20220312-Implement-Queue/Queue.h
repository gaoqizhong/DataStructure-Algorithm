// implement queues using single linked lists
// class Queue : public LinkList
#ifndef QUEUE_H_
#define QUEUE_H_
#include "LinkList\LinkList.h"
#include "LinkList\LinkList.cpp"

class Queue : public LinkList
{
    public:
        Queue();                                                    // create a empty Queue
        Queue(DataType ar[],int n);                                 // using ar[] to create a Queue
        ~Queue();                                                   // delete Queue
        bool enqueue(const DataType &d);                            // enter a Node
        bool dequeue(DataType &d);                                  // delete a Node
        // you can also use the following method defined in LinkList
        // bool isempty() const;                                    // judge it's empty or not
        // bool display() const;                                    // show all the Node
};

#endif