//NAME: SL_PriorityQueue.cpp
//DESC: implementation of priority queue
//USAGE: #include "SL_PriorityQueue.cpp"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018
#include "SL_PriorityQueue.h"
#include <iostream>
#include <memory>

//constructor
//pre: none
//post: creates space in memory for the pointer
template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(std::make_unique<LinkedSortedList<ItemType> >())
{
}

//overloaded contructor
//pre: pq is a priority queue
//post: pq is copied over to slist
template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
  slistPtr->headPtr = copyChain(pq->headPtr);
}

//destructor
//pre: none
//post: clears the priority queue
template <class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
  slistPtr->clear();
}

// checks if priority queue is empty
//pre: none
//post:returns true if empty, false if not
template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
  return slistPtr->isEmpty();
}

// adds an item to back of queue
//pre: newEntry is of type ItemType
//post: returns true after node is inserted to sorted place
template <class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  slistPtr->insertSorted(newEntry);
  return true;
}

// removes item from front of queue
//pre: queue isn't empty
//post: the front of the queue is removed
template <class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
  return slistPtr->remove(1);
}

// returns a copy of the front of the queue
//pre: queue must not be empty
//post: the item is returned if there, throws an exception if not.
template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
  return slistPtr->getEntry(1);
}
