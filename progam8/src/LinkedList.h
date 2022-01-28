/*
 * LinkedList.h
 *
 *  Created on: Mar 20, 2021
 *      Author: cc
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;
/*
 * This is my original work; apart from standard tutoring
 * or class collaboration, I neither received help nor
 * copied this code from another source.
 */
template <class Type>
struct nodeType{
    Type info;
    nodeType<Type> *link;
};

/*
-----------------------------------
		linkedListIterator
-----------------------------------
- *current : nodeType<Type>
----------------------------
+ linkedListIterator()
+ linkedListIterator(nodeType<Type> *ptr)
+ operator* : Type
+ operator++() : linkedListIterator<Type>
+ operator==(const linkedListIterator<Type>& right) const : bool
+ operator!=(const linkedListIterator<Type>& right) const : bool
----------------------------
*/
template <class Type>
class linkedListIterator{
	private:
	   nodeType<Type> *current; //points to current node in the linked list
	public:
	   linkedListIterator();
	   linkedListIterator(nodeType<Type> *ptr);
	   Type operator*();
	   linkedListIterator<Type> operator++();
	   bool operator==(const linkedListIterator<Type>& right) const;
	   bool operator!=(const linkedListIterator<Type>& right) const;
};

//Default constructor
//Postcondition: current = NULL;
template <class Type>
linkedListIterator<Type>::linkedListIterator()
	{ current = NULL; }

//Constructor with a parameter.
//Postcondition: current = ptr;
template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
	{ current = ptr; }

//Constructor with a parameter.
//Postcondition: current = ptr;
template <class Type>
Type linkedListIterator<Type>::operator*()
	{ return current->info; }

//Constructor with a parameter.
//Postcondition: current = ptr;
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(){
    current = current->link;
    return *this;
}

//Overload the equality operator.
//Postcondition: Returns true if this iterator is equal to
//               the iterator specified by right,
//               otherwise it returns the value false.
template <class Type>
bool linkedListIterator<Type>::operator==
        (const linkedListIterator<Type>& right) const
		{ return (current == right.current); }

//Overload the not equal to operator.
//Postcondition: Returns true if this iterator is not
//               equal to the iterator specified by
//               right; otherwise it returns the value
//               false.
template <class Type>
bool linkedListIterator<Type>::operator!=
         (const linkedListIterator<Type>& right) const
		 { return (current != right.current); }

/*
-----------------------------------
		LinkedListType
-----------------------------------
- copyList(const LinkedListType<Type>& otherList) : void
----------------------------
+/- count : int
+/- *count : nodeType<Type>
+/- *last : nodeType<Type>
----------------------------

+ LinkedListType()
+ LinkedListType(const LinkedListType<Type>& otherList)
+ ~LinkedListType()
+ operator= (const LinkedListType<Type>&) : const LinkedListType<Type>&
+ initializeList() : void
+ isEmptyList() const : bool
+ print() const : void
+ length() const : int
+ destroyList() : void
+ front() const : Type
+ back() const : Type
+ insertFirst(const Type& newItem) : void
+ insertLast(const Type& newItem) : void
+ deleteNode(const Type& deleteItem) : void
+ search(Type) : int
+ begin() : linkedListIterator<Type>
+ end() : linkedListIterator<Type>
+ insertNodeAt(Type, int) : void
+ deleteNodeAt(int) : void
----------------------------
*/
template <class Type>
class LinkedListType{
	private:
		void copyList(const LinkedListType<Type>& otherList);
	protected:
		int count;   //variable to store the number of elements in the list
		nodeType<Type> *first; //pointer to the first node of the list
		nodeType<Type> *last;  //pointer to the last node of the list
	public:
		LinkedListType();
		LinkedListType(const LinkedListType<Type>& otherList);
		~LinkedListType();
		const LinkedListType<Type>& operator=
							 (const LinkedListType<Type>&);
		void initializeList();
		bool isEmptyList() const;
		void print() const;
		int length() const;
		void destroyList();
		Type front() const;
		Type back() const;
		linkedListIterator<Type> begin();
		linkedListIterator<Type> end();
		int search(Type);
		void insertNodeAt(Type, int);
		void deleteNodeAt(int);
		//Since the instructions said to retain these methods,
		//I'm assuming that means to not touch them
		void insertFirst(const Type& newItem);
		void insertLast(const Type& newItem);
		void deleteNode(const Type& deleteItem);
};

//Function to insert newItem at the beginning of the list.
//Postcondition: first points to the new list, newItem is
//               inserted at the beginning of the list,
//               last points to the last node in the
//               list, and count is incremented by 1.
template <class Type>
void LinkedListType<Type>::insertFirst(const Type& newItem){
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the actual first node
    count++;                    //increment count
    if (last == NULL)   //if the list was empty, newNode is also the last node in the list
        last = newNode;
}

//Function to insert newItem at the end of the list.
//Postcondition: first points to the new list, newItem
//               is inserted at the end of the list,
//               last points to the last node in the
//               list, and count is incremented by 1.
template <class Type>
void LinkedListType<Type>::insertLast(const Type& newItem){
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode to NULL
    if (first == NULL){  //if the list is empty, newNode is both the first and last node
        first = newNode;
        last = newNode;
        count++;        //increment count
    } else{    //the list is not empty, insert newNode after last
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual last node in the list
        count++;        //increment count
    }
}

//Function to delete deleteItem from the list.
//Postcondition: If found, the node containing
//               deleteItem is deleted from the list.
//               first points to the first node, last
//               points to the last node of the updated
//               list, and count is decremented by 1.
template <class Type>
void LinkedListType<Type>::deleteNode(const Type& deleteItem){
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else{
        if (first->info == deleteItem){ //Case 2
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        } else { //search the list for the node with the given info
            found = false;
            trailCurrent = first;  //set trailCurrent to point to the first node
            current = first->link; //set current to point to the second node

            while (current != NULL && !found){
                if (current->info != deleteItem){
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }

            if (found){ //Case 3; if found, delete the node
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted was the last node
                    last = trailCurrent; //update the value of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in " << "the list." << endl;
        }
    }
}

//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
//               otherwise it returns false.
template <class Type>
bool LinkedListType<Type>::isEmptyList() const
	{ return(first == NULL); }

//default constructor
//Initializes the list to an empty state.
//Postcondition: first = NULL, last = NULL, count = 0;
template <class Type>
LinkedListType<Type>::LinkedListType() {//default constructor
    first = NULL;
    last = NULL;
    count = 0;
}

//Function to delete all the nodes from the list.
//Postcondition: first = NULL, last = NULL, count = 0;
template <class Type>
void LinkedListType<Type>::destroyList(){
    nodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != NULL){   //while there are nodes in the list
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already been set to NULL by the while loop
    count = 0;
}

//Initialize the list to an empty state.
//Postcondition: first = NULL, last = NULL, count = 0;
template <class Type>
void LinkedListType<Type>::initializeList()
	{ destroyList(); }

//Function to output the data contained in each node.
//Postcondition: none
template <class Type>
void LinkedListType<Type>::print() const {
    nodeType<Type> *current; //pointer to traverse the list
    current = first;    //set current so that it points to the first node
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
}

//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.
template <class Type>
int LinkedListType<Type>::length() const
	{ return count; }

//Function to return the first element of the list.
//Precondition: The list must exist and must not be
//              empty.
//Postcondition: If the list is empty, the program
//               terminates; otherwise, the first
//               element of the list is returned.
template <class Type>
Type LinkedListType<Type>::front() const
	{ return first->info; }

//Function to return the last element of the list.
//Precondition: The list must exist and must not be
//              empty.
//Postcondition: If the list is empty, the program
//               terminates; otherwise, the last
//               element of the list is returned.
template <class Type>
Type LinkedListType<Type>::back() const
	{ return last->info; }

//Function to return an iterator at the beginning of the
//linked list.
//Postcondition: Returns an iterator such that current is
//               set to first.
template <class Type>
linkedListIterator<Type> LinkedListType<Type>::begin(){
    linkedListIterator<Type> temp(first);
    return temp;
}

//Function to return an iterator one element past the
//last element of the linked list.
//Postcondition: Returns an iterator such that current is
//               set to NULL.
template <class Type>
linkedListIterator<Type> LinkedListType<Type>::end(){
    linkedListIterator<Type> temp(NULL);
    return temp;
}

//Function to make a copy of otherList.
//Postcondition: A copy of otherList is created and
//               assigned to this list.
template <class Type>
void LinkedListType<Type>::copyList
                   (const LinkedListType<Type>& otherList){
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if (first != NULL) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.first == NULL){
        first = NULL;
        last = NULL;
        count = 0;
    } else {
        current = otherList.first; //current points to the list to be copied
        count = otherList.count;
        first = new nodeType<Type>;  //create the node
        first->info = current->info; //copy the info
        first->link = NULL;        //set the link field of the node to NULL
        last = first;              //make last point to the first node
        current = current->link;     //make current point to the next node

        while (current != NULL){
            newNode = new nodeType<Type>;  //create a node
            newNode->info = current->info; //copy the info
            newNode->link = NULL;       //set the link of newNode to NULL
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to the actual last node
            current = current->link;   //make current point to the next node
        }
    }
}

//destructor
//Deletes all the nodes from the list.
//Postcondition: The list object is destroyed.
template <class Type>
LinkedListType<Type>::~LinkedListType() //destructor
	{ destroyList(); }

template <class Type>
LinkedListType<Type>::LinkedListType
		(const LinkedListType<Type>& otherList){
    first = NULL;
    copyList(otherList);
}

//overload the assignment operator
template <class Type>
const LinkedListType<Type>& LinkedListType<Type>::operator=
		(const LinkedListType<Type>& otherList){
	if (this != &otherList) //avoid self-copy
		copyList(otherList);
	return *this;
}

//Function to search for linked list elements
//Postcondition: none
template <class Type>
int LinkedListType<Type>::search(Type data){
	int index = 0;
	nodeType<Type> *current = first;
	while(current != nullptr){
		if(current->info == data)
			return index;
		current = current->link;
		index++;
	}
	return 0;
}

//Function to insert a node at a specific position specified by the int argument
//Postcondition: none
template <class Type>
void LinkedListType<Type>::insertNodeAt(Type data, int index){
	if(index > 0){
		nodeType<Type> *prev, *newNode, *current;
		newNode = new nodeType<Type>;
		newNode->info = data;
		newNode->link = nullptr;
		current = first;

		if (index == 0){
			newNode->link = first;
			first = newNode;
		} else {
			for (int i = 1; i <= index; i++){
				prev = current;
				current = current->link;
			}
			newNode->link = current;
			prev->link = newNode;
		}
	}
}

//Function to delete a node at a specific position specified by the int argument
//Postcondition: none
template <class Type>
void LinkedListType<Type>::deleteNodeAt(int index){
	if(index > 0){
		nodeType<Type> *prev, *current = first;
		if (index == 1){
			prev = first;
			first = first->link;
			delete prev;
		} else {
			current = first;
			for (int i = 1; i <= index; i++){
				prev = current;
				current = current->link;
			}
			prev->link = current->link;
			delete current;
		}
	}
}
#endif /* LINKEDLIST_H_ */
