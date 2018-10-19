//NAME: LinkedSortedList.cpp
//DESC: implementation of sorted list class
//USAGE: #include "LinkedSortedList.cpp"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018
#include "LinkedSortedList.h"
#include <iostream>

// gets node before an entry
//pre: list has entries
//post: the node before the entry is returned
template <class ItemType>
std::shared_ptr<Node<ItemType> > LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
  std::shared_ptr<Node<ItemType> > curPtr = headPtr;
  std::shared_ptr<Node<ItemType> > prevPtr = nullptr;

  while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
  {
    prevPtr = curPtr;
    curPtr = curPtr->getNext();
  }
  return prevPtr;
}

// gets the node at given position
//pre: the position exists in the list
//post: returns the node at that position
template <class ItemType>
std::shared_ptr<Node<ItemType> > LinkedSortedList<ItemType>::getNodeAt(int position) const
{

  std::shared_ptr<Node<ItemType> > curPtr = headPtr;
  for(int skip = 1; skip < position; skip++)
  {
    curPtr = curPtr->getNext();
  }
  return curPtr;
}

// copys one chain to anouther
//pre: the other chain exists
//post: the chain is copied to the other chain
template <class ItemType>
std::shared_ptr<Node<ItemType> > LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType> > origChainPtr)
{
  std::shared_ptr<Node<ItemType> > copiedChainPtr;
  if(origChainPtr == nullptr)
  {
    copiedChainPtr = nullptr;
    itemCount = 0;
  }
  else
  {
    std::shared_ptr<Node<ItemType> > copiedChainPtr (new Node<int>(origChainPtr->getItem()));
    copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    itemCount++;
  }
  return copiedChainPtr;
}

// constructor
//pre:none
//post: sets item count to 0
template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : itemCount(0)
{
}

// destructor
//pre: none
//post: clears the list
template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{

  clear();

}

//copy constructor
//pre: a list exists
//post: the chain is constructed from a copy
template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
  headPtr = copyChain(aList.headPtr);
}

// inserts an item to its sorted position
//pre: item is of ItemType
//post: item is inserted to its sorted position
template <class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
  std::shared_ptr<Node<ItemType> > newNodePtr = std::make_shared<Node<ItemType> >(newEntry);
  std::shared_ptr<Node<ItemType> > prevPtr = getNodeBefore(newEntry);

  if(isEmpty() || (prevPtr == nullptr))
  {
    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr;
  }
  else
  {
    std::shared_ptr<Node<ItemType> > aftPtr = prevPtr->getNext();
    newNodePtr->setNext(aftPtr);
    prevPtr->setNext(newNodePtr);
  }

  itemCount++;

}

// removes a node
//pre: item is there to remove
//post: item is removed from list and order is maintained
template <class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
  bool entryIsThere = false;
  int position = getPosition(anEntry);
  if(position)
  {
    entryIsThere = true;
    remove(position);
  }

  return entryIsThere;
}

//gets the position of an entry
//pre: item is in list
//post: returns position of entry
template <class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry)
{
  std::shared_ptr<Node<ItemType> > curPtr = headPtr;

  int position = 0;
  int lengthOfList = getLength();

  while(curPtr != nullptr)
  {
    position++;
    if(getEntry(position) == anEntry)
    {
      return position;
    }
    curPtr = curPtr->getNext();
  }

  if(position > getLength())
    return 0;
  else
    return position;
}

// checks if the list is empty
//pre: none
//post:returns true if list is empty, false otherwise.
template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
  return itemCount == 0;
}

// gets the length of the list
//pre: none
//post: returns the number of items in list
template <class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
  return itemCount;
}

//removes an entry by position from the list
//pre: that position exists in the list
//post: item is removed if it exists
template <class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
  bool ableToRemove = (position >=1) && (position <= itemCount);
  if(ableToRemove)
  {
    if (position == 1)
    {
      headPtr = headPtr->getNext();
    }
    else
    {

      std::shared_ptr<Node<ItemType> > prevPtr = getNodeAt(position-1); //might not work
      std::shared_ptr<Node<ItemType> > curPtr = prevPtr->getNext();
      prevPtr->setNext(curPtr->getNext());

      prevPtr->setNext(curPtr->getNext());
    }
    itemCount--;
  }
  return ableToRemove;
}

// clears the list
//pre: list is not empty
//post: the list is empty
template <class ItemType>
void LinkedSortedList<ItemType>::clear()
{
  while(!isEmpty())
    remove(1);
}

// gets the entry at the given position
//pre: the position exists in the list
//post: the entry at the position is returned, otherwise an exception is caught.
template <class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
  bool ableToGet = (position >= 1) && (position <= itemCount);
  if(ableToGet)
  {
    std::shared_ptr<Node<ItemType> > nodePtr = getNodeAt(position);
    return nodePtr->getItem();
  }
  else{
    std::string message = "getEntry() called with an empty list or ";
    message = message + "invalid position.";
    throw(PrecondViolatedExcep(message));
  }
}
