//*****************
//Program Name: Lab 12.2 - Linked List Based Stack
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: create a linked list based stack from scratch using a dynamic array
//*****************
#include <iostream>
using namespace std;
struct Node{
	int val;
	Node *next;
};
void push();
void initialize();
void pop();
int top();
void print();
Node *head = nullptr;

int main() {
	for(int i = 0; i < 6; i++)
		push();
	pop();
	initialize();
	for(int i = 0; i < 14; i++)
		push();
	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//initialize(): clears out stack elements
//Arguments: N/A | Returns: void
void initialize(){
	cout << "Stack initialization in progress.\n";
	head->val = 0;
	head->next = nullptr;
	print();
	head = nullptr;
}

//push(): adds a new top element tp the stack
//Arguments: N/A | Returns: void
void push(){
	/*
	 * For push, since the assignment is supposed to be a
	 * linked list based stack, it doesn't seem like I needed
	 * to worry about size or length of the stack, since I can
	 * just create a new element and put it in the front of the stack
	 * I had troubles with putting the element in the back of the
	 * stack since it kept giving me errors, but this method worked
	 * for some reason, it's not perfect, but it's as close as I can get.
	 */
	int elm;
	cout << "Push operation in progress: ";
	cin >> elm;
	Node *newNode = new Node();
	newNode->val = elm;
	newNode->next = head;
	head = newNode;
	print();
}

//pop(): deletes the top element in the stack
//Arguments: N/A | Returns: void
void pop(){
	cout << "Pop operation in progress: " << endl;
	Node* current = head;
	head = head->next;
	current->next = nullptr;
	free(current);
	print();
}

//top(): returns the top element of the stack without removing it
//Arguments: N/A | Returns: void
int top(){
	Node* current = head;
	int size = 0;
	while(current != nullptr){
		current = current->next;
		size++;
	}
	current = head;
	for(int i = 0; i < size - 1; i++)
		current = current->next;
	return current->val;
}

//print(): prints the state of the stack, as shown in the sample output below
//Arguments: N/A | Returns: void
void print(){
	Node* current = head;
	int size = 0;
	cout << "Current Stack: ";
	if(current->val == 0){
		cout << "<stack empty>";
		cout << "\nStack Size: 0" << endl;
		cout << "Top: 0" << endl << endl;
		return;
	}

	while(current != nullptr){
		cout << current->val << " ";
		current = current->next;
		size++;
	}
	cout << "\nStack Size: " << size << endl;
	cout << "Top: " << top() << endl << endl;
	delete current;
}
