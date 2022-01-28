/*
 * dateType.cpp
 *
 *  Created on: Feb 5, 2021
 *      Author: cc
 */
#include "dateType.h"
#include <iostream>
using namespace std;

//setDate(): setting month, day, year
//Arguments: m(int), d(int), y(year) | Returns: void
//Preconditions: arguments are all positive integers
void dateType :: setDate(int m, int d, int y){
	setMonth(m);
	setDay(d);
	setYear(y);
}

//setDay(): setting day
//Arguments: d(int) | Returns: void
//Preconditions: argument is a positive integer
void dateType :: setDay(int d)
	{d >= 1 ? day = d : day = 0;}

//setMonth(): setting month
//Arguments: m(int) | Returns: void
//Preconditions: argument is a positive integer
void dateType :: setMonth(int m)
	{m >= 1 ? month = m : month = 0;}

//setYear(): setting year
//Arguments: y(int) | Returns: void
//Preconditions: argument is a positive integer
void dateType :: setYear(int y)
	{y >= 0 ? year = y : year = 0;}

//getDay(): returning day
//Arguments: N/A | Returns: int
//Preconditions: N/A
int dateType :: getDay() const
	{ return day; }

//getMonth(): returning month
//Arguments: N/A | Returns: int
//Preconditions: N/A
int dateType :: getMonth() const
	{ return month; }

//getYear(): returning year
//Arguments: N/A | Returns: int
//Preconditions: N/A
int dateType :: getYear() const
	{ return year; }

//printDate(): printing date in order M/D/Y
//Arguments: N/A | Returns: void
//Preconditions: N/A
void dateType :: printDate() const
	{cout << month << "/" << day << "/" << year;}
