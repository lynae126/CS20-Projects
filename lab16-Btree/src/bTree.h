#ifndef H_bTree
#define H_bTree
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

template <class recType, int bTreeOrder>
struct bTreeNode{
    int recCount;
    recType list[bTreeOrder - 1];
    bTreeNode *children[bTreeOrder];
};

/*-----------------------------------
		linkedListIterator
-----------------------------------
- searchNode(bTreeNode<recType, bTreeOrder>,
  const recType&, bool&, int&) : void
- insertBTree(bTreeNode<recType, bTreeOrder>,
  const recType&, recType&, bTreeNode<recType,
  bTreeOrder>*, bool&) : void
- insertNode(bTreeNode<recType, bTreeOrder>,
  const recType&, bTreeNode<recType,
  bTreeOrder>*, int): void
- splitNode (bTreeNode<recType, bTreeOrder>,
  const recType&, bTreeNode<recType, bTreeOrder>*,
  int, bTreeNode<recType, bTreeOrder>*, recType) : void
- recInorder(bTreeNode<recType, bTreeOrder>) : void
-----------------------------------
# *root : bTreeNode<recType, bTreeOrder>
-----------------------------------
+ search(const recType& searchItem) : bool
+ insert(const recType& insertItem) : void
+ inOrder() : void
+ bTree()
-----------------------------------
*/
template <class recType, int bTreeOrder>
class bTree{
	private:
		void searchNode(bTreeNode<recType, bTreeOrder> *current, const recType& item, bool& found, int& location);
		void insertBTree(bTreeNode<recType, bTreeOrder> *current, const recType& insertItem, recType& median, bTreeNode<recType, bTreeOrder>* &rightChild, bool& isTaller);
		void insertNode(bTreeNode<recType, bTreeOrder> *current, const recType& insertItem, bTreeNode<recType, bTreeOrder>* &rightChild, int insertPosition);
		void splitNode (bTreeNode<recType, bTreeOrder> *current, const recType& insertItem, bTreeNode<recType, bTreeOrder>* rightChild, int insertPosition, bTreeNode<recType, bTreeOrder>* &rightNode, recType &median);
		void recInorder(bTreeNode<recType, bTreeOrder> *current);

	protected:
		bTreeNode<recType, bTreeOrder> *root;

	public:
		//Function to determine if searchItem is in the B-tree.
		//Postcondition: Returns true if searchItem is found in the
		//    B-tree; otherwise, returns false.
		bool search(const recType& searchItem);
		//Function to insert insertItem in the B-tree.
		//Postcondition: If insertItem is not in the the B-tree, it
		//    is inserted in the B-tree.
		void insert(const recType& insertItem);
		//Function to do an inorder traversal of the B-tree.
		void inOrder();
		bTree(); //constructor
};

//bTree(): constructor
//Arguments: N/A | Returns: N/A
template <class recType, int bTreeOrder>
bTree<recType, bTreeOrder>::bTree()
	{ root = nullptr; }

//search(): searches for given element
//Arguments: searchItem(const recType&) | Returns: bool
template <class recType, int bTreeOrder>
bool bTree<recType, bTreeOrder>::search(const recType& searchItem){
    bool found = false;
    int location;
    bTreeNode<recType, bTreeOrder> *current = root;

    while (current && !found){
        searchNode(current, searchItem, found, location);
        if (!found)
            current = current->children[location];
    }
    return found;
} //end search

//searchNode(): searches for a node in tree
//Arguments:*current(bTreeNode<recType, bTreeOrder>), item(const recType&), found(bool&), location(int&)| Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::searchNode
                   (bTreeNode<recType, bTreeOrder> *current,
                    const recType& item,
                    bool& found, int& location){
    int first = 0, last = current->recCount - 1;
    found = false;

    while (first <= last && ! found){
        location = (first + last) / 2;
        if (item == current->list[location])
            found = true;
        else if (item < current->list[location])
            last = location - 1;
        else
            first = location + 1;
    }

    if (!found)
        if (item >= current->list[location])
            location++;
}

//insert(): inserts element into tree
//Arguments: insertItem(const recType&) | Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insert(const recType& insertItem){
    bool isTaller = false;
    recType median;
    bTreeNode<recType, bTreeOrder> *rightChild;
    insertBTree(root, insertItem, median,
                rightChild, isTaller);
    if (isTaller){ //the tree is initially empty or the root was split by the function insertBTree
        bTreeNode<recType, bTreeOrder> *tempRoot;
        tempRoot = new bTreeNode<recType, bTreeOrder>;
        tempRoot->recCount = 1;
        tempRoot->list[0] = median;
        tempRoot->children[0] = root;
        tempRoot->children[1] = rightChild;
        root = tempRoot;
    }
}

//insertBTree(): inserts btree
//Arguments: *current(bTreeNode<recType, bTreeOrder>),insertItem(const recType&),
//			 median(recType&), &rightChild(bTreeNode<recType, bTreeOrder>*), isTaller(bool&)
//Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insertBTree
                   (bTreeNode<recType, bTreeOrder> *current,
                    const recType& insertItem,
                    recType& median,
                    bTreeNode<recType, bTreeOrder>* &rightChild,
                    bool& isTaller){
    int position;
    isTaller = false;
    if (!current){
        median = insertItem;
        rightChild = nullptr;
        isTaller = true;
    } else {
        bool found;
        searchNode(current, insertItem, found, position);
        if (found)
            cout << "Cannot insert duplicate record: " << insertItem << endl;
        else{
            recType newMedian;
            bTreeNode<recType, bTreeOrder> *newChild;
            insertBTree(current->children[position], insertItem, newMedian, newChild, isTaller);

            if (isTaller){
                if (current->recCount < bTreeOrder - 1){
                    isTaller = false;
                    insertNode(current, newMedian,newChild, position);
                } else
                    splitNode(current, newMedian, newChild, position, rightChild, median);
            }
        }
    }
}

//insertNode(): inserts node into btree
//Arguments: *current(bTreeNode<recType, bTreeOrder>),insertItem(const recType&)
//			 &rightChild(bTreeNode<recType, bTreeOrder>*), insertPosition(int)
//Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::insertNode
                   (bTreeNode<recType, bTreeOrder> *current,
                    const recType& insertItem,
                    bTreeNode<recType, bTreeOrder>* &rightChild,
                    int insertPosition){
    int index;
    for (index = current->recCount; index > insertPosition; index--){
        current->list[index] = current->list[index - 1];
        current->children[index + 1] = current->children[index];
    }

    current->list[index] = insertItem;
    current->children[index + 1] = rightChild;
    current->recCount++;
} //end insertNode

//splitNode(): splits node
//Arguments: *current(bTreeNode<recType, bTreeOrder>),insertItem(const recType&)
//			 rightChild(bTreeNode<recType, bTreeOrder>*), insertPosition(int)
//			 &rightNode(bTreeNode<recType, bTreeOrder>*), &median(recType)
//Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::splitNode
                   (bTreeNode<recType, bTreeOrder> *current, const recType& insertItem,
                    bTreeNode<recType, bTreeOrder>* rightChild, int insertPosition,
                    bTreeNode<recType, bTreeOrder>* &rightNode, recType &median){
    rightNode = new bTreeNode<recType, bTreeOrder>;
    int mid = (bTreeOrder - 1)  / 2;
    if (insertPosition <= mid){
        int index = 0;
        int i = mid;
        while (i < bTreeOrder - 1){
            rightNode->list[index] = current->list[i];
            rightNode->children[index + 1] = current->children[i + 1];
            index++;
            i++;
        }
        current->recCount = mid;
        insertNode(current, insertItem, rightChild, insertPosition);
        (current->recCount)--;
        median = current->list[current->recCount];
        rightNode->recCount = index;
        rightNode->children[0] = current->children[current->recCount+1];
    } else {
        int i = mid + 1;
        int index = 0;
        while (i < bTreeOrder - 1){
            rightNode->list[index] = current->list[i];
            rightNode->children[index + 1] =
                                  current->children[i+1];
            index++;
            i++;
        }
        current->recCount = mid;
        rightNode->recCount = index;
        median = current->list[mid];
        insertNode(rightNode, insertItem, rightChild, insertPosition - mid - 1);
        rightNode->children[0] = current->children[current->recCount+1];
    }
}

//inOrder(): prints out the children in given root
//Arguments: N/A | Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::inOrder()
	{ recInorder(root); } // end inOrder

//recInorder(): prints out each child after current node
//Arguments: *current(bTreeNode<recType, bTreeOrder>) | Returns: void
template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::recInorder
                     (bTreeNode<recType, bTreeOrder> *current){
    if (current){
        recInorder(current->children[0]);
        for (int i = 0; i < current->recCount; i++){
            cout << setw(5)<<current->list[i] << " ";
            recInorder(current->children[i+1]);
            if((i+1) % 10 == 0)
             	cout << endl;
            /*
             * I have no idea how to fix this, but it seems that whenever
             * I get a duplicate record, the middle line doesn't get a new line,
             * throwing off the format of the columns
             */
        }
    }

} //end recInorder

#endif
