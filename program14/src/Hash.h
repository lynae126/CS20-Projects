/*
 * Hash.h
 *
 *  Created on: May 1, 2021
 *      Author: cc
-----------------------------------
			   Hash
-----------------------------------
- buckets : int
- hashtable : list<int>
-----------------------------------
+ Hash (int a)
+ operator[](int index) : int
+ search_element (int key) : int
+ getBuckets()const : int
+ insert_element (int key) : void
-----------------------------------
*/
#ifndef HASH_H_
#define HASH_H_
#include <iostream>
#include <list>
using namespace std;

class Hash{
    private:
        int buckets;           // # buckets
        list<int> hashtable;  // container
    public:
        //Hash(): constructor sets buckets variable
        //Arguments: a (int) | Returns: N/A
        Hash (int a) { buckets = a; }

        //getBuckets(): returns number of elements
        //Arguments: N/A | Returns: buckets (int)
        int getBuckets()const { return buckets; }

        //insert_element(): sets the list with values
        //Arguments: key (int) | Returns: void
        void insert_element (int key){
        	buckets++;
            hashtable.push_back(key);
        }

        //search_element(): searches for given element and returns amount of comparisons made
        //Arguments: key (int) | Returns: count (int)
        int search_element (int key){
            // add code for your count of key comparisons
        	int count = 0;
            list<int>::iterator i = hashtable.begin();
            for (; i != hashtable.end(); i++){
                if (*i == key){
                	count++;
                	break;
                }
            }
           return count;
         }

        //operator[](): returns the element at given index
        //Arguments: index (int) | Returns: *it (int)
        int operator[](int index){
        	list<int>::iterator it = hashtable.begin();
			for(int i = 0; i < index; i++){
				++it;
			}
			return *it;
        }
};
#endif /* HASH_H_ */
