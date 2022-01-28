//*****************
//Program Name: Program 5 (Extended ArrayList Class)
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Extending arrayListType to include new features
//*****************
#include <iostream>
#include <iomanip>
#include "arrayListType.h"
#include "extArrayListType.h"
using namespace std;
const int SIZE = 50;

int main() {
	srand(time(0));
	extArrayListType<int> extArrayList(SIZE);
	/* I didn't use input validation in my classes
	 * to fill up my list instead because I would
	 * need another value to replace the duplicated
	 * values and I didn't want to just add a random
	 * number in there. Just defaulting it to 0
	 * wouldn't have worked because eventually there
	 * will be other duplicates, and if I did 0 every time,
	 * then 0 would have been the duplicated value, so I put
	 * the input validation in the main.cpp.
	 */
	for(int i = 0; i < 40; i++){
		int num = (rand() % 100 + 1);
		while(extArrayList.seqSearch(num) != -1)
			num = (rand() % 100 + 1);
		extArrayList.insert(num);
	}
	cout << "The list created for you is: \n";
	extArrayList.print();
	cout << "Min: " << extArrayList.min() << endl;
	cout << "Max: " << extArrayList.max() << "\n\n";

	int del = 0;
	cout << "Enter the position of item to be deleted: ";
	cin >> del;
	cout << "After removing element at " << del << ", the list is:\n";
	extArrayList.removeAt(del);
	extArrayList.print();
	cout << "\nMin: " << extArrayList.min() << endl;
	cout << "Max: " << extArrayList.max() << "\n\n";

	cout << "Inserting 999 into three locations: \n";
	extArrayList.insertAt(5, 999);
	extArrayList.insertAt(12, 999);
	extArrayList.insertAt(32, 999);
	extArrayList.print();
	cout << "\nMin: " << extArrayList.min() << endl;
	cout << "Max: " << extArrayList.max() << endl;

	cout << "\nEnter a value; all instances will be removed: ";
	cin >> del;
	cout << "After removing all instances of element " << del << ", the list is:\n";
	extArrayList.removeAll(del);
	extArrayList.print();
	cout << "\nMin: " << extArrayList.min() << endl;
	cout << "Max: " << extArrayList.max() << endl;
	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
