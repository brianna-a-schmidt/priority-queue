#include "../include/Node.h"
#include <cstddef>
#include <iostream>

template<class ItemType>
Node<ItemType>::Node()
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, std::shared_ptr<Node<ItemType> > nextNodePtr) : item(anItem), next(nextNodePtr)
{

}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
  //std::cout << "we good" << std::endl; this displays

  this->item = anItem;

  std::cout << "we good" << std::endl;  //but this doesn't
}

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType> > nextNodePtr)
{
  next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
  return item;
}

template<class ItemType>
std::shared_ptr<Node<ItemType> > Node<ItemType>::getNext() const
{
  return next;
}
