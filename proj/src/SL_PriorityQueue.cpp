#include "SL_PriorityQueue.h"
#include <iostream>

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
  std::cout << "FIXME: implement constructor" << std::endl;
}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq)
{
  std::cout << "FIXME: implement copy constructor" << std::endl;
}

template <class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
  std::cout << "FIXME: implement destructor" << std::endl;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
  std::cout << "FIXME: implement isEmpty()" << std::endl;
  return false;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  std::cout << "FIXME: implement enqueue()" << std::endl;
  return false;
}

template <class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
  std::cout << "FIXME: implement dequeue()" << std::endl;
  return false;
}

template <class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
  std::cout << "FIXME: implement peekFront()" << std::endl;
  return -1;
}
