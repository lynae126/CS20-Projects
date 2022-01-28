//*****************
//Program Name: Honors Project 2
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Code a program that simulates a bank.
//*****************
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <ctime>
#include "Bank.h"
#include "User.h"
#include "Account.h"
using namespace std;
void setBankInfo(Bank& bank);
void backupData(Bank bank);
void login(Bank bank, string name);
void search(Bank bank, string name);
void accountLogin(Bank &bank, string name, int acc);
void createUser(Bank &bank, string fn, string ln, string add, string phone, string date, string ct);
void addAccount(Bank &bank, int index, string nn, string at,	double id, double num);
/*
 * Note 1: I was a bit confused on the routing errors issue, so I assumed
 * that you meant using cerr to print out errors
 *
 * Note 2: For the update/backup functions, I discovered that using thread might
 * enable me to run other functions alongside my original program, so combining
 * this with time functions might work. I'm not sure if my code even works probably,
 * but this is my guess on how to solve this problem.
 *
 * Note 3: I ran out of time when coding this program, the only thing I couldn't finish was
 * implementing the withdraw/add balance, the setting date for first account
 * opened functions, and adding new accounts(I ran into the same issue for all of them - none
 * of the data is saved). Like I coded them, but those functions don't seem to affect the original
 * data, otherwise I would have mostly fulfilled most of the program's requirements. Passing bank
 * by reference to the functions listed at very top of this file, made everything worse, so I don't
 * think that's the solution.
 */

int main() {
	int choice = 0;
	Bank bank;
	setBankInfo(bank);
	//I don't know how to continuously update everything and keep this running when the program
	//ends, so I'm just gonna stick this here for now
	thread t1(backupData, bank);
	string fn, ln, add, phone, ct, name;
	do{
		do{
			cout << "Welcome to the Honors Bank System:\n";
			cout << "------------------------------------\n";
			cout << "1. Print Bank Information" << endl;
			cout << "2. Log in" << endl;
			cout << "3. Search" << endl;
			cout << "4. Register New User" << endl;
			cout << "5. Exit Bank" << endl;
			cin >> choice;
			cout << endl;
			switch(choice){
				case 1:
					bank.printBankInfo();
					break;
				case 2:
					cout << "Log in\n________\nEnter user's last name: ";
					cin >> name;
					if(bank.userExists(name))
						login(bank, name);
					else
						cout << "User doesn't exist\n\n";
					break;
				case 3:
					cout << "Enter user's last name: ";
					cin >> name;
					if(bank.userExists(name))
						search(bank, name);
					else
						cout << "User doesn't exist\n\n";
					break;
				case 4:
					cout << "Enter first name: ";
					cin >> fn;
					cout << "Enter last name: ";
					cin >> ln;
					cout << "Enter address: ";
					cin >> add;
					cout << "Enter phone number: ";
					cin >> phone;
					cout << "Enter customer type(retail v VIP): ";
					cin >> ct;
					cout << "** Created user " << fn + " " << ln << " **\n\n";
					createUser(bank,fn, ln, add, phone, "N/A", ct);
					break;
				case 5:
					cout << "Exitting Bank System...\n\n";
					break;
				default:
					cerr << "Invalid option chosen...\n\n";
			}
		} while(choice < 1 || choice > 5);
	}while(choice != 5);

	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//search(): searches for information for user under given name
//Arguments: bank (Bank), name(string) | Returns: void
void search(Bank bank, string name){
	int choice = 0;
	do{
		do{
			cout << "Searching " << name << "...\n";
			cout << "-------------------------\n";
			cout << "1. Show Accounts Under User" << endl;
			cout << "2. Show All Account Information" << endl;
			cout << "3. Back" << endl;
			cin >> choice;
			cout << endl;
			switch(choice){
				case 1:
					bank.showUserAccounts(name);
					break;
				case 2:
					bank.showAllAccounts(name);
					break;
				case 3:
					cout << "Returning to Default Menu...\n\n";
					break;
				default:
					cerr << "Invalid option chosen...\n";
			}
		} while(choice < 1 || choice > 3);
	} while(choice != 3);
}

//login(): logins into bank as user
//Arguments: bank (Bank), name(string) | Returns: void
void login(Bank bank, string name){
	int choice, acc;
	string nn, at;
	double id;
	time_t now = time(0);
	tm *ltm = localtime(&now);

	do{
		do{
			cout << "\nWelcome " << name << ":\n";
			cout << "-------------------------\n";
			cout << "1. Show User Information" << endl;
			cout << "2. Log into User Account" << endl;
			cout << "3. Show Accounts Under User" << endl;
			cout << "4. Show All Account Information" << endl;
			cout << "5. Add Account" << endl;
			cout << "6. Back" << endl;
			cin >> choice;
			cout << endl;
			switch(choice){
				case 1:
					bank.showUserInfo(name);
					cout << endl;
					break;
				case 2:
					cout << "____________\n";
					cout << "Enter account id: ";
					cin >> acc;
					if(bank.accountExists(name, acc))
						accountLogin(bank, name, acc);
					else
						cerr << "Account doesn't exist under " << name << endl;
					break;
				case 3:
					bank.showUserAccounts(name);
					break;
				case 4:
					bank.showAllAccounts(name);
					break;
				case 5:
					cout << "Enter Account Nickname: ";
					cin >> nn;
					cout << "Enter Account Type: ";
					cin >> at;
					cout << "Enter Account ID: ";
					cin >> id;
					cout << "** Created account for " << name << " **\n\n";
					if(bank.getUser(name).getNumAccounts() == 0)
						bank.getUser(name).setDate(to_string(ltm->tm_mon) + " " + to_string(ltm->tm_mday));
					addAccount(bank, bank.getIndex(name), nn, at, id, 0);
					break;
				case 6:
					cout << "Returning to Default Menu...\n\n";
					break;
				default:
					cerr << "Invalid option chosen...\n";
			}
		} while(choice < 1 || choice > 6);
	}while(choice != 6);
}

//setBankInfo(): reads input file and initializes bank data
//Arguments: bank(Bank &) | Returns: void
void setBankInfo(Bank& bank){
	ifstream file("input.txt");
    int users = 0;
	string fn, ln, add, phone, date, ct, line, nn, at;
	double id, num;
	stringstream ss;
	if(!file)
		cerr << "\nFile does not exist\n";
	else{
		while(getline(file, fn)){
			getline(file, ln);
			getline(file, add);;
			getline(file, phone);
			getline(file, date);
			getline(file, ct);
			getline(file, line);
			createUser(bank, fn, ln, add, phone, date, ct);
			//setting user account data
			while(line != "..."){
				getline(file, nn);
				getline(file, at);
				getline(file, line);
				ss.clear();
				ss << line;
				ss >> id;
				ss.clear();
				getline(file, line);
				ss << line;
				ss >> num;
				getline(file, line);
				addAccount(bank, users, nn, at, id, num);
			}
			users++;
		}
		file.close();
	}
}

//accountLogin(): logins into given user account
//Arguments: bank (Bank&), name(string), acc(int) | Returns: void
void accountLogin(Bank &bank, string name, int acc){
	int choice;
	double amount;
	do{
		do{
			cout << "\n" << name << ": " << bank.getAccount(name, acc).getNickName() << "\n";
			cout << "-------------------------\n";
			cout << "1. Show Account Information" << endl;
			cout << "2. Add to Balance" << endl;
			cout << "3. Withdraw" << endl;
			cout << "4. Back" << endl;
			cin >> choice;
			cout << endl;
			switch(choice){
				case 1:
					cout << bank.getAccount(name, acc).accountInfo();
					break;
				case 2:
					cout << "Enter amount to add to balance: ";
					cin >> amount;
					bank.addBalance(name, acc, amount);
					cout << "Added " << amount << " to " << bank.getAccount(name, acc).getNickName() << "...\n";
					break;
				case 3:
					cout << "Enter amount to withdraw: ";
					cin >> amount;
					bank.withdraw(name, acc, amount);
					cout << "Withdrew " << amount << " from " << bank.getAccount(name, acc).getNickName() << "...\n";
					break;
				case 4:
					cout << "Returning to Default Menu...\n\n";
					break;
				default:
					cerr << "Invalid option chosen...\n";
			}
		} while(choice < 1 || choice > 4);
	}while(choice != 4);
}

//createUser(): creates a new user
//Arguments: bank(Bank &), fn, ln, add, phone, date, ct(string) | Returns: void
void createUser(Bank &bank, string fn, string ln, string add, string phone, string date, string ct){
  User newUser(fn, ln, add, phone, date, ct);
  bank.addUser(newUser);
}

//addAccount(): creates a new account under user
//Arguments:  bank(Bank &), index(int), nn, at(string), id, num(double) | Returns: void
void addAccount(Bank &bank, int index, string nn, string at, double id, double num){
  Account newAcc(at, nn, id, num);
  bank.addUserAccount(newAcc, index);
}

//backupData(): backups data in output file
//Arguments: bank(Bank) | Returns: void
void backupData(Bank bank){
	using namespace std::this_thread;// sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	//there are 86400 seconds in a day, so theoretically, this will update 24 hours
	//from when the program boots up. I'm not sure how to keep this function looping
	//without overlapping everything
	//sleep_until(system_clock::now() + seconds(86400));
	ofstream file("output.txt");
	file << bank.returnBankInfo();
	file << "\n--------------------\n";
	for(int i = 0 ; i < bank.getNumUsers(); i++)
		file << bank.returnUserAccounts(i) << endl;
	file.close();
}
