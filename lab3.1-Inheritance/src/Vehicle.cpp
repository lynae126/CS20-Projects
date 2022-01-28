/*
 * Vehicle.cpp
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
 */
#include "Vehicle.h"
#include <iostream>
using namespace std;

//setYear(): sets the year the vehicle was bought
//Arguments: n (int) | Returns: void
//Preconditions: amount is a valid, positive integer
void Vehicle :: setYear(int n)
	{n >= 0 ? year = n : year = 0;}

//getYear(): returns the year of the car
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Vehicle :: getYear()const
	{return year;}

//setMileage(): sets the mileage of the vehicle
//Arguments: m (int) | Returns: void
//Preconditions: amount is a valid, positive integer
void Vehicle :: setMileage(int m)
	{m >= 0 ? mileage = m : mileage = 0;}

//getMileage(): returns the mileage of the car
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Vehicle :: getMileage()const
	{return mileage;}

//print(): prints out all the data on the vehicle
//Arguments: N/A | Returns: void
//Preconditions: N/A
void Vehicle :: print(){
	cout << "Year: " << year << "\nMileage: " << mileage << "\n";
}
