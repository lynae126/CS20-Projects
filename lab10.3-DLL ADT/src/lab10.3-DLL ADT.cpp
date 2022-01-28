//*****************
//Program Name: lab 10.3 - Doubly Linked List ADT
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Write a driver program which fully demonstrates all capabilities of the Doubly-Linked List ADT.
//*****************
#include <iostream>
#include "DLL.h"
using namespace std;

int main() {
	doublyLinkedList<int> list;
	cout << "Creating a doubly linked list: \n";
	cout << "------------------------------\n";
	list.insert(11);
	list.insert(22);
	list.insert(17);
	list.insert(15);
	list.insert(18);
	list.insert(32);
	cout << "Printing out list...\n";
	list.print();
	cout << "\nDeleting nodes 15 and 11...\n";
	list.deleteNode(15);
	list.deleteNode(11);
	list.print();

	cout << "\n\nCopying list's values into list2: \n";
	cout << "------------------------------\n";
	doublyLinkedList<int> list2 = list;
	cout << "Printing out list2...\n";
	list2.print();
	cout << "\nPrinting out list2 in reverse...\n";
	list2.reversePrint();
	cout << "\n\nList Length: " << list2.length() << endl;
	cout << "List Front: " << list2.front() << endl;
	cout << "List Back: " << list2.back() << endl;
	cout << "15 is in list: " << list2.search(15) << endl;
	cout << "22 is in list: " << list2.search(22) << endl;

	doublyLinkedList<int> list3(list);
	cout << "\nCopying list's values into list3: \n";
	cout << "------------------------------\n";
	cout << "Printing out list3...\n";
	list3.print();
	cout << "\nInitializing list3...\n";
	list3.initializeList();
	if(list3.isEmptyList())
		cout << "List 3 is empty.\n";
	else
		cout << "List 3 isn't empty.\n";
	cout << "\nSetting list3 back to its original values..\n";
	list3 = list;
	list3.print();
	cout << "\nDeleting list3...\n";
	if(!list2.isEmptyList()){
		list3.destroy();
		cout << "List 3 is now empty.\n";
	}
	list3.print();

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

