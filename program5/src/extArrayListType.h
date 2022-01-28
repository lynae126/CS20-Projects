/*
 * extArrayListType.h
 *
 *  Created on: Feb 17, 2021
 *      Author: cc
---------------------------------------
         extArrayListType<Type>
---------------------------------------
(inherited from arrayListType)
---------------------------------------
+ extArrayListType(int)
+ extArrayListType(const arrayListType<Type>&)
+ ~extArrayListType()
+ removeAt(int): void
+ min()const: Type
+ max()const: Type
+ removeAll(Type): void
---------------------------------------
*/
#ifndef EXTARRAYLISTTYPE_H_
#define EXTARRAYLISTTYPE_H_
#include "arrayListType.h"
using namespace std;

template <class Type>
class extArrayListType : public arrayListType<Type>{
	public:
		extArrayListType(int n) : arrayListType<Type>(n){};
		extArrayListType(const extArrayListType<Type>& otherList) :
			arrayListType<Type>(otherList){}
		~extArrayListType(){ delete[] this->list; }
		void removeAt(int location);
		Type min() const;
		Type max() const;
		void removeAll(Type val);
};

//removeAt(): removes list element by location
//Arguments: location (int) | Returns: void
template <class Type>
void extArrayListType<Type>::removeAt(int location){
    if (location < 0 || location >= this->listSize())
        cerr << "The location of the item to be removed " << "is out of range" << endl;
    else{
    	this->replaceAt(location, this->list[this->listSize()-1]);
    	this->length--;
    }
}

//min(): returns the min element of the list
//Arguments: N/A | Returns: Type
template <class Type>
Type extArrayListType<Type>::min()const{
	Type min = this->list[0];
	for(int i = 0; i < this->length; i++)
		if(min > this->list[i])
			min = this->list[i];
	return min;
}

//max(): returns the max element of the list
//Arguments: N/A | Returns: Type
template <class Type>
Type extArrayListType<Type>::max()const{
	Type max = this->list[0];
	for(int i = 0; i < this->length; i++)
		if(max < this->list[i])
			max = this->list[i];
	return max;
}

//removeAll(): removes all instances of a list element
//Arguments: val (Type) | Returns: void
template <class Type>
void extArrayListType<Type>::removeAll(Type val){
	for(int i = 0; i < this->length; i++)
		if(this->list[i] == val)
			this->removeAt(i);
}

#endif /* EXTARRAYLISTTYPE_H_ */
