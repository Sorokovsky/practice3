#include "StadiumType.h"

StadiumType::StadiumType(string codeOfStadiumType, string nameOfStadiumType)
{
	this->setCodeOfStadiumType(codeOfStadiumType);
	this->setNameOfStadiumType(nameOfStadiumType);
}

StadiumType::StadiumType()
{
}

string StadiumType::getCodeOfStadiumType()
{
	return this->codeOfStadiumType;
}

string StadiumType::getNameOfStadiumType()
{
	return this->nameOfStadiumType;
}

void StadiumType::setCodeOfStadiumType(string code)
{
	this->codeOfStadiumType = code;
}

void StadiumType::setNameOfStadiumType(string name)
{
	this->nameOfStadiumType = name;
}

void StadiumType::print()
{
	this->printHead();
	this->printBody();
	this->printEnd();
}

void StadiumType::printHead()
{
	cout << "\n \t Stadium type { ";
}

void StadiumType::printBody()
{
	cout << "Stadium type code: " << this->getCodeOfStadiumType();
	cout << ", Stadium type name: "; cout << this->getNameOfStadiumType();
}

void StadiumType::printEnd()
{
	cout << " }";
}
