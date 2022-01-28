/*
 * Date.h
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
----------------------------
Date
----------------------------
- month : int
- day : int
- year : int
----------------------------
+ Date()
+ Date(int, int, int)
+ Dzte(const Date&)
+ setMonth(int) : void
+ getMonth()const : int
+ setDay(int) : void
+ getDay()const : int
+ setYear(int) : void
+ getYear()const : int
+ print() : void
----------------------------
*/
#ifndef DATE_H_
#define DATE_H_

class Date{
	private:
		int month;
		int day;
		int year;
	public:
		Date(): month(0), day(0), year(0){}
		Date(int, int, int);
		Date(const Date&);
		void setMonth(int);
		int getMonth()const;
		void setDay(int);
		int getDay()const;
		void setYear(int);
		int getYear()const;
		void print();
};

#endif /* DATE_H_ */
