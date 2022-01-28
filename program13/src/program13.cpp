//*****************
//Program Name: Program 13
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Write a new QueueADT method named "moveToFront(int)"
//*****************
#include <iostream>
#include <stdlib.h>
#include "queueType.h"
using namespace std;

int main() {
	queueType<int> list;
	srand(time(0));
	int num = 0, random = 0, idx = 0, size = 0;
	for(int i = 0; i < 10; i++){
		random = rand() % 100 + 1;
		list.addQueue(random);
	}
	cout << "Orginal Queue:\n";
	list.printQueue();

	for(int i = 1; i < 11; i++){
		cout << "Operation #" << i << ": ";
		random = rand() % 100 + 1;
		num = rand() % 100 + 1;
		idx = rand() % list.getSize() + 1;

		if(random >= 0 && random < 46) {
			cout << "Add random number to the queue (" << num << ")\n";
			list.addQueue(num);
			list.printQueue();
		} else if(random < 91) {
			cout << "Delete queue front (" << list.front() << ")\n";
			list.deleteQueue();
			list.printQueue();
		} else {
			cout << "Move random element to front\n";
			cout << "Randomly selected element " << idx << " (" << list.get_element_at(idx) << ") to move to front\n";
			list.moveToFront(idx);
			list.printQueue();
		}
	}
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
