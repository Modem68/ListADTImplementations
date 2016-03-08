//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation, recursive version.
 @file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
   
   // Locates the node at a given position within the subchain pointed to by subChainPtr.
   // Returns a pointer to the located node.
   Node<ItemType>* getNodeAt(int position, Node<ItemType>* listPtr) const;
   
   // Adds a given node at a given position within the subchain pointed to by subChainPtr.
   // Returns a pointer to the augmented subchain.
   Node<ItemType>* insertNode(int newPosition, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);
   
   // Deletes the node at a given position within the subchain pointed to by subChainPtr.
   // Returns a pointer to the revised subchain.
   Node<ItemType>* deleteNode(int position, Node<ItemType>* curPtr);
   
   // Deallocates all nodes assigned to this list.
   void deallocate(Node<ItemType>* nextNodePtr);

public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   
   /** @throw PrecondViolatedExcep if position < 1 or 
              position > getLength(). */
   ItemType getEntry(int position) const throw(PrecondViolatedExcep);

   /** @throw PrecondViolatedExcep if position < 1 or 
              position > getLength(). */
   void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
}; // end LinkedList

#include "LinkedList.cpp"

#endif 
