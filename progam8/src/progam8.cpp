//*****************
//Program Name: Program 8 - Linked List ADT Expansion
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: leverage the Linked List ADT and add a bit more functionality to the class
//*****************
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedListType<double> list;

    cout << "Adding three nodes to the LL:\n";
    list.insertFirst(5.2);
    list.insertFirst(7.9);
    list.insertFirst(12.6);
    list.print();

    cout << "\n\nDeleting 7.9:\n";
    list.deleteNode(7.9);
    list.print();

    cout << "\n\nInserting more values at the back:\n";
    list.insertLast(86.86);
    list.insertLast(153);
    list.insertLast(543.2);
    list.insertLast(15.1);
    list.print();

    cout << "\n\nSearching for 153:\n";
    bool found = list.search(153);
    if (found)
        cout << "\tValue is found\n";
    else
        cout << "\tValue is not found\n";

    cout << "\n\nInserting 999 into position 3:\n";
    list.insertNodeAt(999, 3);
    list.print();
    cout << "\n\nDeleting position 2:\n";
    list.deleteNodeAt(2);
    list.print();

    cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
    return 0;
}
