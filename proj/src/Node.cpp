//NAME: Node.cpp
//DESC: implementation of node class
//USAGE: #include "Node.cpp"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018
#include "../include/Node.h"
#include <cstddef>
#include <iostream>

//default constructor
//no preconditions
//postcondition: a constructed node
template<class ItemType>
Node<ItemType>::Node()
{

}

//overloaded constructor
//pre: data of type ItemType
//post: a node that holds the data anItem
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{

}

//overloaded constructor
//pre: data type ItemType, pointer to a node
//post: a node that holds data anItem and points to another node nextNodePtr
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, std::shared_ptr<Node<ItemType> > nextNodePtr) : item(anItem), next(nextNodePtr)
{

}

//setter for node
//pre: data type anItem
//post: the data in the node is set to anItem
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
  this->item = anItem;
}

//setter for node
//pre: pointer to node
//post: node now points where nextNodePtr points
template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType> > nextNodePtr)
{
  next = nextNodePtr;
}

//getter for node
//pre: none
//post: returns the item in the node
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
  return item;
}

//getter for node
//pre: none
//post: returns next node from node
template<class ItemType>
std::shared_ptr<Node<ItemType> > Node<ItemType>::getNext() const
{
  return next;
}
