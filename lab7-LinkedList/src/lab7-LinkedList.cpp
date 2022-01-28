//*****************
//Program Name: lab7 - LinkedList
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: interactive, menu-driven program to do two simple linked list operations: add node and delete node
//*****************
#include <iostream>
using namespace std;
struct Node{
	int value;
	Node *next;
};

Node* BuildList();
void addNode(Node *list);
void deleteNode(Node *list);
void outputList(Node *list);
int menu();

int main() {
	int choice = 0;
	Node* list = BuildList();
	do{
		choice = menu();
		switch(choice){
			case 1:
				outputList(list);
				break;
			case 2:
				addNode(list);
				break;
			case 3:
				deleteNode(list);
				break;
			case 4:
				cout << "Exiting menu...\n\n";
				break;
		};
	}while(choice!=4);
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//BuildList(): build a linked list, prompt the user for how many
//elements they'd like in the LL (range: 10-50),create the linked
//list with that many elements, using random numbers for values
//Arguments: NA | Returns: pointer to LL
Node* BuildList(){
	int num, count = 0;
	do {
		cout << "How many nodes to generate [10-50]: ";
		cin >> num;
	} while(num < 10 || num > 50);

	srand(time(0));
	Node* list;
	while(count!=num){
		Node *newVal = new Node;
		if(count == 0){
			list = newVal;
			newVal -> next = nullptr;
			newVal -> value = rand() % 101;
		} else {
			newVal -> next = list;
			newVal -> value = rand() % 101;
			list = newVal;
		}
		count++;
	}
	return list;
}

//addNode(): asks user to provide a value, displays a submenu
//of the linked list, asking the user to select the insertion
//point, adds a node to the linked list at that insertion point.
//Arguments: list(Node *) | Returns: void
void addNode(Node *list){
	int val, index, count = 1;
	Node *current = list;
	//getting node's value
	do{
		cout << "\nEnter the new node's value: ";
		cin >> val;
	}while(val < 0 || val > 100);
	//getting index to place node in
	//Since we are inserting the node prior to the insertion point, there's no
	//reason putting [0] New node at beginning, because inputting [1] would get
	//the same result
	do{
		cout << "Enter the node number just prior to your insertion point: \n";
		while (current != nullptr){
			cout << "[" << count << "] " << current -> value << "\n";
			current = current -> next;
			count++;
		}
		cin >> index;
		cout << endl;
	}while(index < 0);

	Node *newVal = new Node;

	if(index != 1){
		count = 0;
		current = list;
		while(count!=index-2){
			current = current -> next;
			count++;
		}
		newVal -> value = val;
		newVal -> next = current -> next;
		current -> next = newVal;
	} else if(index == 1) {
		newVal -> next= current;
		current = newVal;
		current -> value = val;
	}
}

//deleteNode(): displays a submenu of the linked list, asking
//the user to select the node to be deleted, and deletes that node
//Arguments: list(Node *) | Returns: void
void deleteNode(Node *list){
	Node *current = list, *previous = nullptr;
	int count = 1, index = 0;
	do{
		cout << "Enter the node number to be deleted:\n";
		while (current != nullptr){
			cout << "[" << count << "] " << current -> value << "\n";
			current = current -> next;
			count++;
		}
		cin >> index;
		cout << endl;
	}while(index < 1);

	current = list;
	count = 0;
	if(index == 1){
		previous = current;
		current = current -> next;
		return;
	}
	while(count != index-1){
		previous = current;
		current = current -> next;
		count++;
	}
	previous -> next = current -> next;
	delete previous, current;
}

//outputList(): this function will output the LL in its current state
//Arguments: list(Node *) | Returns: void
void outputList(Node * list){
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
		cout << "Enter: \n[1] Output Linked List\n[2] Insert Node\n[3] Delete Node\n[4] Quit\n";
		cin >> choice;
	}while(choice < 0 || choice > 4);
	cout << "Your Choice: " << choice << "\n";
	return choice;
}
