/*
 * Account.h
 *
 *  Created on: May 20, 2021
 *      Author: cc
-----------------------------------
			  Account
-----------------------------------
- accountType : string
- nickName : string
- idNum : int
- balance : double
-----------------------------------
+ Account()
+ Account(string at, string nn, int id, int bal)
+ setAccountType(string at) : void
+ setNickName(string nn) : void
+ setId(int n) : void
+ setBalance(int bal) : void
+ getAccountType()const : string
+ getNickName()const : string
+ getId()const : int
+ getBalance()const : double
+ addBalance(double n) : void
+ withdraw(double n) : void
+ accountInfo()const : string
-----------------------------------
*/
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <vector>
using namespace std;

class Account{
	private:
		string accountType;
		string nickName;
		int idNum;
		double balance;

	public:
		//Account(): default constructor
		//Arguments: N/A | Returns: N/A
		Account(){
			accountType = "checking";
			nickName = "nickname is not set yet,,,";
			idNum = 0;
			balance = 0;
		}

		//constructor(): initializes private members
		//Arguments: at(string), nn(string), id(int), bal(double) | Returns: N/A
		Account(string at, string nn, int id, double bal){
			accountType = at;
			nickName = nn;
			idNum = id;
			balance = bal;
		}

		//setAccountType(): setting account type
		//Arguments: at(string) | Returns: void
		void setAccountType(string at){
			if(at == "checking" || at == "4-star checking" || at == "savings" || at == "4-star savings" || at == "CD's")
				accountType = at;
		}

		//setNickName(): setting account nickname
		//Arguments: nn (string) | Returns: void
		void setNickName(string nn)
			{ nickName = nn; }

		//setId(): setting account id
		//Arguments: n (int) | Returns: void
		void setId(int n)
			{ idNum = n; }

		//setBalance(): setting amount of money in account
		//Arguments: bal(int) | Returns: void
		void setBalance(int bal)
			{ balance = bal; }

		//getAccountType(): returning account type
		//Arguments: N/A | Returns: accountType(string)
		string getAccountType()const
			{ return accountType; }

		//getNickName(): returning account nickname
		//Arguments: N/A | Returns: nickName(string)
		string getNickName()const
			{ return nickName; }

		//getId(): return account id
		//Arguments: N/A | Returns: idNum (int)
		int getId()const
			{ return idNum; }

		//getBalance(): returning balance
		//Arguments: N/A| Returns: balance(double)
		double getBalance()const
			{ return balance; }

		//addBalance(): putting money in the bank
		//Arguments: n(double) | Returns: void
		void addBalance(double n)
			{ balance += n; }

		//withdraw(): taking out money out of balance
		//Arguments: n(double) | Returns: void
		void withdraw(double n)
			{ balance -= n; }

		//accountInfo(): returns all account information in form of string
		//Arguments: N/A | Returns: string
		string accountInfo()const
			{ return getNickName() + ": " + getAccountType() + "\n-------------------\nAccount Number: " + to_string(getId()) + "\nAccount Balance: " + to_string(getBalance()) + "\n"; }
};
#endif /* ACCOUNT_H_ */
