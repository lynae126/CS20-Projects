/*
 * customerListType.h
 *
 *  Created on: Mar 24, 2021
 *      Author: cc
-----------------------------------
customerListType : public customerType
-----------------------------------
- searchCustList(int id, bool& found,
  nodeType<customerType>* &current) const : void
-----------------------------------
+ custSearchId(int id) : bool
+ getName(int id)const : string
+ custReturnVideo(int id, string title) : void
+ custRentVideo(int id, string title) : void
+ custGetNoOfRentals(int id)const : int
+ rentedVideosInfo(int id): void
+ getCustomer(int id)const : nodeType<customerType>*
-----------------------------------
*/
#ifndef CUSTOMERLISTTYPE_H_
#define CUSTOMERLISTTYPE_H_
#include "customerType.h"
#include "LinkedListType.h"

class customerListType: public linkedListType<customerType>{
	private:
		void searchCustList(int id, bool& found, nodeType<customerType>* &current) const;
	public:
		bool custSearchId(int id);
		string getName(int id)const;
		void custReturnVideo(int id, string title);
		void custRentVideo(int id, string title);
		int custGetNoOfRentals(int id)const;
		void rentedVideosInfo(int id);
		bool custSearchTitle(int id, string title);
		nodeType<customerType>* getCustomer(int id)const;
};

//Function to find the customer with given id
//Postcondition: Returns a pointer to the customer
nodeType<customerType> *customerListType::getCustomer(int id)const{
	nodeType<customerType>* current = first;
	while(current != nullptr)
		current = current->link;
	return current;
}

//Function to check to see if the customer with given id is in list
//Postcondition: sets found to true if, else gets set to false
void customerListType::searchCustList(int id, bool& found,
                         nodeType<customerType>* &current) const{
    found = false;   //set found to false
    current = first; //set current to point to the first node in the list
    while (current != NULL && !found)     //search the list
        if (current->info.getID() == id) //the item is found
            found = true;
        else
            current = current->link; //advance current to the next node
}

//Function to check to see if the customer with given id is in list
//Postcondition: Returns true if found, else returns false
bool customerListType::custSearchId(int id){
	bool found;
	nodeType<customerType>* current = first;
	searchCustList(id, found, current);
    if (found)
        found = (current->info.getID() > 0);
    else
        found = false;
    return found;
}

//Function to check to see if the customer with given id is in list
//Postcondition: Returns true if found, else returns false
bool customerListType::custSearchTitle(int id, string title){
	nodeType<customerType>* current = first;
	while(current!=nullptr){
		if(current->info.getID() == id)
			break;
		current = current->link;
	}
	return current->info.hasVid(title);
}

//Function to check in a video with given title and id number
//Postcondition: Returns void, but the title of the video should be removed from given customer's rented video list
void customerListType::custReturnVideo(int id, string title){
	nodeType<customerType>* current = first;
	while(current!=nullptr){
		if(current->info.getID() == id)
			break;
		current = current->link;
	}
	current->info.delRent(title);
}

//Function to rent out a video with given title and id number
//Postcondition: Returns void, but the title of the video should show up on given customer's rented video list
void customerListType::custRentVideo(int id, string title){
	nodeType<customerType>* current = first;
	while(current!=nullptr){
		if(current->info.getID() == id)
			break;
		current = current->link;
	}
	current->info.addRent(title);
}

//Function to return the amount of rented videos corresponding with given id
//Postcondition: Returns the number of videos rented out for each customer
int customerListType::custGetNoOfRentals(int id)const{
	nodeType<customerType>* current = first;
	while(current!=nullptr){
		if(current->info.getID() == id)
			break;
		current = current->link;
	}
	return current->info.getNumOfRent();
}

//Function to print out all data in the list
//Postcondition: Returns void, but all data for each customer including the rented videos is printed
void customerListType::rentedVideosInfo(int id){
	nodeType<customerType>* current = first;
	while(current!=nullptr){
		if(current->info.getID() == id)
			break;
		current = current->link;
	}
	cout << current->info.getNumOfRent() << " videos are rented out by " << current->info.getName() << endl;
	current->info.printRented();
}

//Function to get the customer's name from id given
//Postcondition: Returns the name corresponding to id
string customerListType::getName(int id)const{
	nodeType<customerType>* current = first;
	while(current!=nullptr && id != current->info.getID())
		current = current->link;
	return current->info.getName();
}
#endif /* CUSTOMERLISTTYPE_H_ */
