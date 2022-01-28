/*
-----------------------------------
			  Actor
-----------------------------------
- idNum : int
- name : string
-----------------------------------
+ Actor()
+ Actor(int id)
+ Actor(int id, string n)
+ setId(int id) : void
+ setName(string n) : void
+ getId()const : int
+ getName()const : string
+ operator==(int value) : bool
+ operator==(const Actor& emp) : bool
+ operator< (const Actor& emp) : bool
+  operator> (const Actor& emp) : bool
+ &operator<<(ostream &strm, Actor &obj)
	: friend ostream
-----------------------------------
*/
#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
using namespace std;

class Actor{
	private:
		int idNum;
		string name;
	public:
		Actor(): idNum(0), name(" "){}
		Actor(int id): idNum(id)
			{ name = "N/A"; }
		Actor(int id, string n){
			idNum = id;
			name = n;
		}

		//accessors and mutators
		void setId(int id)
			{ idNum = id; }
		void setName(string n)
			{ name = n; }
		int getId()const
			{ return idNum; }
		string getName()const
			{ return name; }

		//overloaded operators
		bool operator==(int value)
			{ return this->idNum == value; }
		bool operator==(const Actor& emp)
			{ return this->idNum == emp.idNum; }
		bool operator< (const Actor& emp)
			{ return this->idNum < emp.idNum; }
		bool operator> (const Actor& emp)
			{ return this->idNum > emp.idNum; }

		friend ostream &operator<<(ostream &strm, Actor &obj){
			strm << "ID Number: " << obj.idNum << "\tName: " << obj.name << endl;
			return strm;
		}
};
#endif
