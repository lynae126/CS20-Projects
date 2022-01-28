/*
 * stockList.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: cc
 */


#include "stockList.h"

bool compare(const stock &a, const stock &b) //comparator
{ return a.percentGainLoss() > b.percentGainLoss(); }

bool compareSymbol(stock a, stock b)
{ return (a < b); };

void stockList:: sortStockList(){
    if(list.size()>0){
        //temp container to store the percentages to compare and create the indexByGain deque
        string *temp = new string[list.size()];
        for(int i = 0; i < list.size(); ++i)
        temp[i] = list[i].getSymbol();
        sort(list.begin(), list.end(), compare); //sort by comparing the gain/loss value
        while(indexByGain.size() != list.size()) //while indexByGain isn't filled up
        for(int i = 0; i < list.size(); ++i)
        if(list[i].getSymbol() == temp[i]) //if the content of the newly sorted list index matches the orignial, add that index to indexByGain
        indexByGain[i] = i;
        delete[] temp; //take out temp container
    }//else
    //cerr << "Your deque isn't initialized.\n";//supposedly gives an error

}

void stockList::printBySymbol()
{

    cout << "********* Financial Report **********\n"; //regularly print out
    cout << "Stock Today Previous Percent\nSymbol Open Close High Low Close Gain Volume\n";
    cout << "------ ---- ----- ---- --- ----- ---- ------\n";
    //for every stock object, would look through all objects, and if the symbol
    //matches, print out the objects according to how its ordered in temp

    deque<stock> copyList(list);
    sort(copyList.begin(), copyList.end(), compareSymbol);
    for(auto it = copyList.begin(); it != copyList.end(); it++)
    {
        cout << *it;
    }
}

void stockList::printByGain(){

    cout << "********* Gain/Loss Report **********\n";
    //since indexByGain stores indexes, this takes each element in
    //indexByGain and prints out the stock objects in the order specified
    for(auto it = indexByGain.begin(); it != indexByGain.end(); ++it){
        cout << *it;
    }
}
