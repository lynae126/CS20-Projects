/*
 * LinkedListType.h
 *
 *  Created on: Mar 23, 2021
 *      Author: cc
-----------------------------------
		linkedListIterator
-----------------------------------
- *current : nodeType<Type>
-----------------------------------
+ linkedListIterator()
+ linkedListIterator(nodeType<Type> *ptr)
+ operator*() : Type
+ operator++() : linkedListIterator<Type>
+ operator==
	(const linkedListIterator<Type>& right) const : bool
+ operator!=
	(const linkedListIterator<Type>& right) const : bool
-----------------------------------
*/
#ifndef LINKEDLISTTYPE_H_
#define LINKEDLISTTYPE_H_
#include <iostream>
using namespace std;

template <class Type>
struct nodeType{
    Type info;
    nodeType<Type> *link;
};

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
		  linkedListType
-----------------------------------
- copyList(const linkedListType<Type>& otherList) : void
-----------------------------------
# count : int
# *first : nodeType<Type>
# *last : nodeType<Type>
-----------------------------------
+ linkedListType(const linkedListType<Type>& otherList);
+ ~linkedListType();
+ operator= (const linkedListType<Type>&) :
  const linkedListType<Type>&
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
+ begin() : linkedListIterator<Type>
+ end() : linkedListIterator<Type>
-----------------------------------
*/
template <class Type>
class linkedListType{
	private:
		void copyList(const linkedListType<Type>& otherList);
	protected:
		int count;   //variable to store the number of elements in the list
		nodeType<Type> *first; //pointer to the first node of the list
		nodeType<Type> *last;  //pointer to the last node of the list
	public:
		linkedListType();
		linkedListType(const linkedListType<Type>& otherList);
		~linkedListType();
		const linkedListType<Type>& operator=
							 (const linkedListType<Type>&);
		void initializeList();
		bool isEmptyList() const;
		void print() const;
		int length() const;
		void destroyList();
		Type front() const;
		Type back() const;
		void insertFirst(const Type& newItem);
		void insertLast(const Type& newItem);
		void deleteNode(const Type& deleteItem);
		linkedListIterator<Type> begin();
		linkedListIterator<Type> end();
};

//Function to insert newItem at the beginning of the list.
//Postcondition: first points to the new list, newItem is
//               inserted at the beginning of the list,
//               last points to the last node in the
//               list, and count is incremented by 1.
template <class Type>
void linkedListType<Type>::insertFirst(const Type& newItem){
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the actual first node
    count++;                    //increment count
    if (last == NULL)   //if the list was empty, newNode is also the last node in the list
        last = newNode;
}//end insertFirst

//Function to insert newItem at the end of the list.
//Postcondition: first points to the new list, newItem
//               is inserted at the end of the list,
//               last points to the last node in the
//               list, and count is incremented by 1.
template <class Type>
void linkedListType<Type>::insertLast(const Type& newItem){
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode to NULL
    if (first == NULL){  //if the list is empty, newNode is both the first and last node
        first = newNode;
        last = newNode;
        count++;        //increment count
    } else {   //the list is not empty, insert newNode after last
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual last node in the list
        count++;        //increment count
    }
}//end insertLast


//Function to delete deleteItem from the list.
//Postcondition: If found, the node containing
//               deleteItem is deleted from the list.
//               first points to the first node, last
//               points to the last node of the updated
//               list, and count is decremented by 1.
template <class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem){
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list." << endl;
    else {
        if (first->info == deleteItem){ //Case 2
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        } else {//search the list for the node with the given info
            found = false;
            trailCurrent = first;  //set trailCurrent to point to the first node
            current = first->link; //set current to point to the second node
            while (current != NULL && !found){
                if (current->info != deleteItem){
                    trailCurrent = current;
                    current = current-> link;
                } else
                    found = true;
            }//end while

            if (found){ //Case 3; if found, delete the node
                trailCurrent->link = current->link;
                count--;
                if (last == current)   //node to be deleted was the last node
                    last = trailCurrent; //update the value of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in " << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
//               otherwise it returns false.
template <class Type>
bool linkedListType<Type>::isEmptyList() const
	{ return(first == NULL); }

//default constructor
//Initializes the list to an empty state.
//Postcondition: first = NULL, last = NULL, count = 0;
template <class Type>
linkedListType<Type>::linkedListType(){ //default constructor
    first = NULL;
    last = NULL;
    count = 0;
}

//Function to delete all the nodes from the list.
//Postcondition: first = NULL, last = NULL, count = 0;
template <class Type>
void linkedListType<Type>::destroyList(){
    nodeType<Type> *temp;   //pointer to deallocate the memory occupied by the node
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
void linkedListType<Type>::initializeList()
	{ destroyList(); }//if the list has any nodes, delete them

//Function to output the data contained in each node.
//Postcondition: none
template <class Type>
void linkedListType<Type>::print() const{
    nodeType<Type> *current; //pointer to traverse the list
    current = first;    //set current so that it points to the first node
    while (current != NULL){ //while more data to print
        cout << current->info << " ";
        current = current->link;
    }
}//end print

//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.
template <class Type>
int linkedListType<Type>::length() const
	{ return count; }  //end length

//Function to return the first element of the list.
//Precondition: The list must exist and must not be
//              empty.
//Postcondition: If the list is empty, the program
//               terminates; otherwise, the first
//               element of the list is returned.
template <class Type>
Type linkedListType<Type>::front() const
	{ return first->info; }//return the info of the first node

//Function to return the last element of the list.
//Precondition: The list must exist and must not be
//              empty.
//Postcondition: If the list is empty, the program
//               terminates; otherwise, the last
//               element of the list is returned.
template <class Type>
Type linkedListType<Type>::back() const
	{ return last->info; }//return the info of the last node

//Function to return an iterator at the beginning of the
//linked list.
//Postcondition: Returns an iterator such that current is
//               set to first.
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin(){
    linkedListIterator<Type> temp(first);
    return temp;
}

//Function to return an iterator one element past the
//last element of the linked list.
//Postcondition: Returns an iterator such that current is
//               set to NULL.
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end(){
    linkedListIterator<Type> temp(NULL);
    return temp;
}

//Function to make a copy of otherList.
//Postcondition: A copy of otherList is created and
//               assigned to this list.
template <class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList){
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if (first != NULL) //if the list is nonempty, make it empty
       destroyList();
    if (otherList.first == NULL){ //otherList is empty
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
        }//end while
    }//end else
}//end copyList

//destructor
//Deletes all the nodes from the list.
//Postcondition: The list object is destroyed.
template <class Type>
linkedListType<Type>::~linkedListType() //destructor
	{ destroyList(); }//end destructor

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList){
    first = NULL;
    copyList(otherList);
}//end copy constructor

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList){
    if (this != &otherList) //avoid self-copy
        copyList(otherList);
     return *this;
}
#endif /* LINKEDLISTTYPE_H_ */
