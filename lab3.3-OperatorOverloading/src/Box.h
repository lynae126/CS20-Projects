/*
 * Box.h
 *
 *  Created on: Feb 2, 2021
 *      Author: cc
----------------------------
Box
----------------------------
- length : double
- width : double
- height : double
----------------------------
+ Box(double, double, double)
+ volume() : double
+ setLength(double): void
+ setWidth(double): void
+ setHeight(double): void
+ getLength()const: double
+ getWidth()const: double
+ getHeight()const: double
+ operator==(Box): bool
+ operator>(Box): bool
+ operator<(Box): bool
+ operator>=(Box): bool
+ operator<=(Box): bool
----------------------------
*/
#ifndef BOX_H_
#define BOX_H_
#include <iostream>
using namespace std;

class Box{
	private:
		double length;
		double width;
		double height;
	public:
		// Constructor definition with default values
		Box(double l = 2.0, double w = 2.0, double h = 2.0)
			{ length = l; width = w; height = h; }
		double volume();

		void setLength(double l)
			{l >= 0 ? length = l : length = 0;}
		void setWidth(double w)
			{w >= 0 ? width = w : width = 0;}
		void setHeight(double h)
			{h >= 0 ? height = h : height = 0;}
		double getLength()const
			{return length;}
		double getWidth()const
			{return width;}
		double getHeight()const
			{return height;}

		//overloading operators
		bool operator==(Box);
		bool operator>(Box);
		bool operator<(Box);
		bool operator>=(Box);
		bool operator<=(Box);
};

#endif /* BOX_H_ */
