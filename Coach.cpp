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

void Coach::print()
{
	cout << "\n \t Coach { ";
	cout << " Position Name: " << this->getPositionName();
	cout << ", Requirements: " << this->getRequirements();
	cout << ", Salary: "; this->getSalary();
	cout << ", Coach phone number: " << this->getCoachPhoneNumber();
	cout << ", Coach address: " << this->getCoachAddress();
	cout << ", Coach age: " << this->getAge();
	cout << " }";
}
