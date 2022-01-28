//*****************
//Program Name: Program 16 (BST with Objects)
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: implementing a btree with objects as elements
//*****************
#include <iostream>
#include "Actor.h"
#include "binarySearchTree.h"
using namespace std;

int main(){
    int num = 0;
    bSearchTreeType<Actor> tree;

    Actor wkr1(52521, "John Heard");
    tree.insert(wkr1);
    Actor wkr2(64815, "Reese Witherspoon");
    tree.insert(wkr2);
    Actor wkr3(81214, "Jennifer Garner");
    tree.insert(wkr3);
    Actor wkr4(44266, "Sophia Loren");
    tree.insert(wkr4);
    Actor wkr5(33615, "Debbie Boone");
    tree.insert(wkr5);
    Actor wkr6(33040, "George Carlin");
    tree.insert(wkr6);
    Actor wkr7(12841, "Ashley Judd");
    tree.insert(wkr7);
    Actor wkr8(94664, "Josh Groban");
    tree.insert(wkr8);

    //display actors
    cout << "List of actors:\n";
    tree.inorderTraversal();

    //get an ID number to search for
    cout << "\nEnter a union ID number to search for: ";
    cin >> num;
    Actor *p = tree.returnNode(num);
    if(tree.search(num))
    	cout << "Actor was found: " << p->getName()<< endl;
    else
    	cout << "Actor was not found: " << p->getName() << endl;
    cout << "\nNumber of tree nodes: " << tree.treeNodeCount() << endl;
    cout << "Number of tree leaves: " << tree.treeLeavesCount() << endl;
	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
