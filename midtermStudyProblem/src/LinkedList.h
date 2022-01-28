/*
 * LinkedList.h
 *
 *  Created on: Mar 30, 2021
 *      Author: cc
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class Type>
class LinkedList{
	private:
		struct Node{
			Type value;
			struct Node *next;
		};
		Node *head;
	public:
		 LinkedList() { head = nullptr; }
		 ~LinkedList();
		 void appendNode(Type);
		 void insertNode(Type);
		 void deleteNode(Type);
		 void deleteNodeAt(int);
		 void displayList() const;
		 int search(Type);
		 void insertNodeAt(Type, int);
		 void deleteNodesByValue(Type);
};

template <class Type>
void LinkedList<Type>::deleteNodesByValue(Type n){
	Node* current, *prev, *last;
	if(!head) return; //if list is empty
	else{
		current = head;
		while(current){
			if(current->value = n){
				if(current == head){ //if deleting head node
					head = head->next;
					delete current;
					current = head;
					if(head = nullptr) last = nullptr;
				} else { //if not deleting head node
					prev->next = current->next;
					if(current = last) last = prev;
					delete current;
					current = prev;
				}
			} else {
				prev = current;
				current = current->next;
			}
		}
	}
}

template <class Type>
void LinkedList<Type>::deleteNode(Type n){
	Node *current, *prev;
	if(!head) return;
	if(head->value == n){
		current = head->next;
		delete head;
		head = current;
	} else {
		current = head;
		while(current != nullptr && current->value!=n){
			prev = current;
			current = current->next;
		}
		if(current){
			prev->next = current->next;
			delete current;
		}
	}
}

template <class Type>
LinkedList<Type>::~LinkedList(){
	Node* current, *nextNode;
	current = head;
	while(current != nullptr){
		nextNode = nextNode->next;
		delete current;
		current = nextNode;
	}
}

template <class Type>
void LinkedList<Type>::appendNode(Type n){
	Node *newNode = new Node, *current;
	newNode->value = n;
	newNode->next = nullptr;

	if(!head) head = newNode;
	else{
		current = head;
		while(current->next)
			current = current->next;
		current->next = newNode;
	}
}

template <class Type>
void LinkedList<Type>::displayList() const{
    Node *current;
    current = head;
    while (current){
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

template <class Type>
void LinkedList<Type>::insertNode(Type n){
    Node *newNode = new Node, *current, *prev = nullptr;
    newNode->value = n;
    if(!head){
    	head = newNode;
    	newNode->next = nullptr;
    } else {
    	current = head;
    	prev = nullptr;
    	while(current != nullptr && current->value < n){
    		prev = current;
    		current = current->next;
    	}
    	if(prev == nullptr){
    		head = newNode;
    		newNode->next = current;
    	} else {
    		prev->next = newNode;
    		newNode->next = current;
    	}
    }
}

template <class Type>
void LinkedList<Type>::insertNodeAt(Type n, int index){
	Node *newNode = new Node, *current = head;
	int num;
	newNode->value = n;
	newNode->next = nullptr;
	if(head == nullptr){
		head = newNode;
		return;
	}
	if(index == 0){
		newNode->next = head;
		head = newNode;
		return;
	}
	while(num <= index){
		if(current->next == nullptr || num == index){
			Node *temp = current->next;
			current->next = newNode;
			newNode->next = temp;
			return;
		}
		num++;
	}
}

template <class Type>
void LinkedList<Type>::deleteNodeAt(int index){
	Node *current = head;
	if(current == nullptr) return;
	while(index >0 && current){
		current = current->next;
		index --;
	}
	if(current == head){
		head = head->next;
		delete current;
		return;
	} else {
		if(current == nullptr) return;
		Node *tail = head;
		while(tail->next !=current)
			tail = tail->next;
		tail->next = current->next;
		delete current;
	}
}

template <class Type>
int LinkedList<Type>::search(Type n){
	int num = 1;
	Node *node = head;
	while(node){
		if(node->value == n) return num;
		else{
			node = node->next;
			num++;
		}
	}
	return 0;
}

#endif /* LINKEDLIST_H_ */
