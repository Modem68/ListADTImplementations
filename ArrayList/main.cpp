//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "ArrayList.h" // ADT list operations
#include <iostream>
#include <string>

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	cout << "The list contains " << endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl;
}  // end displayList

void listTester(ListInterface<string>* listPtr)
{
	string data[] = {"one", "two", "three", "four", "five", "six"};
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
	for (int i = 0; i < 6; i++)
   {
		if (listPtr->insert(i + 1, data[i]))
         cout << "Inserted " << listPtr->getEntry(i + 1) << " at position " << (i + 1) << endl;
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1) << endl;
	}  // end for
   
   displayList(listPtr);
   
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 5" << endl;
   
   cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
   cout << "After replacing the entry at position 3 with XXX: ";
   listPtr->setEntry(3, "XXX");
   displayList(listPtr);
    
   cout << "remove(2): returns " << listPtr->remove(2) << "; should be 1 (true)" << endl;
   cout << "remove(1): returns " << listPtr->remove(1) << "; should be 1 (true)" << endl;
   cout << "remove(6): returns " << listPtr->remove(6) << "; should be 0 (false)" << endl;
   displayList(listPtr);
   
   cout << "clear: " << endl;
   listPtr->clear();
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   
   try
   {
      cout << "Attempt an illegal retrieval from position 6: " << endl;
      listPtr->getEntry(6);
   }
   catch(PrecondViolatedExcep e)
   {
      cout << e.what() << endl;
   }  // end try/catch
   
   try
   {
      cout << "Attempt an illegal replacement at position 6: " << endl;
      listPtr->setEntry(6, "YYY");
   }
   catch(PrecondViolatedExcep e)
   {
      cout << e.what() << endl;
   }  // end try/catch
   
} // end listTester

int main()
{
	ListInterface<string>* listPtr = new ArrayList<string>();
	cout << "Testing the Array-Based List:" << endl;
	listTester(listPtr);
   return 0;
}  // end main

/*
 Testing the Array-Based List:
 isEmpty: returns 1; should be 1 (true)
 Inserted one at position 1
 Inserted two at position 2
 Inserted three at position 3
 Inserted four at position 4
 Inserted five at position 5
 Cannot insert six at position 6
 The list contains 
 one two three four five 
 isEmpty: returns 0; should be 0 (false)
 getLength returns : 5; should be 5
 The entry at position 4 is four; should be four
 After replacing the entry at position 3 with XXX: The list contains 
 one two XXX four five 
 remove(2): returns 1; should be 1 (true)
 remove(1): returns 1; should be 1 (true)
 remove(6): returns 0; should be 0 (false)
 The list contains 
 XXX four five 
 clear: 
 isEmpty: returns 1; should be 1 (true)
 Attempt an illegal retrieval from position 6: 
 Precondition Violated Exception: getEntry() called with an empty list or invalid position.
 Attempt an illegal replacement at position 6: 
 Precondition Violated Exception: setEntry() called with an invalid position. 
*/
