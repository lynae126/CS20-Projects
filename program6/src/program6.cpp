//============================================================================
// Name        : program6.cpp
// Author      : Clarissa Cheung
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include "stockList.h"

using namespace std;

void getData(stockList&);

int main() {

    //declarations
    stockList stockList;
    freopen("error.txt", "w", stderr);
    cout << fixed << setprecision(2) << showpoint;

    getData(stockList);        //read external file data into stockList
    stockList.sortStockList(); //sorts stockList and generates indexByGain
    stockList.printBySymbol(); //prints alphabetically by symbol
    stockList.printByGain();   //prints high-to-low low by gain



    return 0;
}

void getData(stockList& list)
{
    ifstream file;
    file.open("stockData.txt");
    stock stock;

    if(file.is_open())
    {
        while(file >> stock)
        {
            list.insert(stock);
        }
    }
    else
        cerr << "Cannot open file";
    file.close();
}

