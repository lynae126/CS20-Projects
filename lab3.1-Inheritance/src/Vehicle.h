/*
 * Vehicle.h
 *
 *  Created on: Feb 1, 2021
 *      Author: cc
----------------------------
Vehicle
----------------------------
- year : int
- mileage : int
----------------------------
+ Vehicle()
+ Vehicle(int, int)
+ setYear(int) : void
+ getYear()const : int
+ setMileage(int) : void
+ getMileage()const : int
+ print() : void
----------------------------
*/
#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle{
	private:
		int year;
		int mileage;
	public:
		Vehicle(): year(0), mileage(0){}
		Vehicle(int y, int m): year(y), mileage(m){}
		void setYear(int);
		int getYear()const;
		void setMileage(int);
		int getMileage()const;
		void print();
};

#endif /* VEHICLE_H_ */
