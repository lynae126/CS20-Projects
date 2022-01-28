/*
 * DynamicFloatArray.cpp
 *
 *  Created on: Jan 21, 2021
 *      Author: cc
 */

#include "DynamicFloatArray.h"

//I don't know if we have to do function headers for constructors and destructors, but I'll do it anyways

//DynamicFloatArray(): constructor
//Arguments: none | Returns:
DynamicFloatArray :: DynamicFloatArray() : _size(0), _capacity(0)
	{array = nullptr;}
//DynamicFloatArray(): constructor
//Arguments: n(int) | Returns: N/A
DynamicFloatArray :: DynamicFloatArray(int n) : _size(n), _capacity(n)
	{array = new float[n];}
//DynamicFloatArray(): constructor
//Arguments: da(const DynamicFloatArray&) | Returns: N/A
DynamicFloatArray :: DynamicFloatArray(const DynamicFloatArray& da){
	array = new float[da.size()];
	_size = da.size();
	_capacity = da.capacity();
	for(int i = 0; i < da.size(); i++)
		array[i] = da[i];
}

//~DynamicFloatArray(): destructor
//Arguments: none | Returns: N/A
DynamicFloatArray :: ~DynamicFloatArray(){delete[] array;}

//push_back(): adds element to array
//Arguments: em(float) | Returns: void
void DynamicFloatArray :: push_back(float em){
	if(size() < capacity()){
		array[size()] = em;
		_size++;
	}else{
		_capacity *=2;
		float * newA = new float[capacity()];
		for(int i = 0; i < size(); i++)
			newA[i] = array[i];
		newA[size()] = em;
		_size++;
		delete[] array;
		array = newA;
	}
}

//pop_back(): deletes the last element the array
//Arguments: none | Returns: void
void DynamicFloatArray :: pop_back(){
	if(size()-1 != 0)
		_size--;
}

//size(): returns the current size of the dynamic array
//Arguments: none | Returns: int
int DynamicFloatArray :: size()const{return _size;}

//capacity(): returns the size of the current allocated capacity
//Arguments: none | Returns: int
int DynamicFloatArray :: capacity()const{return _capacity;}

//resize(): changes the current size of the array
//Arguments: n(int) | Returns: void
void DynamicFloatArray :: resize(int n){
	_size = n;
	float * newA = new float[n];
	for(int i = 0; i < n; i++)
		newA[i] = array[i];
	delete[] array;
	array = newA;
}

//reserve(): changes the capacity of the array
//Arguments: n(int) | Returns: void
void DynamicFloatArray :: reserve(int n){
	_capacity = n;
	float * newA = new float[n];
	for(int i = 0; i < n; i++)
		if(array[i] != 0)
			newA[i] = array[i];
	delete[] array;
	array = newA;
}

//operator[](): access the i-th element of the array
//Arguments: i(int) | Returns: float &
float & DynamicFloatArray :: operator[](int i) const{
	if(i > size()) {
		cout << "Index out of bounds" << endl;
		return array[0];
	}
	return array[i];
}

//operator<<(): overloading << operator to print array(size, capacity, and elements)
//Arguments: os(ostream&), da(const DynamicFloatArray&) | Returns: ostream&
ostream& operator<<(ostream& os, const DynamicFloatArray& da){
	os << "-------------------------------\n";
	os << "Array size: " << da.size() << endl;
	os << "Array capacity: " << da.capacity() << endl;
	os << "Array Elements: \n";
	for(int i = 0; i < da.size(); i++)
		if(da[i] != 0)
			os << "Element " << i << ": " << da[i] << endl;
	os << "-------------------------------\n";
	return os;
}
