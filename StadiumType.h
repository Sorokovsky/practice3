#pragma once
#include "constants.h"
#include<string.h>
#include<stdlib.h>
class StadiumType
{
public:
	StadiumType(int codeOfTypeStadium, char nameOfStadium[WORD_LENGTH])
	{
		this->setCodeOfTypeStadium(codeOfTypeStadium);
		this->setNameOfStadium(nameOfStadium);
	}

	StadiumType()
	{
		char name[WORD_LENGTH] = "Stadium";
		this->setNameOfStadium(name);
		this->setCodeOfTypeStadium(rand());
	}

	void setCodeOfTypeStadium(int code)
	{
		this->codeOfTypeStadium = code;
	}

	int getCodeOfTypeStadium()
	{
		return this->codeOfTypeStadium;
	}

	void setNameOfStadium(char name[WORD_LENGTH])
	{
		strcpy_s(this->nameOfStadium, WORD_LENGTH, name);
	}

	char* getNameOfStadium()
	{
		char name[WORD_LENGTH];
		strcpy_s(name, WORD_LENGTH, this->nameOfStadium);
		return name;
	}

protected:
	int codeOfTypeStadium;
	char nameOfStadium[WORD_LENGTH];
};