/*
 * Date.cpp
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
 */
#include "Date.h"
#include <iostream>
using namespace std;

Date :: Date(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}

Date :: Date(const Date& d){
	month = d.getMonth();
	day = d.getDay();
	year = d.getYear();
}

//setMonth(): sets the month
//Arguments: m (int) | Returns: void
//Preconditions: amount is a valid, positive integer
void Date ::setMonth(int m)
	{m >= 0 ? month = m : month = 0;}

//getMonth(): returns month
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Date :: getMonth()const
	{return month;}

//setDay(): sets the day
//Arguments: d (int) | Returns: void
//Preconditions: amount is a valid, positive integer
void Date :: setDay(int d)
	{d >= 0 ? day = d : day = 0;}

//getDay(): returns day
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Date :: getDay()const
	{return day;}

//setYear(): sets the year
//Arguments: y (int) | Returns: void
//Preconditions: amount is a valid, positive integer
void Date :: setYear(int y)
	{y >= 0 ? year = y : year = 0;}

//getYear(): returns year
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Date :: getYear()const
	{return year;}

//print(): prints out the date in order of M/D/Y
//Arguments: N/A | Returns: void
//Preconditions: N/A
void Date :: print(){
	cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}
