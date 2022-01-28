//*****************
//Program Name: Lab 11.3 - Stack ADT Overloading ==
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Add to the Stack ADT by adding a method that will overload the equality operator (==)
//*****************
#include <iostream>
#include "stackType.h"
using namespace std;

int main() {
	stackType<int> s1(3), s2(3), s3(4), s4(4);
	s1.push(4);
	s1.push(5);
	s1.push(6);

	s2.push(4);
	s2.push(5);
	s2.push(6);

	s3.push(1);
	s3.push(9);
	s3.push(2);
	s3.push(3);

	s4.push(4);
	s4.push(5);
	s4.push(6);

	cout << "Checking if s1 == s2: " << (s1 == s2) << endl;
	cout << "Checking if s1 == s3: " << (s1 == s3) << endl;
	cout << "Checking if s2 == s4: " << (s2 == s4) << endl;
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
