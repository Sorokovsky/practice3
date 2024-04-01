#include "Date.h"

Date::Date() : Date(1, 1, 1)
{
}

Date::Date(int year, int month, int day)
{
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
}

void Date::setYear(int year)
{
	if (year < 1)
		year = 1;
	this->year = year;
}

void Date::setMonth(int month)
{
	if (month < 1)
		month = 1;
	if (month > 12)
		month = 12;
	this->month = month;
}

void Date::setDay(int day)
{
	if (day < 1)
		day = 1;
	this->month = month;
}

int Date::getYear()
{
	return this->year;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getDay()
{
	return this->day;
}

string Date::monthToString()
{
	string month;
	switch (this->getMonth())
	{
	case 1:
		month = "January";
		break;
	case 2:
		month = "February";
		break;
	case 3:
		month = "March";
		break;
	case 4:
		month = "April";
		break;
	case 5:
		month = "May";
		break;
	case 6:
		month = "June";
		break;
	case 7:
		month = "July";
		break;
	case 8:
		month = "August";
		break;
	case 9:
		month = "September";
		break;
	case 10:
		month = "October";
		break;
	case 11:
		month = "November";
		break;
	case 12:
		month = "December";
		break;
	default:
		break;
	}
	return month;
}

Equels Date::compare(Date first, Date second)
{
	if (first.getYear() > second.getYear())
		return Equels::firstMore;
	else if (first.getYear() < second.getYear())
		return Equels::secondMore;
	else
	{
		if (first.getMonth() > second.getMonth())
			return Equels::firstMore;
		else if (first.getMonth() < second.getMonth())
			return Equels::secondMore;
		else
		{
			if (first.getDay() > second.getDay())
				return Equels::firstMore;
			else if (first.getDay() < second.getDay())
				return Equels::secondMore;
			else
				return Equels::equel;
		}
	}
}
