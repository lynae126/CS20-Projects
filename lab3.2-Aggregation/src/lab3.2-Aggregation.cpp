//*****************
//Program Name: Lab 3.2 - Aggregation
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: demonstrates the use of an object inside a class(agregation)
//*****************
#include <iostream>
#include "Date.h"
#include "Person.h"
using namespace std;

int main() {
	//creating date objects to pass to person objects as parameters
	Date d1(7,18, 2019), d2(2,9, 2018), d3(9,22, 2017);
	Person p1(562911461, d1);
	Person p2(832947149, d2);
	Person p3(538139472, d3);

	//printing out data of each person object
	cout << "Person 1\n-----------\n";
	p1.printPerson();
	cout << "Person 2\n-----------\n";
	p2.printPerson();
	cout << "Person 3\n-----------\n";
	p3.printPerson();
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
}
