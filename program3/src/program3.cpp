//*****************
//Program Name: Program 3 (Extended DateType)
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: take a base class, dateType, and create an
//extended class, extDateType that adds to its features and functionality
//*****************
#include <iostream>
using namespace std;
#include "dateType.h"
#include "extDateType.h"

int main() {
	dateType d1(4,5,1994), d2(10,25,2014);
	extDateType e1(6, 9, 2010), e2(1, 10, 2000);

	cout << "Regular Dates\n---------------------\n";
	cout << "Date 1: ";
	d1.printDate();
	cout << "\nDate 2: ";
	d2.printDate();

	cout << "\n\nExtended Dates\n---------------------\n";
	cout << "Date 3: ";
	e1.print();
	cout << "\nLeap Year: "<< boolalpha << e1.isLeapYear() << "\n";
	cout << "Days Passed: " << e1.daysPassed() << "\n";
	cout << "Days Remaining: " << e1.daysRemaining() << "\n";
	cout << "\nDate 4: ";
	e2.print();
	cout << "\nLeap Year: "<< boolalpha << e2.isLeapYear() << "\n";
	cout << "Days Passed: " << e2.daysPassed() << "\n";
	cout << "Days Remaining: " << e2.daysRemaining() << "\n";

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
