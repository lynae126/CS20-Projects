//demo.cpp file
//*****************
//Program Name: program1
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: I made a class that's supposed to imitate a vector and its functions; it's
//supposed to hold float values, add them to a container, delete them, resize the array, etc.
//*****************

#include <iostream>
#include "DynamicFloatArray.h"
using namespace std;

int main(){
	srand(0);
	const int n=7;
	const int maxval=1000;
	const int minval=100;
	DynamicFloatArray da(n);

	// assigning array da with random values from minval to maxval
	for (int i = 0; i < da.capacity(); i++){
		float rand01 = rand() / float(RAND_MAX);
		da[i] = minval+ (maxval - minval) * rand01;
	}

	//testing push_back and pop_back functions on da
	da.push_back(56.7);
	cout << "push_back executed for dynamic array da!\n" << da;
	da.pop_back();
	cout << "pop_back executed for dynamic array da!\n" << da;

	//checking copy constructor and overloaded [] operator
	DynamicFloatArray da2(da);
	cout << "Dynamic array da2 created!\n";
	da2[0] = 999.01;
	da2[1] = 998.01;
	cout << "Dynamic array da2 changed!\n" << da2;

	//testing rest of overloaded operators and resize and reserve functions
	DynamicFloatArray da3;
	cout << "Dynamic array da3 created!\n" << da3;
	da3 = da2;
	da3 += 333.7;
	cout << "Dynamic array da3 changed!\n" << da3;
	da3.resize(5);
	cout << "Dynamic array da3 resized!\n" << da3;
	cout << "Dynamic array da3 changed capacity!\n";
	da3.reserve(100);
	cout << da3;
	da3 += 449.97;
	cout << "push_back executed for dynamic array da3!\n" << da3;
	--da3;
	cout << "Dynamic array da3 changed!\n" << da3;

	/* I wasn't sure if I should put this or not since this is technically an assignment.
	 * This particular program was code for one of my assignments last semester where the
	 * instructor pretty much gave us the entire main function and told us to create a class
	 * that imitated a vector and its functions, so technically not all of it is my work.
	 */
	cout << "!!! Please read the comment above in my code about this assignment !!!\n";
	cout << "I attest that this code is my original work, I received no help creating it, and that I did not copy this code nor any portion of it from any source.\n";
	return 0;
}
