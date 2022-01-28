/*
 * stockList.h
 *
 *  Created on: Feb 22, 2021
 *      Author: cc
 */

#ifndef stockList_h
#define stockList_h
#include "stock.h"

#include <stdio.h>
#include <iostream>

class stockList
{
private:
    deque<int> indexByGain;
    deque<stock> list;
public:
    //I honestly don't know if I need to explicitly
    //include constructors and a destructor
    void insert(stock item){list.push_back(item);};
    void sortStockList();
    void printBySymbol();
    void printByGain();
    void print();
};

#endif /* stockList_h */
