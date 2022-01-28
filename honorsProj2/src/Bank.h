/*
 * Bank.h
 *
 *  Created on: May 19, 2021
 *      Author: cc
-----------------------------------
		linkedListIterator
-----------------------------------
- name : string
- location : string
- phone : string
- users : vector<User>
-----------------------------------
+ Bank()
+ setName(string n) : void
+ setLocation(string loc) : void
+ setPhoneNum(string num) : void
+ getName()const : string
+ getNumUsers()const : int
+ setLocation()const : string
+ setPhoneNum()const : string
+ addUser(User newUser) : void
+ showAllAccounts(string name) : void
+ showUserInfo(string name) : void
+ addUserAccount(Account acc, int index) : void
+ addUserAccount(Account acc, string name) : void
+ returnBankInfo()const : string
+ returnUserAccounts(int num) : string
+ getAccount(string name, int acc) : Account
+ addBalance(string name, int acc, double num) : void
+ withdraw(string name, int acc, double num) : void
+ userExists(string name) : bool
+ accountExists(string name, int acc) : bool
+ showUserAccounts(string name) : void
+ getUser(string name) : User
+ getIndex(string name : int
+ printBankInfo()const : void
-----------------------------------
*/

#ifndef BANK_H_
#define BANK_H_
#include <string>
#include <vector>
#include <string>
#include "User.h"
#include "Account.h"
using namespace std;

class Bank{
	private:
		string name;
		string location;
		string phone;
		vector<User> users;

	public:
		//Bank(): default constructor
		//Arguments: N/A | Returns: N/A
		Bank(){
			name = "Honors Bank System";
			location = "123 Wall St.";
			phone = "(925)-222-333";
		}

		//setName(): set name
		//Arguments: n(string) | Returns: void
		void setName(string n)
			{ name = n; }
		//setLocation(): set location
		//Arguments: loc (string) | Returns: void
		void setLocation(string loc)
			{ location = loc; }
		//setPhoneNum(): set phone number
		//Arguments: num (string) | Returns: void
		void setPhoneNum(string num)
			{ phone = num; }
		//getName(): get name
		//Arguments:  N/A | Returns: string
		string getName()const
			{ return name; }
		//getNumUsers(): get number of users registered
		//Arguments: N/A | Returns: int
		int getNumUsers()const
			{ return users.size(); }
		//getLocation(): get location
		//Arguments: N/A | Returns: string
		string getLocation()const
			{ return location; }
		//getPhoneNum(): get phone number
		//Arguments: N/A | Returns: string
		string getPhoneNum()const
			{ return phone; }

		//addUser(): adds user to list of registered users
		//Arguments: newUser(User) | Returns: void
		void addUser(User newUser)
			{ users.push_back(newUser); }

		//showAllAccounts(): prints data of all accounts of user
		//Arguments: name (string) | Returns: void
		void showAllAccounts(string name)
			{ getUser(name).printAllAccounts(); }

		//showUserInfo(): shows basic user info
		//Arguments: name (string) | Returns: void
		void showUserInfo(string name)
			{ getUser(name).printUserInfo(); }

		//addUserAccount(): adds a new user based on index
		//Arguments: acc(Account), index(int) | Returns: void
		void addUserAccount(Account acc, int index)
			{ users[index].addAccount(acc); }

		//addUserAccount(): adds a new account for user
		//Arguments acc(Account), name (string) | Returns: void
		void addUserAccount(Account acc, string name)
			{ getUser(name).addAccount(acc); }

		//returnBankInfo(): returns all bank information
		//Arguments: N/A | Returns: string
		string returnBankInfo()const
			{ return name + "\n--------------------\nAddress: " + location + "\nPhone #: " + phone + "\nNumber of Registered Users: " + to_string(getNumUsers()) + "\n\n"; }

		//returnUserAccounts(): returns all user information
		//Arguments: num(int) | Returns: string
		string returnUserAccounts(int num)
			{ return users[num].show(); }

		//getAccount(): gets the account of user
		//Arguments: name (string), acc(int) | Returns: Account
		Account getAccount(string name, int acc)
			{ return getUser(name).getAccount(acc); }

		//addBalance(): adds to balance
		//Arguments: name (string), acc(int), num(double) | Returns: void
		void addBalance(string name, int acc, double num)
			{ getUser(name).getAccount(acc).addBalance(num); }

		//withdraw(): withdraws from balance
		//Arguments: name (string), acc(int), num(double) | Returns: void
		void withdraw(string name, int acc, double num)
			{ getUser(name).getAccount(acc).withdraw(num); }

		//userExists(): if user by name exists
		//Arguments: name (string) | Returns: bool
		bool userExists(string name){
			for(int i = 0; i < users.size(); i++)
				if(users[i].getLastName() == name)
					return true;
			return false;
		}

		//accountExists(): if account exists
		//Arguments: name (string), acc(int) | Returns: bool
		bool accountExists(string name, int acc){
			if(getUser(name).accountExist(acc))
				return true;
			return false;
		}

		//showUserAccounts(): listing all accounts under user
		//Arguments: name (string) | Returns: void
		void showUserAccounts(string name){
			vector<string> accs = getUser(name).getAllAccountNames();
			cout << "Listing all accounts under " << name << ":\n";
			for(string names : accs)
				cout << names << endl;
			cout << endl;
		}

		//getUser(): returns user under given name
		//Arguments: name (string) | Returns: User
		User getUser(string name){
			for(int i = 0; i < users.size(); i++){
				if(users[i].getLastName() == name)
					return users[i];
			}
			cerr << "User not found with given name\n";
			cerr << "Returning first user instead...\n";
			return users[0];
		}

		//getIndex(): returns user index with given name
		//Arguments: name (string) | Returns: int
		int getIndex(string name){
			for(int i = 0; i < users.size(); i++)
				if(users[i].getLastName() == name)
					return i;
			cerr << "User not found with given name\n";
			cerr << "Returning first index instead...\n";
			return 0;
		}

		//printBankInfo(): prints all bank info
		//Arguments: N/A | Returns: void
		void printBankInfo()const{
			cout << name << endl;
			cout << "--------------------\n";
			cout << "Address: " << location << endl;
			cout << "Phone #: " << phone << endl;
			cout << "Number of Registered Users: " << getNumUsers() << endl << endl;
		}
};
#endif /* BANK_H_ */
