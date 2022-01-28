//*****************
//Program Name: Lab 15.1 - Hashing
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: implement a hashing function
//*****************

#include <iostream>
#include <ctime>
#include "hashT.h"
using namespace std;

const int MAX_RAND = 1000, HT_SIZE = 19, SAMPLE_SIZE = 16;
void fillTable(int type, int num, int key, hashT<int> &table);
void deleteElm(int type, int num, int key, hashT<int> &table);
void search(int type, int num, int key, bool found, hashT<int> &table);
void insertElm(int type, int num, int key, hashT<int> &table);
int setKey(int type, int num);
int hashFunc(int num);
int truncationHash(int num);
int additiveHash(int num);
int XORhash(int num);

int main(){
	srand(time(0));
	hashT<int> table1(HT_SIZE); //trunctuation
	hashT<int> table2(HT_SIZE); //keyAverage
	hashT<int> table3(HT_SIZE);
	int num1, num2, num3;
	int key1, key2, key3;
	bool found1,found2, found3;

	cout << "\n__________________\n";
	cout << "Trunctuation\n__________________\n";
	fillTable(1, num1, key1, table1);
	deleteElm(1, num1, key1, table1);
	search(1, num1, key1, found1, table1);
	insertElm(1, num1, key1, table1);

    cout << "\n__________________\n";
    cout << "Additive Hash\n__________________\n";
    fillTable(2, num2, key2, table2);
    deleteElm(2, num2, key2, table2);
    search(2, num2, key2, found2, table2);
    insertElm(2, num2, key2, table2);

	cout << "\n__________________\n";
    cout << "XOR Hash\n__________________\n";
	fillTable(3, num3, key3, table3);
	deleteElm(3, num3, key3, table3);
	search(3, num3, key3, found3, table3);
	insertElm(3, num3, key3, table3);

    cout << "\n\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
    return 0;
}

//fillTable(): fills elements into table
//Arguments: type, num, key (int), &table (hashT<int>) | Returns: void
//Preconditions: N/A
void fillTable(int type, int num, int key, hashT<int> &table){
	cout << "Generating " << SAMPLE_SIZE << " integers....\n";
	for (int i = 0; i < SAMPLE_SIZE; i++){
		num = rand() % MAX_RAND;
		key = setKey(type, num);
		table.insert(key, num);
	}
	table.print();
}

//deleteElm(): deletes given element in table
//Arguments: type, num, key (int), &table (hashT<int>) | Returns: void
//Preconditions: N/A
void deleteElm(int type, int num, int key, hashT<int> &table){
	cout << "\nEnter item to be deleted: ";
	cin >> num;
	key = setKey(type, num);
	table.remove(key, num);
	table.print();
}

//search(): finds element in table
//Arguments: type, num, key (int), &table (hashT<int>), found(bool) | Returns: void
//Preconditions: N/A
void search(int type, int num, int key, bool found, hashT<int> &table){
	cout << "\nEnter item to be searched: ";
	cin >> num;
	key = setKey(type, num);
	table.search(key, num, found);
	if (found)
		cout << "Item found in the list" << endl;
	else
		cout << "Item not in the list." << endl;
}

//insertElm(): inserts input into table
//Arguments: type, num, key (int), &table (hashT<int>) | Returns: void
//Preconditions: N/A
void insertElm(int type, int num, int key, hashT<int> &table){
	cout << "\nEnter item to be inserted: ";
	cin >> num;
	key = setKey(type, num);
	table.insert(key, num);
	table.print();
}

//setKey(): returns val to set key to based on hash function specified
//Arguments: type, num (int) | Returns: int
//Preconditions: N/A
int setKey(int type, int num){
	switch(type){
		case 1:
			return truncationHash(num);
		case 2:
			return additiveHash(num);
		case 3:
			return XORhash(num);
		default:
			return hashFunc(num);
	}
}

//hashFunc(): simple hash func
//Arguments: num (int) | Returns: num (int)
//Preconditions: num >= 0
int hashFunc(int num)
	{ return num % HT_SIZE; }

//truncationHash(): takes first digit of given num
//found this from https://www.vidyarthiplus.com/vp/attachment.php?aid=11523
//Arguments: num (int) | Returns: n (int)
//Preconditions: num >= 0
int truncationHash(int num){
	int n = num;
	while(n >= 10)
		n = n / 10;
	return n;
}

//additiveHash(): adding the ascii value of all digits
//I thought of this when thinking of how to combine digits
//Arguments: num (int) | Returns: n (int)
//Preconditions: num >= 0
int additiveHash(int num){
	string number = to_string(num);
	int n = 0;
	for(auto it=number.begin(); it != number.end(); it++)
		n += *it;
	return n;
}

//XORhash(): uses xor to map key to value
//I also thought of this when thinking of how to combine digits
//Arguments: num (int) | Returns: val (int)
//Preconditions: num >= 0
int XORhash(int num){
	string number = to_string(num);
	int n = 0;
	for(auto it = number.begin(); it != number.end(); it++)
		n=n ^ *it;
	if(n < 0)
		n*=-1;
	return n;
}
