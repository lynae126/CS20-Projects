//*****************
//Program Name: 7.2 - FileAnalysis
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: working with sets and files
//*****************
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
	set<string> unique, unique2, unique3, text1, text2;
	set<string>::iterator it;
	string word;
	ifstream file("text1.txt");
	cout << "Working with Sets\n-------------------\n";
	// Open the source file and check, if it could be opened and there is no failure
	if(!file)
		cerr << "\nFile does not exist\n";
	else{
		cout << "Listing the unique words in text1.txt...\n";
		while(getline(file, word)){
			text1.insert(word);
			if(!unique.count(word)){
				unique.insert(word);
				unique3.insert(word);
			}else{
				unique.erase(word);
			}
		}
		for(it = unique.begin(); it != unique.end(); ++it)
			cout << *it << "\t";
		cout << "\n\n";
		file.close();
	}

	ifstream file2("text2.txt");
	if(!file2)
		cerr << "\nFile does not exist\n";
	else{
		cout << "Listing the unique words in text2.txt...\n";
		while(getline(file2, word)){
			text2.insert(word);
			if(!unique2.count(word))
				unique2.insert(word);
			else
				unique2.erase(word);
			}
		for(it = unique2.begin(); it != unique2.end(); ++it)
			cout << *it << "\t";
		file2.close();
	}

	cout << "\n\nListing the words that appear in both files...\n";
	for(it = text1.begin(); it != text1.end(); ++it)
		if(text2.find(*it)!=text2.end())
			cout << *it << "\t";

	cout << "\n\nListing the words that appear in the first file, but not the second...\n";
	for(it = text1.begin(); it != text1.end(); ++it)
		if(text2.find(*it)==text2.end())
			cout << *it << "\t";

	cout << "\n\nListing the words that appear in the second file, but not the first...\n";
	for(it = text2.begin(); it != text2.end(); ++it)
		if(text1.find(*it)==text1.end())
			cout << *it << "\t";

	cout << "\n\nListing the words that appear in either the first or second files, but not both...\n";
	for(it = unique2.begin(); it != unique2.end(); ++it){
		if(unique3.find(*it)!=unique3.end())
			unique3.erase(*it);
		else
			unique3.insert(*it);
	}
	for(it = unique3.begin(); it != unique3.end(); ++it)
		cout << *it << "\t";

	cout << "\n\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
