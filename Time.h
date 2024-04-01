#pragma once
#include "Equels.h"
class Time
{
public:
	Time();
	Time(int seconds, int minutes, int hours);
	void setSeconds(int seconds);
	void setMinutes(int minutes);
	void setHours(int hours);
	int getSeconds();
	int getMinutes();
	int getHours();
	static Equels compare(Time first, Time second);
private:
	int seconds;
	int minutes;
	int hours;
};