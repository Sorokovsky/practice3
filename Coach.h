#pragma once
#include<string.h>
#include "constants.h"
#include "Position.h"
class Coach : Position
{
public:

	Coach(
		char positionName[WORD_LENGTH],
		char requirements[WORD_LENGTH],
		int salary,
		char phoneNumber[WORD_LENGTH],
		char address[WORD_LENGTH],
		int age
	) : Position(positionName, requirements, salary)
	{
		this->setPhoneNumber(phoneNumber);
		this->setAddress(address);
		this->setAge(age);
	}

	Coach() : Position()
	{

	}

	void setPhoneNumber(char phone[WORD_LENGTH])
	{
		strcpy_s(this->phoneNumber, WORD_LENGTH, phone);
	}

	char* getPhoneNumber()
	{
		char phone[WORD_LENGTH];
		strcpy_s(phone, WORD_LENGTH, this->phoneNumber);
		return phone;
	}

	void setAddress(char address[WORD_LENGTH])
	{
		strcpy_s(this->address, WORD_LENGTH, address);
	}

	char* getAddress()
	{
		char address[WORD_LENGTH];
		strcpy_s(address, WORD_LENGTH, this->address);
		return address;
	}

	void setAge(int age)
	{
		if (age < 18)
		{
			age = 18;
		}
		this->age = age;
	}

	int getAge()
	{
		return this->age;
	}

protected:
	char phoneNumber[WORD_LENGTH];
	char address[WORD_LENGTH];
	int age;
};