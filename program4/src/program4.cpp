//*****************
//Program Name: Program 4 (Array Operations Using Pointers)
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Array Operations Using Pointers
//*****************
#include <iostream>
using namespace std;
const int SIZE = 5;

//reverse(): return a pointer to an array with elements reversed
//Arguments: *arr(int) | Returns: *newArr (int)
int* reverse(int* arr){
	int* newArr = new int[SIZE];
	for(int i = 0;i<SIZE;i++)
		*(newArr+i) = *(arr+(SIZE - i - 1));
	return newArr;
}

//shift(): return a pointer to an array with elements shifted by the amount specified
//Arguments: *arr(int), num(int) | Returns: *newArr (int)
int* shift(int* arr, int num){
	//checking if num is valid
	if(num <= 0 || num > SIZE) return arr;
	int* newArr = new int[SIZE];
	int temp;

	for(int i = 0;i<SIZE;i++)
		*(newArr+i) = *(arr+i);
	for(int i = 0;i<num;i++){
		temp = *(newArr);
		for(int j = 0; j < SIZE - 1; j++)
			*(newArr+j) = *(newArr+j+1);
		*(newArr+SIZE-1) = temp;
	}
	return newArr;
}

//expand(): return a pointer to an array that has been expanded by one element
//Arguments: *arr(int) | Returns: *newArr (int)
int* expand(int* arr){
	int* newArr = new int[SIZE+1];
	//set the first element to be 0
	*newArr = 0;
	for(int i = 0;i<SIZE+1;i++)
		*(newArr+i+1) = *arr++;
	return newArr;
}

//print(): printing out the arrays using pointers
//Arguments: *arr(int), size(int) | Returns: void
void print(int* arr, int size){
	//making sure size is positive before printing
	if(size >= 0){
		for (int i = 0; i < size; i++)
			cout << *(arr + i) << " ";
		cout<<endl<<endl;
	}
}

int main() {
	int array[SIZE] = {1,2,3,4,5};
	int* arrRev = nullptr, *arrShift = nullptr, *arrExpand = nullptr;
	int num;

	cout<<"Array reversed:\n";
	arrRev = reverse(array);
	print(arrRev, SIZE);
	delete[] arrRev;

	cout<<"# elements do you want shifted to the left: ";
	cin >> num;
	cout<<"Array shifted:\n";
	arrShift = shift(array,num);
	print(arrShift, SIZE);
	delete[] arrShift;

	cout<<"Expanding the array by one:\n";
	arrExpand = expand(array);
	print(arrExpand, SIZE+1);
	delete[] arrExpand;
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
