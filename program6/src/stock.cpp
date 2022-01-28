/*
 * stock.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: cc
 */

#include "stock.h"


ifstream& operator>> (ifstream& inf, stock& stock)
{
    inf >> stock.symbol >> stock.openPrice >> stock.closePrice >> stock.todayHigh;
    inf >> stock.todayLow >> stock.prevClose >> stock.volume;
    return inf;
}

ostream& operator<< (ostream& os, const stock& stock)
{

    os << setw(6) << left << stock.symbol << setw(6) << right << stock.openPrice;
    os << setw(7) << stock.closePrice << setw(7) << stock.todayHigh << setw(7);
    os << stock.todayLow << setw(7) << stock.prevClose << setw(6);
    os << stock.stock::percentGainLoss() << "%" << setw(6) << stock.volume << endl;
    return os;
}
