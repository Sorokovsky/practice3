#include "Position.h"

Position::Position(string positionName, string requirements, int salary)
{
	this->setPositionName(positionName);
	this->setRequirements(requirements);
	this->setSalary(salary);
}

Position::Position()
{
}

string Position::getPositionName()
{
	return this->positionName;
}

string Position::getRequirements()
{
	return this->requirements;
}

int Position::getSalary()
{
	return this->salary;
}

void Position::setPositionName(string positionName)
{
	this->positionName = positionName;
}

void Position::setRequirements(string requirements)
{
	this->requirements = requirements;
}

void Position::setSalary(int salary)
{
	this->salary = salary;
}

void Position::print()
{
	this->printHead();
	this->printBody();
	this->printEnd();
}

void Position::printHead()
{
	cout << "\n \t Position { ";
}

void Position::printBody()
{
	cout << "\n \t Position Name: " << this->getPositionName();
	cout << ",\n \t Position Requirements: " << this->getRequirements();
	cout << ",\n \t Position Salary: " << this->getSalary();
}

void Position::printEnd()
{
	cout << "\n \t }";
}
