/*
 * stock.h
 *
 *  Created on: Feb 22, 2021
 *      Author: cc
 */




#ifndef Stock_h
#define Stock_h

#include <stdio.h>
#include <fstream>
#include <ostream>
#include <iomanip>

using namespace std;

class stock
{
    friend ifstream& operator>> (ifstream&, stock&);
    friend ostream& operator<< (ostream&, const stock&);
private:
    string symbol;
    double openPrice;
    double closePrice;
    double todayHigh;
    double todayLow;
    double prevClose;
    int volume;
public:
    //constructors
    stock() {symbol = ""; openPrice = 0.0; closePrice = 0.0; todayHigh = 0.0; todayLow = 0.0; prevClose = 0.0; volume = 0; };
    stock(string s, double oP, double cP, double tH, double tL, double pC, int v)
        { setStockInfo(s, oP, cP, tH, tL, pC, v); };
    //getters
    string getSymbol() { return symbol; };
    int getVolume() { return volume; };
    double getOpenPrice() { return openPrice; };
    double getClosePrice() { return closePrice; };
    double getTodayHight() { return todayHigh; };
    double getTodayLow() { return todayLow; };
    double getPrevClose() { return prevClose; };
    //other method functions
    double percentGainLoss() const
        { return (closePrice - prevClose) / prevClose * 100; };
    bool operator<(stock s) { return symbol < s.symbol; };
    void setStockInfo(string s, double oP, double cP, double tH, double tL, double pC, int v)
        { symbol = s; openPrice = oP; closePrice = cP; todayHigh = tH; todayLow = tL; prevClose = pC; volume = v; };
    double dailyAsset() { return closePrice * volume; };
};

#endif /* Stock_h */

