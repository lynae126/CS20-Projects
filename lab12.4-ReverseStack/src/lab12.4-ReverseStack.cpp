//*****************
//Program Name: Lab 12.4 - Stack ADT Reverse Stack
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: add to the Stack ADT with a method that will make a reverse copy of a target stack
//*****************
#include <iostream>
#include "stackType.h"
using namespace std;
const int size = 7;

int main() {
	cout << "The original stack1:\n";
	stackType<int> stack1(size);
	int num;
	for(int i = 0; i < size; i++){
		cin >> num;
		stack1.push(num);
	}

	cout << "\nstack2 which is a reverse copy of stack1:\n";
	stackType<int> stack2(7);
	stack2.reverseStack(stack1);

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
