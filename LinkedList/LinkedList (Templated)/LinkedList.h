//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef TEACH235_LIST_LINKEDLIST_H_
#define TEACH235_LIST_LINKEDLIST_H_

#include "ListInterface.h"
#include "Node.h"
#include "PreconditionViolatedException.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& a_list);
   LinkedList<ItemType>& operator=(const LinkedList<ItemType>& right_hand_side); 
   virtual ~LinkedList();

   bool IsEmpty() const;
   int GetLength() const;
   bool Insert(int new_position, const ItemType& new_entry);
   bool Remove(int position);
   void Clear();
   
   /** @throw PreconditionViolatedException if position < 1 or 
                                      position > getLength(). */
   ItemType GetEntry(int position) const throw(PreconditionViolatedException);

   /** @throw PreconditionViolatedException if position < 1 or 
                                      position > getLength(). */
   void SetEntry(int position, const ItemType& new_entry)
                               throw(PreconditionViolatedException);

private:
   Node<ItemType>* head_ptr_; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int item_count_;           // Current count of list items 
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* GetNodeAt(int position) const;

   // @param a_list a given bag.
   // Allocates space and copies all the nodes from a_list.
   // The function does not check whether this list contains
   // any items, but it assumes that it is empty.
   void CopyNodesFrom(const LinkedList<ItemType> &a_list);
}; // end LinkedList

#include "LinkedList.cpp"
#endif // TEACH235_LIST_LINKEDLIST_H_
