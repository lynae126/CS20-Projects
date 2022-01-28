/*
 * Sedan.cpp
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
 */
#include "Sedan.h"
#include <iostream>
using namespace std;

Sedan :: Sedan(int y, int m, int d, bool hb): Vehicle(y, m){
	doors = d;
	hatchback = hb;
}

//setDoors(): sets the door private instance member
//Arguments: d (int) | Returns: void
//Preconditions: d must be a positive integer
void Sedan :: setDoors(int d)
	{d >= 0 ? doors = d : doors = 0;}

//getDoors(): return the amount of doors on a car
//Arguments: N/A | Returns: int
//Preconditions: N/A
int Sedan :: getDoors()const
	{return doors;}

//setHatchback(): sets the hatchback private instance member
//Arguments: hb (bool) | Returns: void
//Preconditions: amount must be a bool value(either false or true)
void Sedan :: setHatchback(bool hb){
	if(hb == false || hb == true)
		hatchback = hb;
	else
		hatchback = false;
}

//getHatchback(): return if the car is a hatchback or not
//Arguments: N/A | Returns: bool
//Preconditions: N/A
bool Sedan :: getHatchback()const
	{return hatchback;}

//printVehicle(): prints out all the data on the car
//Arguments: N/A | Returns: void
//Preconditions: N/A
void Sedan :: printVehicle(){
	print();
	if(this->getHatchback() == true)
		cout << "Doors: " << doors << "\nHatchback: yes" << "\n\n";
	else
		cout << "Doors: " << doors << "\nHatchback: no" << "\n\n";
}
