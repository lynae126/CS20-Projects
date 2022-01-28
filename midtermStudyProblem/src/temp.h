/*
 * temp.h
 *
 *  Created on: Mar 29, 2021
 *      Author: cc
 */

#ifndef TEMP_H_
#define TEMP_H_

class temp{
	private:
		int temperature;
	public:
		temp(int t): temperature(t){}
		int getTemp()const{ return temperature; }
		void setTemp(int t) { temperature = t; }
		bool isEthylFreezing()const{ return(temperature <= -173); }
		bool IsEthylBoiling()const{ return(temperature >= 172); }
		bool isWaterFreezing()const{ return(temperature <= 32); }
		bool IsWaterlBoiling()const{ return(temperature >= 212); }
		bool isOxygenFreezing()const{ return(temperature <= -362); }
		bool IsOxygenBoiling()const{ return(temperature >= -306); }
};
#endif /* TEMP_H_ */
