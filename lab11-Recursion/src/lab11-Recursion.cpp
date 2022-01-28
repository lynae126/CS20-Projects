//*****************
//Program Name: Lab11 - Recursion
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: implementing recursion to loop through a story
//*****************
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int displayMenu();
void printReverse(string story, int num);
int countPunc(string str);

int main() {
	//reading the story into one long string
	ifstream file("ant.txt");
	string line, story = "";
	int choice = 0;
	if(!file)
		cout << "Cannot open ant.txt\n";
	else
		while(getline(file, line))
			story += line;
	file.close();

	//displaying menu and choices
	while(choice!=5){
		choice = displayMenu();
		switch(choice){
			case 1:
				cout << "Number of Punctuation in story: " << countPunc(story) << endl << endl;
				break;
			case 2:
				cout << "Printing story backwards...\n";
				printReverse(story, story.length());
				cout << "\n\n";
				break;
			case 3:
				cout << "Number of Punctuation in story: " << countPunc(story) << endl ;
				cout << "Printing story backwards...\n";
				printReverse(story, story.length());
				cout << "\n\n";
				break;
			case 4:
				cout << "Quitting menu...\n";
				choice = 5;
				break;
		}
	}
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//countPunc(): counting the number of punctuations in the story recursively
//Arguments: str (string) | Returns: countPunc (int)
int countPunc(string str){
	if(str.length() == 0)
		return 0;
	//if the first character is a punctuation, add one and move onto next character
	if(ispunct(str.at(0)))
		return 1 + countPunc(str.substr(1));
	//else just move onto next character
	return countPunc(str.substr(1));
}

//displayMenu(): displaying the menu choices and data validates the input
//Arguments: N/A | Returns: choice (int)
int displayMenu(){
	int choice = 0;
	do{
		cout << "Enter: [1] to find the number of punctuation marks in the story\n";
		cout << "       [2] to print the story in reverse\n";
		cout << "       [3] for both\n";
		cout << "       [4] Quit\n";
		cin >> choice;
	}while(choice < 1 || choice > 4);
	return choice;
}

//printReverse(): prints the given string in reverse
//Arguments: story(string), num(int) | Returns: void
void printReverse(string story, int num){
	//if the number to keep track of story length is an invalid number
	if(num > story.length())
		return;
	//prints last character
	cout << story.back();
	//slowly shortens string
	printReverse(story.substr(0, num - 1), num-1);
}
