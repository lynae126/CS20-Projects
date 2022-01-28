//*****************
//Program Name: Lab 13 - Linked List Queue
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Write a program that implements a queue using a linked list
//*****************
#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;
struct Node{
	int val;
	Node *next;
};
int front(Node *head);
int back(Node *head);
Node* addQueue(Node *head);
Node* deleteQueue(Node *head);
void print(Node *head);

int main() {
	srand(time(0));
	int num;
	Node *head = nullptr;
	cout << "Operation #1:\n";
	head = addQueue(head);
	for(int i = 2; i < 16; i++){
		cout << "Operation #" << i <<":\n";
		num =rand()%2+1;
		(num == 1) ? head = addQueue(head) : head = deleteQueue(head);
	}
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//front(): returns the front value
//Arguments: *head (Node) | Returns: int
int front(Node *head){
	Node *current = head, *trail = head;
	while(current != nullptr){
		trail = current;
		current = current->next;
	}
	return trail->val;
}

//back(): returns the back value
//Arguments: *head (Node) | Returns: int
int back(Node *head){
	assert(head != nullptr);
	return head->val;
}

//addQueue():adds an element at the end of the queue
//Arguments: *head (Node) | Returns: Node *
Node* addQueue(Node *head){
	int elm = rand()%500 + 100;
	cout << "addQueue operation in progress: " << elm << endl;
	Node *newNode = new Node;
	newNode->val = elm;
	newNode->next = nullptr;
	if(!head)
		head = newNode;
	else {
		Node *current = head;
		while(current->next)
			current = current->next;
		current->next = newNode;
	}
	print(head);
	return head;
}

//deleteQueue(): removes/serves an element from the front of the queue
//Arguments: *head (Node) | Returns: Node *
Node* deleteQueue(Node *head){
	cout << "deleteQueue operation in progress: " << back(head) << endl;
	Node *current = head;
	if(current==nullptr){
		cout << "Cannot remove from an empty queue" << endl;
		return current;
	}
	head = current->next;
	print(head);
	return head;
}

//print(): prints the queue contents
//Arguments: *head (Node) | Returns: void
void print(Node *head){
	int size = 0;
	Node *current = head;
	cout << "Current queue: ";
	while(current){
		cout << current->val << " ";
		current = current->next;
		size++;
	}
	cout << "\nQueue size: " << size << "\n\n";
}
