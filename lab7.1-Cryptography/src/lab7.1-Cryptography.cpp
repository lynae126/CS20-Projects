//*****************
//Program Name: 7.1 - Cryptography
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: using maps as an cipher legend for encryption and decryption
//*****************
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

void encrypt(string encryptFile, string outputFile);
void decrypt(string encrypted);
const map<char,char> crypt = {
		{'A', 'D'}, {'B', 'E'}, {'C', 'F'}, {'D', 'G'}, {'E', 'H'}, {'F', 'I'},
		{'G', 'J'}, {'H', 'K'}, {'I', 'L'}, {'J', 'M'}, {'K', 'N'}, {'L', 'O'},
		{'M', 'P'}, {'N', 'Q'}, {'O', 'R'}, {'P', 'S'}, {'Q', 'T'}, {'R', 'U'},
		{'S', 'V'}, {'T', 'W'}, {'U', 'X'}, {'V', 'Y'}, {'W', 'Z'}, {'X', 'A'},
		{'Y', 'B'}, {'Z', 'C'}
};

int main() {
	//I couldn't figure out the problem to why some code wasn't working such as the at() function,
	//the map, and the range based for loop, so I couldn't finish debugging properly.
	//It seems that it's because of not compiling my code with the right version, but I still couldn't fix it.
	encrypt("raw.txt","encrypted.txt");
	decrypt("encrypted.txt");
	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}

//encrypt(): encrypting the given message in the encryptFile, and outputting result in outputFile
//Arguments: encryptFile, outputFile (string) | Returns: void
void encrypt(string encryptFile, string outputFile){
	//caesar cipher of shift 3
	string result = "", word;
	ifstream file(encryptFile);
	if(!file.is_open())
		cerr << "Can not open file\n";
	else{
		getline(file, word);
		for(int i = 0; i<word.length(); i++)
			result += crypt.at(word[i]);
		file.close();
		ofstream file2(outputFile);
		file2 << result;
		file2.close();
	}
}

//decrypt(): decrypting the given message in the encrypted file, and outputting result on console
//Arguments: encrypted(string) | Returns: void
void decrypt(string encrypted){
	ifstream file(encrypted);
	string mes, result;
	int count = 0;
	if(!file.is_open())
		cerr << "Can not open file\n";
	else{
		getline(file, mes);
		for(int i = 0; i<mes.length(); i++){
			for(auto it : crypt){
				if(it.second == mes[count]){
					result += it.first;
					count++;
				}
			}
		}
		cout << "Message Decrypted: " << result << endl;
		file.close();
	}
}
