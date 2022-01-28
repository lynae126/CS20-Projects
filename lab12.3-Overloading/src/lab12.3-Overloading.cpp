//*****************
//Program Name: Lab 12.3 - Stack ADT Overloading ==
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Add to the Stack ADT by adding a method that will overload the equality operator (==)
//*****************
#include <iostream>
#include "stackType.h"
using namespace std;

int main() {
	cout << "Created stack1:\n";
	stackType<int> stack1(6);
	int size = 0, num = 0;
	while(size != 6){
		cin >> num;
		stack1.push(num);
		size++;
	}

	cout << "\nCreated stack2 using assignment.\n";
	stackType<int> stack2 = stack1;
	if(stack1 == stack2)
		cout << "stack1 and stack2 are identical\n";
	else
		cout << "stack1 and stack2 are not identical\n";
	cout << "Stack 1's top is: " << stack1.top() << endl;
	cout << "Stack 2's top is: " << stack2.top() << endl;

	cout << "\nAfter push and pop operations on stack2...\n";
	stack2.pop();
	stack2.pop();
	stack2.push(24);
	if(stack1 == stack2)
		cout << "stack1 and stack2 are identical\n";
	else
		cout << "stack1 and stack2 are not identical\n";

	cout << "\nAfter another push operation on stack2...\n";
	stack2.push(3);
	if(stack1 == stack2)
		cout << "stack1 and stack2 are identical\n";
	else
		cout << "stack1 and stack2 are not identical\n";

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
