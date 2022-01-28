/*
 * Box.cpp
 *
 *  Created on: Feb 2, 2021
 *      Author: cc
 */
#include "Box.h"
#include <iostream>
using namespace std;

//volume(): calculates volume
//Arguments: N/A | Returns: double
//Preconditions: N/A
double Box :: volume(){
	if(getLength() >= 0 && getWidth() >= 0 && getHeight() >= 0)
		return (getLength() * getWidth() * getHeight());
	else
		return 0;
}

//operator==(): checks if volumes are the same
//Arguments: b (Box) | Returns: bool
//Preconditions: N/A
bool Box :: operator==(Box b)
	{return volume() == b.volume();}

//operator>(): checks if one volume is greater than the other
//Arguments: b (Box) | Returns: bool
//Preconditions: N/A
bool Box :: operator>(Box b)
	{return volume() > b.volume();}

//operator<(): checks if one volume is less than the other
//Arguments: b (Box) | Returns: bool
//Preconditions: N/A
bool Box :: operator<(Box b)
	{return volume() < b.volume();}

//operator>=(): checks if all three dimensions of box1 are
//				greater than corresponding dimensions of box2.
//Arguments: b (Box) | Returns: bool
//Preconditions: N/A
bool Box :: operator>=(Box b){
	return(getLength() > b.getLength() && getWidth() > b.getWidth() && getHeight() > b.getHeight());
}

//operator<=(): same as above but less than
//Arguments: b (Box) | Returns: bool
//Preconditions: N/A
bool Box :: operator<=( Box b){
	return(getLength() < b.getLength() && getWidth() < b.getWidth() && getHeight() < b.getHeight());
}
