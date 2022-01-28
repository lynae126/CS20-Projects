/*
 * stackType.h
 *
 *  Created on: Apr 12, 2021
 *      Author: cc
-----------------------------------
			stackType
-----------------------------------
- maxStackSize : int
- stackTop : int
- *list : Type
- copyStack(const stackType<Type>& otherStack): void
-----------------------------------
+ operator==(const stackType<Type>& otherStack)
			 const : bool
+ &operator=(const stackType<Type>&) :
			 const stackType<Type>
+ initializeStack() : void
+ isEmptyStack() const : bool
+ isFullStack() const : bool
+ push(const Type& newItem) : void
+ top() const : Type
+ pop() : void
+ stackType(int stackSize = 100);
+stackType(const stackType<Type>&)
+ ~stackType();
+ getSize()const : int
+ operator[](int n)const : Type
+ getMaxSize()const : int
+ reverseStack(const stackType<Type>& otherStack) : void
-----------------------------------
*/
#ifndef STACKTYPE_H_
#define STACKTYPE_H_
#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
class stackType{
	private:
		int maxStackSize; //maximum stack size
		int stackTop;     //points to the top of the stack
		Type *list;       //pointer to the array that holds the stack
		void copyStack(const stackType<Type>& otherStack);

	public:
		const stackType<Type>& operator=(const stackType<Type>&);
		bool operator==(const stackType<Type>& otherStack) const;
		int getSize()const;
		int getMaxSize()const{ return maxStackSize; }
		void initializeStack()     { stackTop = 0; }
		bool isEmptyStack() const  { return(stackTop == 0); }
		bool isFullStack() const   { return(stackTop == maxStackSize); }
		void push(const Type& newItem);
		Type top() const;
		Type operator[](int n)const{return list[n]; }
		void pop();
		void reverseStack(const stackType<Type>& otherStack);
		//constructors
		stackType(int stackSize = 100);
		stackType(const stackType<Type>&);
		//destructors
		~stackType();

};

//Function to allow one stack to be compared to another stack and evaluated for equality
//Postcondition: A copy of otherStack is compared with current to check for differences
template <class Type>
bool stackType<Type>::operator==(const stackType<Type>& otherStack) const{
	if(this == &otherStack)
		return true;
	if(this->top() != otherStack.top())
		return false;
	if(this->getMaxSize() != otherStack.getMaxSize())
			return false;
	if(this->getSize() != otherStack.getSize())
		return false;
	for(int i = 0; i < this->getSize(); i++)
		if(list[i] != otherStack[i])
			return false;
	return true;
}

//Function to return current size of stack
//Postcondition: The number of elements in stack are returned
template <class Type>
int stackType<Type>::getSize()const{
	int size = 0;
    while(list[size] != this->top())
    	size++;
    return size;
}

//Function to make a copy of otherStack.
//Postcondition: A copy of otherStack is created and assigned
//    to this stack.
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack){
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];

    //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack

//Overload the assignment operator
template <class Type>
const stackType<Type>& stackType<Type>::operator=
                    (const stackType<Type>& otherStack){
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);
    return *this;
} //end operator=

//Function to add newItem to the stack.
//Precondition: The stack exists and is not full.
//Postcondition: The stack is changed and newItem is
//    added to the top of the stack.
template <class Type>
void stackType<Type>::push(const Type& newItem){
    if (!isFullStack()){
        list[stackTop] = newItem;   //add newItem to the top
        stackTop++; //increment stackTop
    }
    else
        cerr << "Cannot add to a full stack." << endl;
}//end push

//Function to return the top element of the stack.
//Precondition: The stack exists and is not empty.
//Postcondition: If the stack is empty, the program
//    terminates; otherwise, the top element of the stack
//    is returned.
template <class Type>
Type stackType<Type>::top() const{
    assert(stackTop != 0);          //if stack is empty, terminate the program
    return list[stackTop - 1];      //return the element of the stack indicated by
}//end top                          //stackTop - 1


//Function to remove the top element of the stack.
//Precondition: The stack exists and is not empty.
//Postcondition: The stack is changed and the top element is
//    removed from the stack.
template <class Type>
void stackType<Type>::pop(){
    if (!isEmptyStack())
        stackTop--;                 //decrement stackTop
    else
        cerr << "Cannot remove from an empty stack." << endl;
}//end pop

//Constructor
//Create an array of the size stackSize to hold
//the stack elements. The default stack size is 100.
//Postcondition: The variable list contains the base address
//   of the array, stackTop = 0, and maxStackSize = stackSize
template <class Type>
stackType<Type>::stackType(int stackSize){
    if (stackSize <= 0){
        cerr << "Size of the array to hold the stack must " << "be positive." << endl;
        cerr << "Creating an array of size 100." << endl;
        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to the value specified by the parameter stackSize
    stackTop = 0;                   //set stackTop to 0 create the array to
    list = new Type[maxStackSize];  //hold the stack elements
}//end constructor

//Copy constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack){
    list = NULL;
    stackTop = 0;
    maxStackSize = 0;
    copyStack(otherStack);
}//end copy constructor

//Destructor
//Remove all the elements from the stack.
//Postcondition: The array (list) holding the stack
//    elements is deleted.
template <class Type>
stackType<Type>::~stackType() //destructor
	{ delete [] list; }

template <class Type>
void stackType<Type>::reverseStack(const stackType<Type>& otherStack){
	if(this->getMaxSize() != otherStack.getMaxSize())
		cerr << "Error, stack sizes don't match\n";
	int index = 1;
	while(index != otherStack.getMaxSize()+1){
		list[index] = otherStack[otherStack.getMaxSize()-index];
		cout << list[index] << endl;
		index++; //increment stackTop
	}
}

#endif /* STACKTYPE_H_ */
