//NAME: LinkedSortedList.h
//DESC: specification of sorted list
//USAGE: #include "LinkedSortedList.h"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018

#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
  std::shared_ptr<Node<ItemType> > headPtr;
  int itemCount;

  std::shared_ptr<Node<ItemType> > getNodeBefore(const ItemType& anEntry) const;

  std::shared_ptr<Node<ItemType> > getNodeAt(int position) const;

  std::shared_ptr<Node<ItemType> > copyChain(const std::shared_ptr<Node<ItemType> > origChainPtr);

public:
  LinkedSortedList();
  LinkedSortedList(const LinkedSortedList<ItemType>& aList);
  ~LinkedSortedList();

  void insertSorted(const ItemType& newEntry);
  bool removeSorted(const ItemType& anEntry);
  int getPosition(const ItemType& anEntry);

  //same as listinterface
  bool isEmpty() const;
  int getLength() const;
  bool remove(int position);
  void clear();
  ItemType getEntry(int position) const throw(PrecondViolatedExcep);
};
#endif
