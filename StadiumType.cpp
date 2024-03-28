#include "StadiumType.h"

StadiumType::StadiumType(string codeOfStadiumType, string nameOfStadiumType)
{
	this->setCodeOfStadiumType(codeOfStadiumType);
	this->setNameOfStadiumType(nameOfStadiumType);
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
