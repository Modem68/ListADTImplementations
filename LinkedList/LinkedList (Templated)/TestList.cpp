//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

void DisplayList(const ListInterface<string>* list_ptr)
{
  cout << "The list contains " << endl;
  for (int pos = 1; pos <= list_ptr->GetLength(); pos++) {
    cout << list_ptr->GetEntry(pos) << " ";
  } // end for
  cout << endl << endl;
}  // end DisplayList

void CopyConstructorAndAssignmentOperatorTester() {
  const string items[] = {"zero", "one", "two", "three", "four", "five"};
  LinkedList<string> a_list;
  for (int i = 0; i < 6; i++) {
    cout << "Adding " << items[i] << endl;
    const bool success = a_list.Insert(1, items[i]);
    if (!success)
      cout << "Failed to add " << items[i] << " to the list." << endl;
  }
  DisplayList(&a_list);
  
  LinkedList<string> copy_of_list(a_list);
  cout << "Copy of list: ";
  DisplayList(&copy_of_list);
  
  cout << "The copied list: ";
  DisplayList(&a_list);

  cout << "I will change the original list by removing the second item: " << endl;
  a_list.Remove(2);
  cout << "This is the original list: " << endl;
  DisplayList(&a_list);
  cout << "This is the copied list: (it shouldn't have been affected: " << endl;
  DisplayList(&copy_of_list);

  copy_of_list = a_list;
  cout << "The copy is changed after assignment to: " << endl;
  
  DisplayList(&copy_of_list);

}  // end CopyContructorTester

void ListTester()
{
  ListInterface<string>* list_ptr = new LinkedList<string>();
  cout << "Testing the Link-Based List:" << endl;
  cout << "IsEmpty: returns " << list_ptr->IsEmpty() << "; should be 1 (true)" << endl;
  
  const string data[] = {"one", "two", "three", "four", "five", "six"};
  for (int i = 0; i < 6; i++) {
    if (list_ptr->Insert(i + 1, data[i]))
      cout << "Inserted " << list_ptr->GetEntry(i + 1)
	   << " at position " << (i + 1) << endl;
    else
      cout << "Cannot Insert " << data[i] << " at position " << (i + 1)
	   << endl;
  }  // end for
   
  DisplayList(list_ptr);
   
  cout << "IsEmpty: returns " << list_ptr->IsEmpty() << "; should be 0 (false)" << endl;
  cout << "GetLength returns : " << list_ptr->GetLength() << "; should be 6" << endl;
  
  cout << "The entry at position 4 is " << list_ptr->GetEntry(4) << "; should be four" << endl;
  cout << "After replacing the entry at position 3 with XXX: ";
  list_ptr->SetEntry(3, "XXX");
  DisplayList(list_ptr);
  
  cout << "Remove(2): returns " << list_ptr->Remove(2) << "; should be 1 (true)" << endl;
  cout << "Remove(1): returns " << list_ptr->Remove(1) << "; should be 1 (true)" << endl;
  cout << "Remove(6): returns " << list_ptr->Remove(6) << "; should be 0 (false)" << endl;
  DisplayList(list_ptr);
  cout << "GetLength returns : " << list_ptr->GetLength() << "; should be 4" << endl;
  cout << "Clear: " << endl;
  list_ptr->Clear();
  cout << "IsEmpty: returns " << list_ptr->IsEmpty() << "; should be 1 (true)" << endl;
  
  try {
    cout << "Attempt an illegal retrieval from position 6: " << endl;
    list_ptr->GetEntry(6);
  } catch (PreconditionViolatedException an_exception) {
    cout << an_exception.what() << endl;
  }  // end try/catch
  
  try {
    cout << "Attempt an illegal replacement at position 6: " << endl;
    list_ptr->SetEntry(6, "YYY");
  } catch (PreconditionViolatedException an_exception) {
    cout << an_exception.what() << endl;
  }  // end try/catch
  
} // end listTester


/*
 Expected program behavior:
 Adding zero
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 The list contains
 five four three two one zero
 
 Copy of list: The list contains
 five four three two one zero
 
 The copied list: The list contains
 five four three two one zero
 
 Testing the Link-Based List:
 IsEmpty: returns 1; should be 1 (true)
 Inserted one at position 1
 Inserted two at position 2
 Inserted three at position 3
 Inserted four at position 4
 Inserted five at position 5
 Inserted six at position 6
 The list contains
 one two three four five six
 
 IsEmpty: returns 0; should be 0 (false)
 GetLength returns : 6; should be 6
 The entry at position 4 is four; should be four
 After replacing the entry at position 3 with XXX: The list contains
 one two XXX four five six
 
 Remove(2): returns 1; should be 1 (true)
 Remove(1): returns 1; should be 1 (true)
 Remove(6): returns 0; should be 0 (false)
 The list contains
 XXX four five six
 
 GetLength returns : 4; should be 4
 Clear:
 IsEmpty: returns 1; should be 1 (true)
 Attempt an illegal retrieval from position 6:
 Precondition Violated Exception: GetEntry() called with an empty list or invalid position.
 Attempt an illegal replacement at position 6:
 Precondition Violated Exception: SetEntry() called with an invalid position.
*/

int main()
{
  CopyConstructorAndAssignmentOperatorTester();
  ListTester();
   return 0;
}  // end main

