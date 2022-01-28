//*****************
//Program Name: Program 14 - Search Analysis
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: testing the efficiency of a variety of search methods
//*****************
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "Hash.h"
using namespace std;
int recSeq(vector<int> test, int val, int low, int high);
int recBin(vector<int> test, int low, int high, int val);

int main() {
	srand(time(0));
	vector<int> test;
	cout << "Procedural Sequential Search" << endl;
	test.push_back(rand()%100);
	test.push_back(rand()%100);
	int num = test.size(), random;
	double count = 0;
	for(int i = 1; i < 14; i++){
		for(int i = 0; i < 1000; i++){
			random = rand()%num;
			for(int i = 0; i < num; i++){
				if(test[i] != test[random])
					count++;
				else
					break;
			}
		}
		cout << "n = " << num << " | pct = " << ((count/1000.0)/num)<< endl;
		for(int i = 0; i < num; i++)
			test.push_back(rand()%100);
		num = test.size();
	}

	test.clear();
	cout << "\n\nProcedural Binary Search" << endl;
	test.push_back(rand()%100);
	test.push_back(rand()%100);
	num = test.size();
	int low = 0, high = num, mid = (low+high)/2;
	count = 0;
	for(int i = 1; i < 14; i++){
		for(int i = 0; i < 1000; i++){
			random = rand()%num;
			while(low <= high){
				mid = (low+high)/2;
				count++;
				if(test[mid] == test[random])
					break;
				if(test[mid] < test[random])
					low = mid+1;
				if(test[mid] > test[random])
					high = mid-1;
				count++;
			}
		}
		cout << "n = " << num << " | pct = " << ((count/1000.0)/num)<< endl;
		for(int i = 0; i < num; i++)
			test.push_back(rand()%100);
		num = test.size();
	}

	test.clear();
	cout << "\n\nRecursive Sequential Search" << endl;
	test.push_back(rand()%100);
	test.push_back(rand()%100);
	num = test.size();
	count = 0;
	for(int i = 1; i < 14; i++){
		for(int i = 0; i < 1000; i++){
			random = rand()%num;
			count += recSeq(test, test[random], 0, num);
		}
		cout << "n = " << num << " | pct = " << ((count/1000.0)/num)<< endl;
		for(int i = 0; i < num; i++)
			test.push_back(rand()%100);
		num = test.size();
	}

	test.clear();
	cout << "\n\nRecursive Binary Search" << endl;
	test.push_back(rand()%100);
	test.push_back(rand()%100);
	num = test.size();
	count = 0;
	for(int i = 1; i < 14; i++){
		for(int i = 0; i < 1000; i++){
			random = rand()%num;
			count += recBin(test, 0, num, test[random]);
		}
		cout << "n = " << num << " | pct = " << ((count/1000.0)/num)<< endl;
		for(int i = 0; i < num; i++)
			test.push_back(rand()%100);
		num = test.size();
	}

	Hash hash(0);
	cout << "\n\nHashing" << endl;
	hash.insert_element(rand()%100);
	hash.insert_element(rand()%100);
	num = hash.getBuckets();
	count = 0;
	for(int i = 1; i < 14; i++){
		for(int i = 0; i < 1000; i++){
			random = rand()%num;
			count += hash.search_element(hash[random]);
		}
		cout << "n = " << num << " | pct = " << ((count/1000.0)/num)<< endl;
		for(int i = 0; i < num; i++)
			hash.insert_element(rand()%100);
		num = hash.getBuckets();
	}

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//recSeq(): returns the number of times there has been a comparison
//Arguments: test(vector<int>), index, val (int) | Returns: count(int)
int recSeq(vector<int> test, int val, int low, int high){
    if(high < 1)
    	return 0;
    if(test[low] == val)
    	return 1;
    if(test[high] == val)
    	return 1;
    return 2 + recSeq(test, val, low+1, high - 1);
}

//recBin(): returns the number of times there has been a comparison
//Arguments: test(vector<int>), low, high, val (int) | Returns: count(int)
int recBin(vector<int> test, int low, int high, int val){
	if(low <= high){
		int mid = (low + high) / 2;
		if(test[mid] == val)
			return 1;
		if(test[mid] > val)
			return 2 + recBin(test, low, mid-1, val);
		return 2 + recBin(test, mid+1, high, val);
	}
	return 0;
}
