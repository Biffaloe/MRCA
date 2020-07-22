#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#pragma once
#ifndef DATAMANAGEMENT_H
#define DATAMANAGEMENT_H

class DataManagement
{
protected:
	int deliveries, month, day, year;
	double milageRate, tips, hoursRoad, hoursInstore;
	const double roadWage = 4;
	const double instoreWage = 8;
	fstream WorkData;
public:
	void SaveData();
	void ShowData();
	void ShowTotal();
	void ShowSpecific();
	void ShowAll();

};

#endif // !DATAMANAGEMENT_H

