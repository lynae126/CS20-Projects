/*
 * Die.h
 *
 *  Created on: Mar 29, 2021
 *      Author: cc
 */
#ifndef DIE_H_
#define DIE_H_
#include <cstdlib>

class Die{
	private:
		int sides; // Number of sides
		int value; // The die's value
	public:
		Die(int s): sides(s) { roll(); } // Constructor
		void roll()
			{ value += (rand() % (sides - 1 + 1)) + 1; }
		int getSides() // Returns the number of sides
			{ return sides; }
		int getValue() // Returns the die's value
			{ return value; }
};

#endif /* DIE_H_ */
