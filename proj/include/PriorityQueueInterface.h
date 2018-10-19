//NAME: PriorityQueueInterface.h
//DESC: specification of priority queue interface
//USAGE: #include "PriorityQueueInterface.h"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018

#ifndef PRIORITY_QUEUE_INTERFACE
#define PRIORITY_QUEUE_INTERFACE

template<class ItemType>
class PriorityQueueInterface
{
public:
    /*
    Checks if the queue is empty
    return true if empty, false if not
    */
    virtual bool isEmpty() const = 0;

    /*
    Adds new entry to back of queue
    postconditions: the entry is at the back of the queue if successful
    preconditions: an entry to be added, newEntry, of type ItemType
    returns true if addition was successful
    */
    virtual bool enqueue(const ItemType& newEntry) = 0;

    /*
    removes from the front of the queue
    post: the front of queue was removed
    returns true if removal was successful and false if not
    */
    virtual bool dequeue() = 0;

    /*
    copies the value at the front of the queue
    preconditions: the queue isn't empty
    postconditions: the front is returned and the queue remains unchanged
    returns the front of the queue
    */
    virtual ItemType peekFront() const = 0;
};
#endif
