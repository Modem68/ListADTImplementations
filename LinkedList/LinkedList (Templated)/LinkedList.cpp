//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
  
template<class ItemType>
LinkedList<ItemType>::LinkedList() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& a_list) 
{
  CopyNodesFrom(a_list);
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& right_hand_side) {
  if (this != &right_hand_side) {  
    Clear(); // First deallocate all memory.
    CopyNodesFrom(right_hand_side);  // Then copy everything.
  }
  return *this;  // Return self.
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   Clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::IsEmpty() const
{
   return item_count_ == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::GetLength() const
{
   return item_count_;
}  // end GetLength

template<class ItemType>
bool LinkedList<ItemType>::Insert(int new_position, const ItemType& new_entry)
{
  const bool able_to_insert = (new_position >= 1) && (new_position <= item_count_ + 1);
  if (!able_to_insert) return false;

  // Create a new node containing the new entry 
  Node<ItemType>* new_node_ptr = new Node<ItemType>(new_entry);  
  
  // Attach new node to chain
  if (new_position == 1) {
      // Insert new node at beginning of chain
      new_node_ptr->SetNext(head_ptr_); 
      head_ptr_ = new_node_ptr;
  } else {
    // Find node that will be before new node
    Node<ItemType>* prev_ptr = GetNodeAt(new_position - 1);
      
    // Insert new node after node to which prevPtr points
    new_node_ptr->SetNext(prev_ptr->GetNext()); 
    prev_ptr->SetNext(new_node_ptr);
  }  // end if
  
  item_count_++;  // Increase count of entries
  return true;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::Remove(int position)
{
  const bool able_to_remove = (position >= 1) && (position <= item_count_);
  if (!able_to_remove) return false;

  Node<ItemType>* cur_ptr = nullptr;
  if (position == 1) {
    // Remove the first node in the chain
    cur_ptr = head_ptr_; // Save pointer to node
    head_ptr_ = head_ptr_->GetNext();
  } else {
    // Find node that is before the one to delete
    Node<ItemType>* prev_ptr = GetNodeAt(position - 1);
         
    // Point to node to delete
    cur_ptr = prev_ptr->GetNext();
    
    // Disconnect indicated node from chain by connecting the
    // prior node with the one after
    prev_ptr->SetNext(cur_ptr->GetNext());
  }  // end if
      
  // Return node to system
  cur_ptr->SetNext(nullptr);
  delete cur_ptr;
  cur_ptr = nullptr;
  
  item_count_--;  // Decrease count of entries
  return true;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::Clear() {
  while (!IsEmpty())
    Remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::GetEntry(int position) const throw(PreconditionViolatedException)
{
   // Enforce precondition
   const bool able_to_get = (position >= 1) && (position <= item_count_);
   if (able_to_get) {
     Node<ItemType>* node_ptr = GetNodeAt(position);
     return node_ptr->GetItem();
   }
   
   const string message = "GetEntry() called with an empty list or invalid position."; 
   throw(PreconditionViolatedException(message)); 
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::SetEntry(int position, const ItemType& new_entry) throw(PreconditionViolatedException)
{
   // Enforce precondition
   const bool able_to_set = (position >= 1) && (position <= item_count_);
   if (able_to_set)
   {
      Node<ItemType>* node_ptr = GetNodeAt(position);
      node_ptr->SetItem(new_entry);
      return;
   }
   
   const string message = "SetEntry() called with an invalid position."; 
   throw(PreconditionViolatedException(message)); 
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::GetNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= item_count_) );
   
   // Count from the beginning of the chain
   Node<ItemType>* cur_ptr = head_ptr_;
   for (int i = 1; i < position; i++) {
     assert(cur_ptr != nullptr);  // This signifies a catastrophic condition.
     cur_ptr = cur_ptr->GetNext();
   }
      
   return cur_ptr;
}  // end getNodeAt

template<class ItemType>
void LinkedList<ItemType>::CopyNodesFrom(const LinkedList<ItemType> &a_list) {
  item_count_ = a_list.item_count_;
  Node<ItemType>* orig_chain_ptr = a_list.head_ptr_;  // Points to nodes in original chain  
  if (orig_chain_ptr == nullptr) {
    head_ptr_ = nullptr;  // Original list is empty
    return;
  }

  // Copy first node
  head_ptr_ = new Node<ItemType>();
  head_ptr_->SetItem(orig_chain_ptr->GetItem());
  
  // Copy remaining nodes
  Node<ItemType>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
  orig_chain_ptr = orig_chain_ptr->GetNext();     // Advance original-chain pointer
  while (orig_chain_ptr != nullptr)
    {
      // Get next item from original chain
      ItemType nextItem = orig_chain_ptr->GetItem();
      
      // Create a new node containing the next item 
      Node<ItemType>* new_node_ptr = new Node<ItemType>(nextItem);  
      
      // Link new node to end of new chain
      new_chain_ptr->SetNext(new_node_ptr); 
      
	  // Advance pointer to new last node      
      new_chain_ptr = new_chain_ptr->GetNext();
      
      // Advance original-chain pointer
	  orig_chain_ptr = orig_chain_ptr->GetNext();
    }  // end while
  
  new_chain_ptr->SetNext(nullptr);              // Flag end of chain
}
//  End of implementation file.
