/*
 * extDateType.cpp
 *
 *  Created on: Feb 5, 2021
 *      Author: cc
 */
#include "extDateType.h"
#include <iostream>
using namespace std;

//isLeapYear(): returns if year is a leap year
//Arguments: N/A | Returns: bool
//Preconditions: if year is a positive int and is divisible by 4
bool extDateType :: isLeapYear()
	{return (getYear() % 4 == 0);}

//numDays(): getting the number of days in a given month
//Arguments: m(int) | Returns: int
//Preconditions: if m is a positive int from 1 to 12
int extDateType :: numDays(int m){
	if(m>=1 && m <=12){
		if(m == 2){
			if(isLeapYear())
				return 29;
			return 28;
		}else if(m % 2 == 0)
			return 30;
		else
			return 31;
	}
	return 0;
}

//daysPassed(): returns how many days has passed so far
//Arguments: N/A | Returns: int
//Preconditions: month and day values are positive ints
int extDateType :: daysPassed(){
	int total = 0;
	for(int i = 1; i < getMonth(); i++)
		total += numDays(i);
	return total + getDay();
}

//daysRemaining(): returns days left in the year
//Arguments: N/A | Returns: int
//Preconditions: values used to calculate are positive ints
int extDateType :: daysRemaining(){
	return 365 - daysPassed();
}

//print(): prints the date in month, day year
//Arguments: N/A | Returns: void
//Preconditions: values should be positive ints
void extDateType :: print(){
	switch(getMonth()){
		case 1:
			cout << "January ";
			break;
		case 2:
			cout << "February ";
			break;
		case 3:
			cout << "March ";
			break;
		case 4:
			cout << "April ";
			break;
		case 5:
			cout << "May ";
			break;
		case 6:
			cout << "June ";
			break;
		case 7:
			cout << "July ";
			break;
		case 8:
			cout << "August ";
			break;
		case 9:
			cout << "September ";
			break;
		case 10:
			cout << "October ";
			break;
		case 11:
			cout << "November ";
			break;
		case 12:
			cout << "December ";
			break;
		default:
			cout << "January ";
	}
	cout << getDay() << ", " << getYear();
}
