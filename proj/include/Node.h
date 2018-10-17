#ifndef _NODE
#define _NODE

#include <iostream>
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
