//*****************
//Program Name: Midterm Study Problem
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: study problem for midterm
//*****************
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "temp.h"
#include "Die.h"
#include "LinkedList.h"
using namespace std;
const int size = 6;

int main() {
	//PART ONE
	temp test(-20);
	cout <<"At a temperature of " << test.getTemp() << "...\n";
	if(test.isEthylFreezing())
		cout << "Ethyl is frozen\n";
	if(test.IsEthylBoiling())
		cout << "Ethyl is boiling\n";
	if(test.isWaterFreezing())
		cout << "Water is frozen\n";
	if(test.IsWaterlBoiling())
		cout << "Water is boiling\n";
	if(test.isOxygenFreezing())
		cout << "Oxygen is frozen\n";
	if(test.IsOxygenBoiling())
		cout << "Oxygen is boiling\n";

	//PART TWO
	srand(time(0));
	string choice;
	int coTotal = 0, usTotal = 0;
	Die die1(size);
	Die die2(size);
	cout << "\n------------------\nBlack Jack\n------------------\n";
	do{
		cout << "Do you want to roll?\n";
		cout << "Enter Y for yes or N for no: ";
		getline(cin, choice);
		cout << endl;
		if(choice == "y" || choice == "Y"){
			die1.roll();
			die2.roll();
			coTotal += die1.getValue() + die2.getValue();
			die1.roll();
			die2.roll();
			usTotal += die1.getValue() + die2.getValue();
			cout << "Current Total: " << usTotal << endl;
		}
	} while ((usTotal < 21) && (choice == "Y" || choice == "y"));

	if (usTotal > 0){
		cout << "\n-----------------------------------\n";
		cout << "The computer had " << coTotal << " points.\n";
		cout << "You had " << usTotal << " points.\n";

	if (usTotal <= 21){
		if (usTotal > 21 || coTotal > 21) //user wins
			cout << "\nCongratualtions! You won!\n";
		else //user does not win
			cout << "\nBetter luck next time.\n";
	} else //user does not win
		cout << "\nBetter luck next time.\n";
	cout << "\n-----------------------------------\n";
	cout << "\nGame Over\n\n";

	//PART THREE
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

	cout << "Adding nodes: ";
	list2.appendNode(91);
	list2.appendNode(42);
	list2.appendNode(60);
	list2.appendNode(12);
	list2.appendNode(42);
	list2.appendNode(60);
	list2.appendNode(42);
	list2.displayList();

	cout << "Deleting all nodes holding 42: ";
	list2.deleteNodesByValue(42);
	list2.displayList();

	return 0;
	}
}
