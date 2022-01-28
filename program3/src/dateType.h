/*
 * dateType.h
 *
 *  Created on: Feb 5, 2021
 *      Author: cc
---------------------------------------
               dateType
---------------------------------------
- month: int
- day: int
- year: int
---------------------------------------
+ dateType(int = 1, int = 1, int = 1900)
+ setDate(int, int, int): void
+ setDay(int): void
+ setMonth(int): void
+ setYear(int): void
+ getDay() const: int
+ getMonth() const: int
+ getYear() const: int
+ printDate() const: void
---------------------------------------
 */
#ifndef DATETYPE_H_
#define DATETYPE_H_

class dateType{
	private:
		int month;
		int day;
		int year;
	public:
		//constructor
		dateType(int m = 1, int d = 1, int y = 1900)
			{ setMonth(m); setDay(d); setYear(y); }

		void setDate(int m, int d, int y);
		void setDay(int d);
		void setMonth(int m);
		void setYear(int y);
		int getDay() const;
		int getMonth() const;
		int getYear() const;

		void printDate() const;
};

#endif /* DATETYPE_H_ */
