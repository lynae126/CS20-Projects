//*****************
//Program Name: lab 10.1 - Doubly Linked List
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Modify your Lab 8 work on Linked Lists to support a doubly-linked list
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
void printReverse(Node *list);
int menu();

int main() {
	srand(time(0));
	Node *myList = BuildList();
	char op;
	int choice = menu();
	while (choice != 4){
		switch (choice){
			case 1:
				cout << "\nOutput the doubly-linked list (F)orward or (B)ackward? --> ";
				cin >> op;
				if(tolower(op) == 'b')
					printReverse(myList);
				else if(tolower(op) == 'f')
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
	Node*first = nullptr, *newNode, *last;
	int num;
	cout << "How many nodes to generate [10-50]: ";
	cin >> num;
	while (num < 10 || num > 50 || cin.fail()){
		cout << "ERROR: 10-50 only: ";
		cin >> num;
	}

	for (int i = 1; i <= num; i++){
		int random = rand() % 100;
		newNode = new Node;
		newNode->value = random;
		newNode->next = nullptr;

		if (first == nullptr){
			newNode->prev = nullptr;
			first = newNode;
			last = newNode;
		}else{
			newNode->prev = last;
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
	Node *p, *newNode = new Node, *current;
	cout << "Enter the new node's value: ";
	int num;
	cin >> num;
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

	newNode->value = num;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	current = list;
	if (choice == 0 ){
		newNode->next = list;
		newNode->prev = nullptr;
		if(list!=nullptr)
			list->prev = newNode;
		list = newNode;
	}
	else{
		for (int i = 1; i <= choice; i++){
			p = current;
			current = current->next;
		}
		cout << "Inserting after element: " << p->value << endl;
		newNode->next = p->next;
		p->next = newNode;
		newNode->prev = p;
		if(newNode->next != nullptr)
			newNode->next->prev = newNode;
	}
	return list;
}

//deleteNode(): displays a submenu of the linked list, asking
//the user to select the node to be deleted, and deletes that node
//Arguments: list(Node *) | Returns: void
Node* deleteNode(Node *list){
	Node *current = list, *p = list;
	cout << "Enter the node number to be deleted:\n";
	int index = 1;
	while (current != NULL){
		cout << "\t[" << index++ << "] " << current->value << endl;
		current = current->next;
	}
	int choice;
	cin >> choice;
	current = list;
	if (choice == 1 && choice > 0){ //deleting head node
		current = current->next;
		delete p;
		p = nullptr;
		current->prev = nullptr;
	}else if(choice > 0){
		for (int i = 1; i < choice; i++){
			p = current;
			current = current->next;
		}
		current->next->prev = p;
		p->next = current->next;
	}
	return list;
}

//outputList(): output to the console the current state of the douly-linked list
//Arguments: list(Node *) | Returns: void
void outputList(Node *list){
	cout << "Current doubly-linked List output forward: \n";
	Node *current = list;
	while (current != nullptr){
		cout << current->value << " ";
		current = current->next;
	}
	cout << "\n\n";
}

//printReverse(): output to the console the current state of the doubly-linked list in reverse
//Arguments: list(Node *) | Returns: void
void printReverse(Node *list){
	cout << "Current doubly-linked List in reverse: \n";
	Node *current = list;
	//I had to get the tail of the list first before printing in reverse
	while (current->next != nullptr)
		current = current->next;
	while (current != nullptr){
		cout << current->value << " ";
		current = current->prev;
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
