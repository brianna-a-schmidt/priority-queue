//NAME: Node.h
//DESC: specification of node class
//USAGE: #include "Node.h"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018

#ifndef _NODE
#define _NODE

#include <memory>

template<class ItemType>
class Node
{
private:
  ItemType item;
  std::shared_ptr<Node<ItemType> > next;
public:
  Node();
  Node(const ItemType& anItem);
  Node(const ItemType& anItem, std::shared_ptr<Node<ItemType> > nextNodePtr);
  void setItem(const ItemType& anItem);
  void setNext(std::shared_ptr<Node<ItemType> > nextNodePtr);
  ItemType getItem() const;
  std::shared_ptr<Node<ItemType> > getNext() const;
};
#endif
