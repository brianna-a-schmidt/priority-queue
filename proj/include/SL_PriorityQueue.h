#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"
#include <memory>

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
  std::unique_ptr<LinkedSortedList<ItemType> > slistPtr ;

public:
  SL_PriorityQueue();
  SL_PriorityQueue(const SL_PriorityQueue& pq);
  ~SL_PriorityQueue();

  bool isEmpty() const;
  bool enqueue(const ItemType& newEntry);
  bool dequeue();

  //@throw PrecondViolatedExcept if priority queue is isEmpty
  ItemType peekFront() const throw(PrecondViolatedExcep);
};

#endif
