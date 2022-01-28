/*
 * extDateType.h
 *
 *  Created on: Feb 5, 2021
 *      Author: cc
---------------------------------------
     extDateType: public dateType
---------------------------------------
^- month: int
^- day: int
^- year: int
---------------------------------------
^+ dateType(int = 1, int = 1, int = 1900)
^+ setDate(int, int, int): void
^+ setDay(int): void
^+ setMonth(int): void
^+ setYear(int): void
^+ getDay() const: int
^+ getMonth() const: int
^+ getYear() const: int
^+ printDate() const: void
 + extDateType(int, int, int)
 + isLeapYear(): bool
 + numDays(int): int
 + daysPassed(): int
 + daysRemaining(): int
 + print():void
---------------------------------------
 */
#ifndef EXTDATETYPE_H_
#define EXTDATETYPE_H_
#include "dateType.h"

class extDateType: public dateType{
	public:
		extDateType(int m, int d, int y ): dateType(m,d,y){}
		bool isLeapYear();
		int numDays(int m);
		int daysPassed();
		int daysRemaining();
		void print();
};

#endif /* EXTDATETYPE_H_ */
