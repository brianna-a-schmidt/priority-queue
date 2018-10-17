#include "SL_PriorityQueue.h"
#include <iostream>
#include <memory>
template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(std::make_unique<LinkedSortedList<ItemType> >())
{
}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{

}

template <class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
  return slistPtr->isEmpty();
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  slistPtr->insertSorted(newEntry);
  return true;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
  return slistPtr->remove(1);
}

template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
  return slistPtr->getEntry(1);
}
