/*
 * DynamicFloatArray.h
 * 	Created on: Jan 22, 2021
 *  Author: cc
 *
 *  !!!I don't know where to put the * and the & in the UML
 *     so please forgive me if I horribly mess this up
 *  __________________________________________________
 *  |		           DynamicFloatArray			  |
 *  |_________________________________________________|
 *  |		 	  									  |
 *  | - array: float *							 	  |
 *  | - _size: int								 	  |
 *  | - _capacity: int							 	  |
 *  |_________________________________________________|
 *  |												  |
 *  | + DynamicFloatArray()							  |
 *  | + DynamicFloatArray(int n)					  |
 *  | + DynamicFloatArray(const DynamicFloatArray& da)|
 *  | + ~DynamicFloatArray()						  |
 *  | + push_back(float em): void					  |
 *  | + pop_back(): void							  |
 *  | + size()const: int							  |
 *  | + capacity()const: int						  |
 *  | + resize(int n): void							  |
 *  | + reserve(int n): void						  |
 *  | + operator[](int i) const: float &			  |
 *  | + operator--(): void							  |
 *  | + operator+=(float em): void					  |
 *  | + operator <<(ostream& os,					  |
 *  |   const DynamicFloatArray& da): friend ostream& |
 *  |												  |
 *  |_________________________________________________|
 */

#include <iostream>
using namespace std;
#ifndef DYNAMICFLOATARRAY_H_
#define DYNAMICFLOATARRAY_H_

class DynamicFloatArray{
	float *array;
    int _size;
    int _capacity;

	public:
        DynamicFloatArray();
        DynamicFloatArray(int n);
        DynamicFloatArray(const DynamicFloatArray& da);
        ~DynamicFloatArray();

        void push_back(float em);
        void pop_back();
        int size()const;
        int capacity()const;
        void resize(int n);
        void reserve(int n);
        float & operator[](int i) const;
        friend ostream& operator <<(ostream& os, const DynamicFloatArray& da);

        //operator--(): executes a pop_back
        //Arguments: none | Returns: void
        void operator--(){pop_back();}

        //operator+-(): executes a push_back(element)
        //Arguments: em(float) | Returns: void
        void operator+=(float em){push_back(em);}
};
#endif /* DYNAMICFLOATARRAY_H_ */
