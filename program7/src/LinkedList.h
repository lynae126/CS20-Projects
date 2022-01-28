/*
 * LinkedList.h
 *
 *  Created on: Mar 8, 2021
 *      Author: cc
 ---------------------------------------
         LinkedList<Type>
---------------------------------------
- ListNode (struct)
- head (ListNode*)
---------------------------------------
+ LinkedList()
+ ~LinkedList()
+ appendNode(Type): void
+ insertNode(Type): void
+ deleteNode(Type): void
+ displayList() const: void
+ search(Type): int
+ insertNodeAt(Type, int): void
+ deleteNodeAt(int): void
---------------------------------------
*/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class Type>
class LinkedList{
	private:
		struct ListNode{
			Type value;
			struct ListNode *next;
		};
		ListNode *head;

	public:
		LinkedList() { head = nullptr; } //constructor
		~LinkedList(); //destructor
		void appendNode(Type);
		void insertNode(Type);
		void deleteNode(Type);
		void displayList() const;
		int search(Type); //doesn't return Type because an index should be int no matter what
		void insertNodeAt(Type, int);
		void deleteNodeAt(int);
};

//LinkedList(): constructor
//Arguments: none | Returns: none
template <class Type>
LinkedList<Type>::~LinkedList()
{
	ListNode *current;
	ListNode *nextNode;

	//place current at the head of the list
	current = head;

	//while current isn't at the end of the list, delete nodes
	while (current != nullptr)
	{
		//save a pointer to the next node
		nextNode = nextNode->next;

		//delete the current ndoe
		delete current;

		//move current to the next node
		current = nextNode;
	}
}

//appendNode(): appends a new node to the end of the LL
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::appendNode(Type num)
{
	ListNode *newNode = new ListNode;  //memory alloc for the new node
	ListNode *current;  //nodePtr used for traversing the list

	//housekeeping for newly-created newNode
	newNode->value = num;
	newNode->next = nullptr;

	//if the list is empty make newNode the first node
	if (!head)
		head = newNode;
	//otherwise insert newNode at the end
	else
	{
		current = head;
		//find the last node in the list
		while (current->next)
			current = current->next;
		//insert newNode as the last node
		current->next = newNode;
	}
}

//displayList(): displays the LL's current state
//Arguments: none | Returns: void
template <class Type>
void LinkedList<Type>::displayList() const{
	ListNode *current;  //moves through the list
	current = head;
	while (current){
		cout << current->value << " ";
		current = current->next;
	}
}

//insertNode(): inserts a new node into the LL in order by value
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::insertNode(Type num){
	ListNode *newNode = new ListNode;
	ListNode *current;
	ListNode *previous = nullptr;  //points to current's previous node
	newNode->value = num; //housekeeping for newly-created newNode

	//if the list is empty make newNode the first node
	if (!head){  //same as if (head == nullptr)
		head = newNode;
		newNode->next = nullptr;
	} else{ //otherwise insert newNode at the end
		current = head;
		previous = nullptr;
		while (current != nullptr and current->value < num){ ////skip values less than num
			previous = current;
			current = current->next;
		}
		if (previous == nullptr){ //otherwise insert newNode at the end
			head = newNode;
			newNode->next = current;
		} else{
			previous->next = newNode;
			newNode->next = current;
		}
	}
}

//deleteNode(): deletes a node with the value num
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::deleteNode(Type num){
	ListNode *current;
	ListNode *previous;
	if (!head) return; //if the list is empty, do nothing

	//determine if the first node is the one to be deleted
	if (head->value == num){
		current = head->next;
		delete head;
		head = current;
	} else{
		current = head; //initialize current to the head of the list
		while (current and current->value != num){//skip ahead to the correct deletion node
			previous = current;
			current = current->next;
		}
		if (current){
			previous->next = current->next;
			delete current;
		}
	}
}

//search(): searches for element in LL
//Arguments: val (Type)| Returns: int
template <class Type>
int LinkedList<Type>::search(Type val){
	int index;

	return index;
}

//insertNodeAt(): inserts element in LL at location given
//Arguments: num (Type), index(int) | Returns: void
template <class Type>
void LinkedList<Type>::insertNodeAt(Type num, int index){


	//store the previous link to the current index and put the ind


	ListNode *newNode = new ListNode;
	ListNode *current;
	ListNode *previous = nullptr;  //points to current's previous node
		newNode->value = num; //housekeepixng for newly-created newNode

		//if the list is empty make newNode the first node
		if (!head){  //same as if (head == nullptr)
			head = newNode;
			newNode->next = nullptr;
		} else{ //otherwise insert newNode at the end
			current = head;
			previous = nullptr;
			while (current != nullptr and current->value < num){ ////skip values less than num
				previous = current;
				current = current->next;
			}
			if (previous == nullptr){ //otherwise insert newNode at the end
				head = newNode;
				newNode->next = current;
			} else{
				previous->next = newNode;
				newNode->next = current;
			}
		}







}

//deleteNodeAt(): deletes LL element at given location
//Arguments: index(int | Returns: void
template <class Type>
void LinkedList<Type>::deleteNodeAt(int){

}



#endif /* LINKEDLIST_H_ */
