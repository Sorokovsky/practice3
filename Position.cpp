#include "Position.h"

Position::Position(string positionName, string requirements, int salary)
{
	this->setPositionName(positionName);
	this->setRequirements(requirements);
	this->setSalary(salary);
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
