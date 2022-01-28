//*****************
//Program Name: Lab3.3 - Operator Overloading
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: demonstrating the concept of operator overloading
//*****************
#include <iostream>
#include "Box.h"
using namespace std;

int main() {
	//creating boxes
	Box box1(2, 8, 3), box2(3.5, 2.5, 4.0), box3(4.25, 7.4, 6), box4(2, 4, 6);

	//printing boxes volumes to compare
	cout << "Volume of box #1: " << box1.volume() << "\n";
	cout << "Volume of box #2: " << box2.volume() << "\n";
	cout << "Volume of box #3: " << box3.volume() << "\n";
	cout << "Volume of box #4: " << box4.volume() << "\n";
	cout << "--------------------------\n";

	//Testing Overloading Operators
	cout << "\nTesting Equality:\n";
	cout << "Testing if box1 = box2: " << boolalpha << (box1 == box2) << "\n";
	cout << "Testing if box2 = box3: " << (box2 == box3) << "\n";
	cout << "Testing if box1 = box4: " << (box1 == box4) << "\n";

	cout << "\nTesting (volume) greater than:\n";
	cout << "Testing if box1 > box2: " << (box1 > box2) << "\n";
	cout << "Testing if box2 > box3: " << (box2 > box3) << "\n";

	cout << "\nTesting (volume) less than:\n";
	cout << "Testing if box2 < box4: " << (box2 < box4) << "\n";
	cout << "Testing if box3 < box2: " << (box3 < box2) << "\n";

	cout << "\nTesting (all dimensions) greater than:\n";
	cout << "Testing if box1 >= box2: " << (box1 >= box2) << "\n";
	cout << "Testing if box2 >= box3: " << (box3 >= box2) << "\n";

	cout << "\nTesting (all dimensions) less than:\n";
	cout << "Testing if box2 <= box1: " << (box2 <= box1) << "\n";
	cout << "Testing if box2 <= box3: " << (box2 <= box3) << "\n";

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
}
