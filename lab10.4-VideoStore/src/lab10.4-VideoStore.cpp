//*****************
//Program Name: lab 10.4 - VideoStore
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: Completing Programming Exercise 15, Chapter 5, page 353.
//*****************

#include <iostream>
#include <fstream>
#include <string>
#include "videoListType.h"
#include "videoType.h"
#include "customerListType.h"
#include "customerType.h"
using namespace std;
void createVideoList(ifstream& infile, videoListType& videoList);
void createCustList(ifstream& infile, customerListType& custList);
void displayMenu();
void processRequests(videoListType& videoList, customerListType& custList);

int main() {;
	videoListType videoList;
	customerListType custList;
	ifstream infile("videoData.txt");
	if(!infile){
		cout << "The input file does not exist. The program terminates...\n";
		return 1;
	}
	createVideoList(infile, videoList);
	infile.close();
	ifstream infile2("customerData.txt");
	if(!infile2){
		cout << "The input file does not exist. The program terminates...\n";
		return 1;
	}
	createCustList(infile2, custList);
	cout << "done5\n";
	infile2.close();
	cout << "done6\n";
	processRequests(videoList, custList);
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

void processRequests(videoListType& videoList, customerListType& custList){
	int choice, id;
	char ch;
	string title;
	cout << "Enter a valid ID: ";
	cin >> id;
	nodeType<customerType>* current = custList.getCustomer(id);

	if(custList.custSearchId(id)){
		cout << "------------------------\n";
		cout << "Welcome " + custList.getName(id) << ":\n";
		cout << "------------------------\n";
		displayMenu();
	}else{
		cout << "Invalid ID...\n";
		return;
	}

	cout << "Enter your choice: ";
	cin >> choice;
	cin.get(ch);
	cout << endl;

	//processing requests
	while(choice != 9){
		switch(choice){
			case 1:
				cout << "Enter the title: ";
				getline(cin, title);

				cout << endl;
				if(videoList.videoSearch(title))
					cout << "The store carries " << title << endl;
				else
					cout << "The store does not carry " << title << endl;
				break;
			case 2:
				cout << "Enter the title: ";
				cin >> title;
				cout << endl;

				if(videoList.videoSearch(title)){
					if(videoList.isVideoAvailable(title)){
						videoList.videoCheckOut(title);
						current->info.addRent(title);
						cout << "Enjoy your movie: " << title << endl;
					} else
						cout << "Currently " << title << " is out of stock." << endl;
				} else
					cout << "The store does not carry " << title << endl;
				break;
			case 3:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if(videoList.videoSearch(title)){
					videoList.videoCheckIn(title);
					//custList.getCustomer(id).delRent(title);
					cout << "Thanks for returning " << title << endl;
				} else
					cout << "The store does not carry " << title << endl;
				break;
			case 4:
				cout << "Enter the title: ";
				getline(cin, title);
				cout << endl;
				if(videoList.videoSearch(title)){
					if(videoList.isVideoAvailable(title))
						cout << title << " is currently in of stock." << endl;
					else
						cout << title << " is currently out of stock." << endl;
				} else
					cout << "The store does not carry " << title << endl;
				break;
			case 5:
				videoList.videoPrintTitle();
				cout << endl;
				break;
			case 6:
				videoList.print();
				break;
			case 7:
				cout << current->info.getNumOfRent() << " videos rented out:\n";
				current->info.printAll();
				break;
			case 8:
				cout << "Logging out...\n\n";
				processRequests(videoList, custList);
				break;
			default:
				cout << "Invalid selection.\n";
		}
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.get(ch);
		cout << endl;
	}
}

void createVideoList(ifstream& infile, videoListType& videoList){
	string title, star1, star2, prod, dir, prodCo;
	char ch;
	int inStock;
	videoType newVideo;
	getline(infile, title);
	while(infile){
		getline(infile, star1);
		getline(infile, star2);
		getline(infile, prod);
		getline(infile, dir);
		getline(infile, prodCo);
		infile >> inStock;
		infile.get(ch);
		newVideo.setVideoInfo(title, star1, star2, prod, dir, prodCo, inStock);
		videoList.insertFirst(newVideo);
		getline(infile, title);
	}
}

void createCustList(ifstream& infile, customerListType& custList){
	string line, first, last;
	int end;
	customerType newCust;

	//I know that there is probably a more efficient way of reading
	//the variables, but I couldn't get them working
	while(!infile.eof()){
		getline(infile, line);
		end = line.find(" ");
		first = line.substr(0, end);
		line = line.erase(0, end+1);
		end = line.find(" ");
		last = line.substr(0, end);
		line = line.erase(0, end+1);
		end = line.find(" ");
		line = line.erase(0, end+1);
		newCust.setInfo(first, last, stoi(line));
		custList.insertFirst(newCust);
	}
}

void displayMenu(){
	cout << "Select one of the following:\n";
	cout << "1: To check whether the store carries a particular video\n";
	cout << "2: To check out a video\n";
	cout << "3: To check in a video\n";
	cout << "4: To check whether a particular video is in stock\n";
	cout << "5: To print only the titles of all the videos\n";
	cout << "6: To print a list of all the videos\n";
	cout << "7: To print a list of all videos rented by current user\n";
	cout << "8: To log out\n";
	cout << "9: To exit all\n";
}
