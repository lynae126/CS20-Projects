//*****************
//Program Name: lab 10.2 - Circular Linked List
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Modify your Lab 8 work on Linked Lists to support a circular linked list
//*****************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node{
    int value;
    Node *next;
};
Node* buildList();
int menu();
void outputList(Node*, int);
Node* addNode(Node*);
Node* deleteNode(Node*);

int main(){
    srand(time(0));
    Node *myList = buildList();
    int choice = menu(), elms;

    while (choice != 4){
        switch (choice){
        	case 1:
        		cout << "How many elements do you want printed? ";
        		cin >> elms;
				if(elms > 0)
					outputList(myList, elms);
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

//deleteNode(): deletes the user-specified LL node
//Arguments: pointer to the LL head | Returns: pointer to the LL head
Node* deleteNode(Node *list){
	Node *p, *current; //to traverse the list
    cout << "Enter the node number to be deleted:\n";
    int index = 2;
    current = list;
    cout << "\t[1] " << current->value << endl;
    current = current->next;
    while (current != list){
        cout << "\t[" << index++ << "] " << current->value << endl;
        current = current->next;
    }
    int choice;
    cin >> choice;

    if (choice == 1){
        p = list;
        list = list->next;
        delete p;
    } else {
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

//addNode(): adds a LL node in a user-specified location
//Arguments: pointer to the LL head | Returns: pointer to the LL head
Node* addNode(Node *list){
	Node *p, *newNode, *current;  //used to traverse the LL
    cout << "Enter the new node's value: ";
    int num;
    cin >> num;
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    cout << "Enter the node number just prior to your insertion point:\n";
    int index = 2;
    current = list;
    cout << "\t[0] New node at beginning\n";
    cout << "\t[1] " << current->value << endl;
    current = current->next;
    while (current != list){
        cout << "\t[" << index++ << "] " << current->value << endl;
        current = current->next;
    }
    int choice;
    cin >> choice;

    current = list;
    if (choice == 0){ // insert node at beginning
        newNode->next = list;
        list = newNode;
    } else {
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

//buildList(): builds a LL
//Arguments: none | Returns: pointer to the LL head
Node* buildList(){
	Node *first,  *newNode, *last;     //points to the LL tail
    int num;
    first = nullptr;

    cout << "How many nodes to generate [10-50]: ";
    cin >> num;
    while (num < 10 or num > 50 or cin.fail()){
        cout << "ERROR: 10-50 only: ";
        cin >> num;
    }

    for (int i = 1; i <= num; i++){
        int random = rand() % 100;
        newNode = new Node;
        newNode->value = random;
        newNode->next = nullptr;

        if (first == nullptr){
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    last->next = first;
    return first;
}

//outputList(): output to the console the current state of the doubly-linked list
//Arguments: list(Node *), elms(int) | Returns: void
void outputList(Node *list, int elms){
	Node *current = list;
	for(int i=0; i < elms; i++){
		cout << current->value << " ";
		current = current->next;
	}
	cout << "\n\n";
}

//menu(): presents menu, returns a validated user choice
//Arguments: none | Returns: validated user choice (int)
int menu(){
    cout << "Enter:\t[1] Output LL\n";
    cout << "\t[2] Insert node\n";
    cout << "\t[3] Delete node\n";
    cout << "\t[4] Quit\n";
    cout << "\nYour choice: ";
    int num;
    cin >> num;
    while (num < 1 or num > 4 or cin.fail()){
        cout << "ERROR; 1-4 only: ";
        cin >> num;
    }
    return num;
}
