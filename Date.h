#pragma once
#include<iostream>
#include "Equels.h"
using namespace std;
class Date
{
public:
	Date();
	Date(int year, int month, int day);
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	int getYear();
	int getMonth();
	int getDay();
	string monthToString();
	static Equels compare(Date first, Date second);
private:
	int year;
	int month;
	int day;
};