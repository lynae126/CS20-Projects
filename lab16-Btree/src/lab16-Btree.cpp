//*****************
//Program Name: Lab 16 - B Tree
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Write a simple driver program that will demonstrate various options on a B-Tree.
//*****************
#include <iostream>
#include <stdlib.h>
#include "bTree.h"
using namespace std;

int main() {
	srand(time(0));
	bTree<int , 100> tree;
	for(int i = 0; i < 100; i++){
		tree.insert(rand()%10000);
	}
	cout << "\nIn order traversal:\n";
	tree.inOrder();
	cout << "\n\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
