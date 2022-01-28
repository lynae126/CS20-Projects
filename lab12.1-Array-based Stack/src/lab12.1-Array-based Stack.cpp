//*****************
//Program Name: Lab 12.1 - Array-based Stack
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: create a stack from scratch using a dynamic array
//*****************
#include <iostream>
using namespace std;
int *push(int *array, int &maxSize, int &length);
int *initialize(int *array, int &maxSize, int &length);
int *pop(int *array, int &maxSize, int &length);
int top(int *array, int length);
void print(int *array, int maxSize, int length);

int main() {
	int maxSize = 5, length = 0;
	int *array = new int[maxSize];
	for(int i = 0; i < 6; i++)
		array = push(array, maxSize, length);
	array = pop(array, maxSize, length);
	array = initialize(array, maxSize, length);
	for(int i = 0; i < 14; i++)
		array = push(array, maxSize, length);

	delete []array;
	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//initialize(): clears out stack elements
//Arguments: *array(int), &maxSize(int), &length(int) | Returns: int*
int *initialize(int *array, int &maxSize, int &length){
	cout << "Stack initialization in progress.\n";
	length = 0;
	int *newArr = new int[maxSize];
	for(int i = 0; i < maxSize; i++)
		newArr[i] = 0;
	delete [] array;
	print(newArr, maxSize, length);
	return newArr;
}

//push(): adds a new top element tp the stack
//Arguments: *array(int), &maxSize(int), &length(int) | Returns: int*
int* push(int *array, int &maxSize, int &length){
	int elm;
	cout << "Push operation in progress: ";
	cin >> elm;
	if(length != maxSize)
		array[length] = elm;
	else {
		cout << "Array too small for push operation; allocating new memory.\n";
		maxSize *= 2;
		int *newArr = new int[maxSize];
		for(int i = 0; i < length; i++)
			newArr[i] = array[i];
		newArr[length] = elm;
		delete[]array;
		length++;
		print(newArr, maxSize, length);
		return newArr;
	}
	length++;
	print(array, maxSize, length);
	return array;
}

//pop(): deletes the top element in the stack
//Arguments: *array(int), &maxSize(int), &length(int) | Returns: int*
int *pop(int *array, int &maxSize, int &length){
	cout << "Pop operation in progress: " << endl;
	array[length] = 0;
	length--;
	print(array, maxSize, length);
	return array;
}

//top(): returns the top element of the stack without removing it
//Arguments: *array(int), length(int) | Returns: top (int)
int top(int *array, int length){
	if(array[length-1] == 0) return -1;
	return array[length-1];
}

//print(): prints the state of the stack, as shown in the sample output below
//Arguments: *array(int), maxSize(int), length(int) | Returns: void
void print(int *array, int maxSize, int length){
	cout << "Current Stack: ";
	if(length==0)
		cout << "<stack empty>";
	for(int i = 0; i < length; i++)
		cout << array[i] << " ";
	cout << "\nStack Size: " << length << endl;
	cout << "Array Size: " << maxSize << endl;
	if(top(array, length) == -1)
		cout << "Top: <stack empty>\n\n";
	else
		cout << "Top: " << top(array, length) << endl << endl;
}
