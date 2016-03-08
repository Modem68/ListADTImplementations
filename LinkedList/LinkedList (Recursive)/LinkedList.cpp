//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
  
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

// NB: See LinkedSortedList in Chapter 12 for a recursive version of a copy constructor.
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   deallocate(headPtr);
   headPtr = nullptr;
   itemCount = 0;
   // OR simply call clear().
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
      headPtr = insertNode(newPosition, newNodePtr, headPtr);
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
      headPtr = deleteNode(position, headPtr);
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   deallocate(headPtr);
   headPtr = nullptr;
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position, headPtr);
      return nodePtr->getItem();
   }
   else
      throw(PrecondViolatedExcep("getEntry() called with an empty list or invalid position."));
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position, headPtr);
      nodePtr->setItem(newEntry);
   }
   else
      throw(PrecondViolatedExcep("setEntry() called with an invalid position."));
}  // end setEntry

// =======================================================================================
// PRIVATE METHODS:

// RECURSIVE
template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position, Node<ItemType>* curPtr) const
{
   assert( (position >= 1) && (position <= itemCount) );
   
   if (position == 1)
      return curPtr;
   else 
      return getNodeAt(position - 1, curPtr->getNext());
}  // end getNodeAt

// RECURSIVE
template<class ItemType> 
Node<ItemType>* LinkedList<ItemType>::InsertNode(int position, Node<ItemType>* new_node_ptr, 
                                                 Node<ItemType>* subChainPtr)
{
   if (position == 1)
   {
      // Insert new node at beginning of subchain
      new_node_ptr->SetNext(sub_chain_ptr); 
      sub_chain_ptr = new_node_ptr;
      itemCount++;  // Increase count of entries
   }
   else
   {
      Node<ItemType>* after_ptr = InsertNode(position - 1, new_node_ptr, sub_chain_ptr->GetNext());
      sub_chain_ptr->SetNext(after_ptr);
   }  // end if
      
   return sub_chain_ptr;
}  // end insertNode

// RECURSIVE
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::deleteNode(int position, Node<ItemType>* curPtr)
{
   if (position == 1)
   {
      // Delete the node and return it to the system
      Node<ItemType>* deleteNodePtr = curPtr;
      curPtr = curPtr->getNext();
      itemCount--;  // Decrease count of entries

      deleteNodePtr->setNext(nullptr);
      delete deleteNodePtr;
      deleteNodePtr = nullptr;
   }
   else
   {
      Node<ItemType>* afterPtr = deleteNode(position - 1, curPtr->getNext());
      curPtr->setNext(afterPtr);
   }  // end if
   
   return curPtr;
}  // end deleteNode

// RECURSIVE
template<class ItemType>
void LinkedList<ItemType>::deallocate(Node<ItemType>* nextNodePtr)
{
   if (nextNodePtr != nullptr)
   {
      Node<ItemType>* nodeToDeletePtr = nextNodePtr;
      nextNodePtr = nextNodePtr->getNext();
      delete nodeToDeletePtr;
      deallocate(nextNodePtr);
   }  // end if
}  // end deallocate

//  End of implementation file.
