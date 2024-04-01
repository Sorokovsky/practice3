#include "Time.h"

Time::Time() : Time(0, 0, 0)
{

}

Time::Time(int seconds, int minutes, int hours)
{
	this->setSeconds(seconds);
	this->setMinutes(minutes);
	this->setHours(hours);
}

void Time::setSeconds(int seconds)
{
	if (seconds < 0)
		seconds = 0;
	this->seconds = seconds;
}

void Time::setMinutes(int minutes)
{
	if (minutes < 0)
		minutes = 0;
	this->minutes = minutes;
}

void Time::setHours(int hours)
{
	if (hours < 0)
		hours = 0;
	this->hours = hours;
}

int Time::getSeconds()
{
	return this->seconds;
}

int Time::getMinutes()
{
	return this->minutes;
}

int Time::getHours()
{
	return this->hours;
}

Equels Time::compare(Time first, Time second)
{
	if (first.getHours() > second.getHours())
		return Equels::firstMore;
	else if (first.getHours() < second.getHours())
		return Equels::secondMore;
	else
	{
		if (first.getMinutes() > second.getMinutes())
			return Equels::firstMore;
		else if (first.getMinutes() < second.getMinutes())
			return Equels::secondMore;
		else
		{
			if (first.getSeconds() > second.getSeconds())
				return Equels::firstMore;
			else if (first.getSeconds() < second.getSeconds())
				return Equels::secondMore;
			else
				return Equels::equel;
		}
	}
}
