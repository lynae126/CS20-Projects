//*****************
//Program Name: Midterm
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: midterm question
//*****************
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <fstream>
#include <list>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;
const int numQuestions = 10;
string lowerCase(string word);
bool containsElm(string str, list<string> &completed);

int main() {
	//setting up variables and data
	srand(time(0));
	map<string, string> flashcards;
	list<string> completed;
	int random = 0, correct = 0, wrong = 0;

	//reading file input into flashcards map
	ifstream input("capitols.txt");
	string state, capitol, ans;
	map<string, string>::iterator it, str;
	while(!input.eof()){
		getline(input, capitol);
		getline(input, state);
		flashcards.emplace(state,capitol);
	}
	input.close();

	//Starting flashcards quiz
	cout << "I'm going to test you with " << numQuestions << " questions on states and capitols\n";
	for(int i = 0; i < numQuestions; i++){
		//to determine which quesiton format is given
		random = rand() % 2 + 1;
		if(random == 1){
			//keep getting a random element from map, until it picks a unique one
			do{
				random = rand() % flashcards.size() + 1;
				it = flashcards.begin();
				for(int i = 0; i < random; i++)
					it++;
			} while(containsElm(it->first, completed)); //keep getting a random number if element is in the completed questions
			//if this question hasn't been completed, add to completed list
			completed.push_back(it->first);
			cout << "What is the capital of " << it->first << "? ";
			getline(cin, ans);
			ans = lowerCase(ans);
			if(ans == lowerCase(it->second)){
				cout << "Correct!\n\n";
				correct++;
			} else
				wrong++;
			while(ans != lowerCase(it->second)){
				cout << "Incorrect!\n\n";
				cout << "What is the capital of " << it->first << "? ";
				getline(cin,ans);
				ans = lowerCase(ans);
				if(ans == lowerCase(it->second))
					cout << "Correct!\n\n";
			}
		} else if(random == 2){ //2nd question format
			do{
				random = rand() % flashcards.size() + 1;
				it = flashcards.begin();
				for(int i = 0; i < random; i++)
					it++;
			} while(containsElm(it->first, completed));

			completed.push_back(it->first);
			cout << it->second << " is the capital of what? ";
			getline(cin,ans);
			ans = lowerCase(ans);
			if(ans == lowerCase(it->first)){
				cout << "Correct!\n\n";
				correct++;
			} else
				wrong++;
			while(ans != lowerCase(it->first)){
				cout << "Incorrect!\n\n";
				cout << it->second << " is the capital of what? ";
				getline(cin,ans);
				ans = lowerCase(ans);
				if(ans == lowerCase(it->first))
					cout << "Correct!\n\n";
			}
		}
	}

	cout << "Correct Answers: " << correct << endl;
	cout << "Incorrect Answers: " << wrong << endl;
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

string lowerCase(string word){
	string result;
	if(isupper(word[0]))
		result += word[0];
	else
		result += toupper(word[0]);
	for(int i = 1; i < word.length(); i++)
		if(word[i] != ' ')
			result += tolower(word[i]);
	return result;
}

bool containsElm(string str, list<string>& completed)
	{ return find(completed.begin(), completed.end(), str) != completed.end(); }
