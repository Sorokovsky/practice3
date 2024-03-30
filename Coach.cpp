#include "Coach.h"

Coach::Coach(
	string positionName,
	string requirements, 
	int salary, 
	string coachPhoneNumber, 
	string coachAddress, 
	int age
) : Position(positionName, requirements, salary)
{
	this->setCoachPhoneNumber(coachPhoneNumber);
	this->setCoachAddress(coachAddress);
	this->setAge(age);
}

Coach::Coach(
	Position position,
	string coachPhoneNumber,
	string coachAddress,
	int age
) : Position(position.getPositionName(), position.getRequirements(), position.getSalary()) 
{
	this->setCoachPhoneNumber(coachPhoneNumber);
	this->setCoachAddress(coachAddress);
	this->setAge(age);
}

Coach::Coach() : Position()
{
}

string Coach::getCoachPhoneNumber()
{
	return this->coachPhoneNumber;
}

string Coach::getCoachAddress()
{
	return this->coachAddress;
}

int Coach::getAge()
{
	return this->age;
}

void Coach::setCoachPhoneNumber(string phoneNumber)
{
	this->coachPhoneNumber = phoneNumber;
}

void Coach::setCoachAddress(string address)
{
	this->coachAddress = address;
}

void Coach::setAge(int age)
{
	if (age < 1)
		age = 1;
	this->age = age;
}
