#include "Coach.h"

Coach::Coach(
	string positionName,
	string requirements, 
	int salary, 
	string phoneNumber, 
	string address, 
	int age
) : Position(positionName, requirements, salary)
{
	this->setPhoneNumber(phoneNumber);
	this->setAddress(address);
	this->setAge(age);
}

string Coach::getPhoneNumber()
{
	return this->phoneNumber;
}

string Coach::getAddress()
{
	return this->address;
}

int Coach::getAge()
{
	return this->age;
}

void Coach::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Coach::setAddress(string address)
{
	this->address = address;
}

void Coach::setAge(int age)
{
	if (age < 1)
		age = 1;
	this->age = age;
}
