/*
 * Person.cpp
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
 */
#include "Person.h"
#include "Date.h"
#include <iostream>
using namespace std;

Person :: Person(int id, Date d){
	identity = id;
	birthday = d;
}

//setIdentity(): sets SSN number
//Arguments: id (int) | Returns: void
//Preconditions: amount is a valid, positive integer
void Person :: setIdentity(int id)
	{id >= 0 ? identity = id : identity = 0;}

//getIdentity(): returns the id number
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Person :: getIdentity()const
	{return identity;}

//setBirthday(): sets the date for the birthday
//Arguments: m (int), d (int), y (int) | Returns: void
//Preconditions: all are valid, positive integers
void Person :: setBirthday(int m, int d, int y){
	m >= 0 ? birthday.setMonth(m) : birthday.setMonth(0);
	d >= 0 ? birthday.setDay(d) : birthday.setDay(0);
	y >= 0 ? birthday.setYear(y) : birthday.setYear(0);
}

//setBirthday(): sets the date for the birthday
//Arguments: m (int), d (int), y (int) | Returns: void
//Preconditions: all are valid, positive integers
void Person :: setBirthday(const Date& d){
	d.getMonth() >= 0 ? birthday.setMonth(d.getMonth()) : birthday.setMonth(0);
	d.getDay() >= 0 ? birthday.setDay(d.getDay()) : birthday.setDay(0);
	d.getYear() >= 0 ? birthday.setYear(d.getYear()) : birthday.setYear(0);
}

//getBirthday(): returns the date for the birthday
//Arguments: N/A | Returns: int
//Preconditions: N/A
Date Person :: getBirthday()const
	{return birthday;}

//printPerson(): prints out the id and the birth date
//Arguments: N/A | Returns: void
//Preconditions: N/A
void Person :: printPerson(){
	cout << "SSN: " << identity << endl;
	cout << "Birthday: ";
	birthday.print();
	cout << endl;
}
