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

void StadiumType::save(StadiumType stadiumType)
{
	ofstream file;
	file.open(StadiumType::filePath, ios::binary | ios::app);
	if (!file.is_open())
	{
		cout << "\n \t File not found";
		return;
	}
	StadiumType::stadiumsType.push_back(stadiumType);
	file.write((char*)&stadiumType, sizeof(StadiumType));
}

string StadiumType::filePath = "stadiums-type.dat";