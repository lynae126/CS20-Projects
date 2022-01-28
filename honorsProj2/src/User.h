/*
 * User.h
 *
 *  Created on: May 20, 2021
 *      Author: cc
--------------------------------------
				User
--------------------------------------
- firstName : string
- lastName : string
- address : string
- phone : string
- date : string
- customerType : string
- accounts : vector<Account>
--------------------------------------
+ User()
+ User(string fn, string ln, string add,
  string num, string dt, string ct)
+ setFirstName(string fn) : void
+ setLastName(string ln) : void
+ setAddress(string add) : void
+ setPhoneNum(string num) : void
+ setDate(string dt) : void
+ setCustomerType(string ct) : void
+ getFirstName()const : string
+ getLastName()const : string
+ getFullName()const : string
+ getAddress()const : string
+ getPhoneNum()const : string
+ getDate()const : string
+ getCustomerType()const : string
+ getNumAccounts()const : int
+ getId() : vector<int>
+ addAccount(Account acc) : void
+ getAllAccountNames()const : vector<string>
+ printAllAccounts()const : void
+ printUserInfo()const : void
+ show()const : string
+ getAccount(int index)const : Account
+ accountExist(int acc)const : bool
--------------------------------------
*/

#ifndef USER_H_
#define USER_H_
#include "Account.h"
#include <vector>
using namespace std;

class User{
	private:
		string firstName;
		string lastName;
		string address;
		string phone;
		string date;
		string customerType;
		vector<Account> accounts;
	public:
		//User(): default constructor
		//Arguments: N/A | Returns: N/A
		User(){
			firstName = "N/A";
			lastName = "N/A";
			address = "N/A";
			phone = "N/A";
			date = "N/A";
			customerType = "N/A";
		}

		//User(): constructor with parameters
		//Arguments: fn, ln, add, num, dt, ct(string) | Returns: N/A
		User(string fn, string ln, string add, string num, string dt, string ct){
			firstName = fn;
			lastName = ln;
			address = add;
			phone = num;
			date = dt;
			customerType = ct;
		}

		//setFirstName(): sets first name
		//Arguments: fn (string) | Returns: void
		void setFirstName(string fn)
			{ firstName = fn; }
		//setLastName(): sets last name
		//Arguments: ln (string) | Returns: void
		void setLastName(string ln)
			{ lastName = ln; }
		//setAddress(): sets address
		//Arguments: add (string) | Returns: void
		void setAddress(string add)
			{ address = add; }
		//setPhoneNum(): sets phone number
		//Arguments: num (string) | Returns: void
		void setPhoneNum(string num)
			{ phone = num; }
		//setDate(): sets first account date
		//Arguments: dt (string) | Returns: void
		void setDate(string dt)
			{ date = dt; }
		//setCustomerType(): sets customer type
		//Arguments: ct(string) | Returns: void
		void setCustomerType(string ct)
			{ customerType = ct; }
		//getFirstName(): returns first name
		//Arguments:  N/A | Returns: string
		string getFirstName()const
			{ return firstName; }
		//getLastName(): returns last name
		//Arguments:  N/A | Returns: string
		string getLastName()const
			{ return lastName; }
		//getFullName(): returns full name
		//Arguments:  N/A | Returns: string
		string getFullName()const
			{ return firstName + " " + lastName; }
		//getAddress(): returns address
		//Arguments:  N/A | Returns: string
		string getAddress()const
			{ return address; }
		//getPhoneNum(): returns phone number
		//Arguments:  N/A | Returns: string
		string getPhoneNum()const
			{ return phone; }
		//getDate(): returns first account date
		//Arguments: N/A | Returns: string
		string getDate()const
			{ return date; }
		//getCustomerType(): returns customer type
		//Arguments: N/A | Returns: string
		string getCustomerType()const
			{ return customerType; }
		//getNumAccounts(): returns number of accounts under user
		//Arguments: N/A| Returns: int
		int getNumAccounts()const
			{ return accounts.size(); }
		//addAccount(): adds account to user
		//Arguments: acc (Account) | Returns: void
		void addAccount(Account acc)
			{ accounts.push_back(acc); }
		//getAccount(): returns account at given index
		//Arguments: index (int) | Returns: Account
		Account getAccount(int index)const
			{ return accounts[index]; }

		//getId(): returns all account ids
		//Arguments: N/A | Returns: vector<int>
		vector<int> getId()const{
			vector<int> existingIds;
			for(int i = 0; i < accounts.size(); i++)
				existingIds.push_back(accounts[i].getId());
			return existingIds;
		}

		//getAllAccountNames(): returns all account nicknames
		//Arguments: N/A | Returns: vector<string>
		vector<string> getAllAccountNames()const{
			vector<string> accountNames;
			for(int i = 0; i < accounts.size(); i++)
				accountNames.push_back(accounts[i].getNickName());
			return accountNames;
		}

		//printAllAccounts(): prints all user account info
		//Arguments: N/A | Returns: void
		void printAllAccounts()const{
			cout << "Listing information on all of " << getFullName() << "'s accounts...\n";
			for(int i = 0; i < accounts.size(); i++)
				cout << accounts[i].accountInfo() << endl;
		}

		//printUserInfo(): prints all user basic info
		//Arguments: N/A | Returns: void
		void printUserInfo()const{
			cout << getFullName() << "\n------------------------\n";
			cout << "Customer Type: " << customerType <<endl;
			cout << "Address: " << address <<endl;
			cout << "Phone Number: " << phone <<endl;
			cout << "Number of Accounts: " << accounts.size() <<endl;
			cout << "Date First Account Opened: " << date <<endl;
		}

		//show(): returning all user info including account info
		//Arguments: N/A | Returns: string
		string show()const{
			string info;
			info += getFullName() + "\n------------------------\n";
			info += "Customer Type: " + customerType;
			info += "\nAddress: " + address;
			info += "\nPhone Number: " + phone;
			info += "\nNumber of Accounts: " + to_string(accounts.size());
			info += "\nDate First Account Opened: " + date;
			info += "\nListing information on all of " + getFullName() + "'s accounts...\n";
			info += "\n...\n";
			for(int i = 0; i < accounts.size(); i++)
				info += accounts[i].accountInfo();
			return info;
		}

		//accountExist(): returning true if account with id exists
		//Arguments: acc(int) | Returns: bool
		bool accountExist(int acc)const{
			for(int i = 0; i < accounts.size(); i++)
				if(accounts[i].getId() == acc)
					return true;
			return false;
		}
};
#endif /* USER_H_ */
