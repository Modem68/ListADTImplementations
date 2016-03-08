//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Interface for the ADT list
    Listing 8-1
    @file ListInterface.h */

#ifndef TEACH235_LIST_LISTINTERFACE_H_
#define TEACH235_LIST_LISTINTERFACE_H_

template<class ItemType>
class ListInterface
{
public:
   /** Sees whether this list is empty.
    @return True if the list is empty; otherwise returns false. */
   virtual bool IsEmpty() const = 0;
   
   /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
   virtual int GetLength() const = 0;
   
   /** Inserts an entry into this list at a given position.
    @pre  None.
    @post  If 1 <= position <= getLength() + 1 and the insertion is
       successful, newEntry is at the given position in the list,
       other entries are renumbered accordingly, and the returned
       value is true.
    @param newPosition  The list position at which to insert newEntry.
    @param newEntry  The entry to insert into the list.
    @return  True if insertion is successful, or false if not. */
   virtual bool Insert(int new_position, const ItemType& new_entry) = 0;
   
   /** Removes the entry at a given position from this list.
    @pre  None.
    @post  If 1 <= position <= getLength() and the removal is successful,
       the entry at the given position in the list is removed, other
       items are renumbered accordingly, and the returned value is true.
    @param position  The list position of the entry to remove.
    @return  True if removal is successful, or false if not. */
   virtual bool Remove(int position) = 0;
   
   /** Removes all entries from this list.
    @post  List contains no entries and the count of items is 0. */
   virtual void Clear() = 0;
   
   /** Gets the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The desired entry has been returned.
    @param position  The list position of the desired entry.
    @return  The entry at the given position. */
   virtual ItemType GetEntry(int position) const = 0;
   
   /** Replaces the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The entry at the given position is newEntry.
    @param position  The list position of the entry to replace.
    @param newEntry  The replacement entry. */
   virtual void SetEntry(int position, const ItemType& new_entry) = 0;
}; // end ListInterface
#endif // TEACH235_LIST_LISTINTERFACE_H_
