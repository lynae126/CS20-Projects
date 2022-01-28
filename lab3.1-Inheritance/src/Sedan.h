/*
 * Sedan.h
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
----------------------------
Sedan :: Vehicle
----------------------------
- doors : int
- hatchback : bool
----------------------------
+ Sedan()
+ Sedan(int, int, int, bool)
+ setDoors(int) : void
+ getDoors()const : int
+ setHatchback(bool) : void
+ getHatchback()const : bool
+ printVehicle() : void
----------------------------
*/
#ifndef SEDAN_H_
#define SEDAN_H_
#include "Vehicle.h"

class Sedan : public Vehicle{
	private:
		int doors;
		bool hatchback;
	public:
		Sedan(): doors(0), hatchback(true){}
		Sedan(int, int, int, bool);
		void setDoors(int);
		int getDoors()const;
		void setHatchback(bool);
		bool getHatchback()const;
		void printVehicle();
};

#endif /* SEDAN_H_ */
