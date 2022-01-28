//*****************
//Program Name: 7.3 - CountWords
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: finding the word count for each word in a file
//*****************
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
	map<string, int> count;
	string word;
	ifstream file("story.txt");
	if(!file)
		cerr << "File does not exist" << endl;
	else{
		while(file >> word){
			//to clean up strings
			if(word[word.length()-1] == ',' || word[word.length()-1] == '.')
				word = word.substr(0, word.length()-1);
			//if the words is found in count
			if(count.count(word)>0)
				count[word]++;
			else
				count.insert(make_pair(word, 1));
		}
		file.close();
	}
	cout << "Word Count\n_______________\n";
	for(auto it : count)
		cout <<"Word: " << it.first << "\t\tCount: " << it.second << endl;
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
