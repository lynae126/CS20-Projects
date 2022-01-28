/*
 * customerType.h
 *
 *  Created on: Mar 24, 2021
 *      Author: cc
-----------------------------------
customerType : public personType
-----------------------------------
- rentedVids : vector<string>
- idNum : int
-----------------------------------
+ customerType(string, string, int)
+ getID()const : int
+ getName()const : string
+ getNumOfRent()const : int
+ printAll()const : void
+ setInfo(string first, string last, int id) : void
+ addRent(string) : void
+ delRent(string) : void
+ printRented()const : void;
+ hasVid(string) : bool;
-----------------------------------
*/

#ifndef CUSTOMERTYPE_H_
#define CUSTOMERTYPE_H_
#include "personType.h"
#include "videoListType.h"
#include <vector>

class customerType: public personType{
	private:
		int idNum;
		vector<string> rentedVids;
	public:
		customerType(string first = "", string last = "", int id = 0)
			{ setInfo(first, last, id); }
		int getID()const
			{ return idNum; }
		string getName()const
			{ return (getFirstName() + getLastName());};
		int getNumOfRent()const
			{ return rentedVids.size(); };
		void printRented()const;
		void printAll()const;
		void setInfo(string first, string last, int id);
		void addRent(string);
		void delRent(string);
		bool hasVid(string);
};

//Function to check if rentedVids contains given title
//Postcondition: Returns true if customer has rented video, else returns false
bool customerType::hasVid(string title){
	for(int i = 0; i < getNumOfRent(); i++)
		if(rentedVids[i] == title)
			return true;
	return false;
}

//Function to print the data for an object
//Postcondition: Returns void, but all data including name, id, and rented videos gets printed
void customerType::printAll()const{
	personType::print();
	cout << ":\nID: " << getID() << endl;
	cout << "Title: ";
	for(string title : rentedVids)
		cout << title << " ";
	cout << endl;
}

//Function to print the rented videos
//Postcondition: Returns void, but prints out all vidoes stored in rentedVids for current customer
void customerType::printRented()const{
	cout << "Title: ";
		for(string title : rentedVids)
			cout << title << "\t";
		cout << endl;
}

//Function to set the name and id of the customer
//Postcondition: Returns void, but the most of the class' data gets set
void customerType::setInfo(string first, string last, int id){
	setName(first, last);
	idNum = id;
}

//Function to add a movie title to the list, if it gets checked out
//Postcondition: Returns void, but the title of the movie gets pushed back to rentedVids
void customerType::addRent(string vid)
	{ rentedVids.push_back(vid); }

//Function to delete a movie title from the list, if it gets checked in
//Postcondition: Returns void, but the title of the movie gets erased from rentedVids
void customerType::delRent(string vid){
	for(int i = 0; i < getNumOfRent(); i++){
		if(rentedVids[i] == vid){
			rentedVids.erase(rentedVids.begin()+i);
			i--;
		}
	}
}
#endif /* CUSTOMERTYPE_H_ */
