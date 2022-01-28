//*****************
//Program Name: lab 8 - Doubly Linked List
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: an interactive, menu-driven program to do two simple doubly-linked list operations: add node and delete node
//*****************
#include <iostream>
using namespace std;
struct Node{
	int value;
	Node *prev;
	Node *next;
};

Node* BuildList();
Node* addNode(Node *list);
Node* deleteNode(Node *list);
void outputList(Node *list);
int menu();

int main() {
	srand(time(0));
	Node *myList = BuildList();

	int choice = menu();
	while (choice != 4){
		switch (choice){
			case 1:
				outputList(myList);
				break;
			case 2:
				myList = addNode(myList);
				break;
			case 3:
				myList = deleteNode(myList);
				break;
			case 4:
				cout << "Program ending.";
		}
		choice = menu();
	}
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//BuildList(): build a linked list, prompt the user for how many
//elements they'd like in the LL (range: 10-50),create the linked
//list with that many elements, using random numbers for values
//Arguments: NA | Returns: pointer to LL
Node* BuildList(){
	Node*first, *newNode, *last;
	int num;
	first = nullptr;

	cout << "How many nodes to generate [10-50]: ";
	cin >> num;
	while (num < 10 || num > 50 || cin.fail()){
		cout << "ERROR: 10-50 only: ";
		cin >> num;
	}

	for (int i = 1; i <= num; i++){
		int rando = rand() % 100;
		newNode = new Node;
		newNode->value = rando;
		newNode->next = nullptr;

		if (first == nullptr){
			first = newNode;
			last = newNode;
		}else{
			last->next = newNode;
			last = newNode;
		}
	}
	return first;
}

//addNode(): asks user to provide a value, displays a submenu
//of the linked list, asking the user to select the insertion
//point, adds a node to the linked list at that insertion point.
//Arguments: list(Node *) | Returns: void
Node* addNode(Node *list){
	Node *p, *newNode, *current;
	cout << "Enter the new node's value: ";
	int num;
	cin >> num;
	newNode = new Node;
	newNode->value = num;
	newNode->next = nullptr;

	cout << "Enter the node number just prior to your insertion point:\n";
	int index = 1;
	current = list;
	cout << "\t[0] New node at beginning\n";
	while (current != nullptr){
		cout << "\t[" << index++ << "] " << current->value << endl;
		current = current->next;
	}
	int choice;
	cin >> choice;
	current = list;
	if (choice == 0){
		newNode->next = list;
		list = newNode;
	}
	else{
		for (int i = 1; i <= choice; i++){
			p = current;
			current = current->next;
		}
		cout << "Inserting after element: " << p->value << endl;
		newNode->next = current;
		p->next = newNode;
	}
	return list;
}

//deleteNode(): displays a submenu of the linked list, asking
//the user to select the node to be deleted, and deletes that node
//Arguments: list(Node *) | Returns: void
Node* deleteNode(Node *list){
	Node *p, *current;
	cout << "Enter the node number to be deleted:\n";
	int index = 1;
	current = list;

	while (current != NULL){
		cout << "\t[" << index++ << "] " << current->value << endl;
		current = current->next;
	}
	int choice;
	cin >> choice;
	if (choice == 1){
		p = list;
		list = list->next;
		delete p;
	}else{
		choice--;
		current = list;
		for (int i = 1; i <= choice; i++){
			p = current;
			current = current->next;
		}
		p->next = current->next;
		delete current;
	}
	return list;
}

//outputList(): output to the console the current state of the douly-linked list
//Arguments: list(Node *) | Returns: void
void outputList(Node *list){
	Node *current = list;
	while (current != nullptr){
		cout << current->value << " ";
		current = current->next;
	}
	cout << "\n\n";
}

//menu(): this function presents the menu to the user and returns the validated choice
//Arguments: NA | Returns: int
int menu(){
	int choice;
	do{
		cout << "Enter: \n[1] Output Doubly-Linked List\n[2] Insert Node\n[3] Delete Node\n[4] Quit\n";
		cin >> choice;
	}while(choice < 0 || choice > 4);
	cout << "Your Choice: " << choice << "\n";
	return choice;
}
