/*
 * Person.h
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
----------------------------
Person
----------------------------
- identity : int
- birthday : Date
----------------------------
+ Person()
+ Person(int, Date)
+ setIdentity(int) : void
+ getIdentity()const : int
+ setBirthday(int, int, int) : void
+ setBirthday(const Date&) : void
+ getBirthday()const : Date
+ printPerson() : void
----------------------------
*/
#ifndef PERSON_H_
#define PERSON_H_
#include "Date.h"

class Person{
	private:
		int identity;
		Date birthday;
	public:
		Person():identity(0)
			{Date b(0,0,0);}
		Person(int, Date);
		void setIdentity(int);
		int getIdentity()const;
		void setBirthday(int,int,int);
		void setBirthday(const Date&);
		Date getBirthday()const;
		void printPerson();
};

#endif /* PERSON_H_ */
