#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <cassert>
#include "binaryTree.h"
using namespace std;
/*
-----------------------------------
		bSearchTreeType
-----------------------------------
- deleteFromTree(binaryTreeNode<elemType>* &p) : void
-----------------------------------
+ search(const elemType& searchItem) const : bool
+ insert(const elemType& insertItem) : void
+ deleteNode(const elemType& deleteItem) : void
+ returnNode(elemType) : elemType*
-----------------------------------
*/
template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>{
	private:
		//Function to delete the node to which p points is deleted
		//from the binary search tree.
		//Postcondition: The node to which p points is deleted from
		//    the binary search tree.
		void deleteFromTree(binaryTreeNode<elemType>* &p);
	public:
		//Function to determine if searchItem is in the binary
		//search tree.
		//Postcondition: Returns true if searchItem is found in the
		//    binary search tree; otherwise, returns false.
		bool search(const elemType& searchItem) const;
		//Function to insert insertItem in the binary search tree.
		//Postcondition: If no node in the binary search tree has the
		//    same info as insertItem, a node with the info insertItem
		//     is created and inserted in the binary search tree.
		void insert(const elemType& insertItem);
		//Function to delete deleteItem from the binary search tree
		//Postcondition: If a node with the same info as deleteItem
		//    is found, it is deleted from the binary search tree.
		void deleteNode(const elemType& deleteItem);
		//Function to return a pointer to a found item in the tree
		//Postcondition: if the node is found a pointer is returned,
		//     otherwise a nullptr is returned.
		elemType* returnNode(elemType);
};

template <class elemType>
elemType* bSearchTreeType<elemType>::returnNode(elemType num){
    binaryTreeNode<elemType> *nodePtr = this->root;
    while (nodePtr)
        if (nodePtr->info == num)
            return &nodePtr->info;
        else if (num < nodePtr->info)
            nodePtr = nodePtr->llink;
        else
            nodePtr = nodePtr->rlink;
    return nullptr;
}

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const{
    binaryTreeNode<elemType> *current;
    bool found = false;

    if (this->root == nullptr)
       cerr << "Cannot search the empty tree." << endl;
    else{
        current = this->root;
        while (current != nullptr && !found){
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->llink;
            else
                current = current->rlink;
        }
    }
    return found;
}

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem){
    binaryTreeNode<elemType> *current;  //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *newNode;  //pointer to create the node

    newNode = new binaryTreeNode<elemType>;
    assert(newNode != nullptr);
    newNode->info = insertItem;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;

    if (this->root == nullptr)
        this->root = newNode;
    else{
        current = this->root;
        while (current != nullptr){
            trailCurrent = current;
            if (current->info == insertItem){
                cerr << "The insert item is already in the list-\n";
                return;
            } else if (current->info > insertItem)
                current = current->llink;
            else
                current = current->rlink;
        }
        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem){
    binaryTreeNode<elemType> *current;  //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == nullptr)
        cout << "Cannot delete from the empty tree." << endl;
    else {
        current = this->root;
        trailCurrent = this->root;

        while (current != nullptr && !found){
            if (current->info == deleteItem)
                found = true;
            else {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }

        if (current == nullptr)
            cout << "The delete item is not in the tree." << endl;
        else if (found){
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }
    }
}

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType>* &p){
    binaryTreeNode<elemType> *current; //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent;   //pointer behind current
    binaryTreeNode<elemType> *temp;        //pointer to delete the node

    if (p == nullptr)
        cerr << "Error: The node to be deleted is nullptr." << endl;
    else if(p->llink == nullptr && p->rlink == nullptr){
        temp = p;
        p = NULL;
        delete temp;
    } else if(p->llink == nullptr) {
        temp = p;
        p = temp->rlink;
        delete temp;
    } else if(p->rlink == nullptr) {
        temp = p;
        p = temp->llink;
        delete temp;
    } else {
        current = p->llink;
        trailCurrent = nullptr;

        while (current->rlink != nullptr){
            trailCurrent = current;
            current = current->rlink;
        }

        p->info = current->info;
        if (trailCurrent == nullptr) //current did not move current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;

        delete current;
    }
}
#endif
