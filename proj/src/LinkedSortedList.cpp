#include "LinkedSortedList.h"
#include <iostream>

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

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : itemCount(0)
{
}

template <class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{

  clear();

}

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
  headPtr = copyChain(aList.headPtr);
}

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

template <class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
  return itemCount == 0;
}

template <class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
  return itemCount;
}

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

template <class ItemType>
void LinkedSortedList<ItemType>::clear()
{
  while(!isEmpty())
    remove(1);
}

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
