//*****************
//Program Name: Lab 3.1 - Inheritance
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: example of inheritance in classes
//*****************
#include <iostream>
#include "Vehicle.h"
#include "Sedan.h"
using namespace std;

int main() {
	//creating vehicle and sedan objects
	Vehicle v1(1992, 40000), v2(1993, 36000);
	Sedan s1(1994, 50500, 4, true), s2(1995, 40500, 4, false);

	//printing out the objects' data
	cout << "Information about Vehicle 1: 'Motor Vehicle'\n";
	v1.print();
	cout << "\nInformation about Sedan 1: 'Yaris'\n";
	s1.printVehicle();
	cout << "------------------------\n\n";
	cout << "Information about Vehicle 2: 'Sport Utility Vehicle'\n";
	v2.print();
	cout << "\nInformation about Sedan 2: 'Sonata'\n";
	s2.printVehicle();
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
}
