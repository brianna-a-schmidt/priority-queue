#ifndef _SORTED_LIST_INTERFACE
#define _SORTED_LIST_INTERFACE

#include "PrecondViolatedExcep.h"
template<class ItemType>
class SortedListInterface
{
public:
  virtual void insertSorted(const ItemType& newEntry) = 0;
  virtual bool removeSorted(const ItemType& anEntry) = 0;
  virtual int getPosition(const ItemType& anEntry) = 0;
  virtual bool isEmpty() const = 0;
  virtual int getLength() const = 0;
  virtual bool remove(int position) = 0;
  virtual void clear() = 0;
  virtual ItemType getEntry(int position) const throw(PrecondViolatedExcep)= 0;
};
#endif
