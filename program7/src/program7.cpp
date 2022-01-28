//*****************
//Program Name: Program 7
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Add a bit more functionality to the Linked List class
//*****************

/*
 * Available
Available complete
Upload in-progress
Submit incomplete
Not Graded Yet incomplete
Program 7: Linked List ADT
Write a program that will leverage the Linked List ADT and add a bit more functionality to the class.

Overview
For this assignment, rather than inheriting a derived class from the ADT, like we did the past several weeks, we will be editing the base class itself with no inheritance.

I will use the driver program at the end of this assignment to evaluate your code. Remember, since the ADT uses the class template, you need to have your class definition and class implementation code in the same file, LinkedList.h. All you have to submit for this assignment is your LinkedList.h file. You do not need to submit a LinkedList.cpp file nor a main.cpp file.

Linked List ADT
Here's the page with the Linked List ADT.

Name your file "LinkedList.h" please -- very important.

New functionality to add to the class
We're now going to build on the Linked List ADT by adding three new functionalities:

search(Type): receives a value of type <Type> to search for. Returns the node's index number if successful; returns 0 if the search term wasn't found.
insertNodeAt(int): will insert a node at a specific position specified by the int argument
deleteNodeAt(int): will delete a node at a specific position specified by the int argument
Retain these methods from the LL ADT for class completeness and backward compatibility (don't delete them):

insertNode() - this method inserts a node based on order of the value
deleteNode() - this method deletes a node based on the value to be deleted
Known limitations
The LL ADT we're working with uses the insertNode() method to insert a node with values in increasing order.

However, we're modifying the ADT such that we can insert nodes anywhere we want with the insertNodeAt() method.

So it's fine if at some point your LL becomes unsorted. When that happens, the insertNode() method will simply insert the node at the first appropriate place it finds. This is fine for the purposes of our assignment. This is part of the concept of retaining slightly older code for backwards compatibility purposes.

*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
	LinkedList<double> list;

	cout << "Adding four nodes to the LL: ";
	list.appendNode(5.2);
	list.appendNode(7.9);
	list.appendNode(12.6);
	list.appendNode(15.5);
	list.displayList();

	cout << "\n\nInserting 10.2 into the LL in order: ";
	list.insertNode(10.2);
	list.displayList();

	cout << "\n\nDeleting 7.9: ";
	list.deleteNode(7.9);
	list.displayList();

	cout << "\n\nSearching for 5.2 in the LL...";
	int result = list.search(5.2);
	if (result == 0)
	cout << "not found.\n";
	else
	cout << "found at node #" << result << endl;

	LinkedList<int> list2;
	list2.appendNode(50);
	list2.appendNode(55);
	list2.appendNode(82);
	list2.appendNode(91);
	list2.appendNode(42);
	list2.appendNode(60);
	list2.appendNode(12);
	cout << "\n\nNew Linked List of ints: ";
	list2.displayList();
	cout << "Inserting 30 as the new fourth node: ";
	list2.insertNodeAt(30, 3);
	list2.displayList();
	cout << "Deleting the second node: ";
	list2.deleteNodeAt(1);
	list2.displayList();

	cout << "\n\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
