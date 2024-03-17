#pragma once
#include "constants.h"
#include<string.h>
class StadiumType
{
	StadiumType(int codOfTypeStadium, char nameOfStadium)
	{

	}

	void setCodOfTypeStadium(int code)
	{
		this->codeOfTypeStadium = code;
	}

	int getCodOfTypeStadium()
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

private:
	int codeOfTypeStadium;
	char nameOfStadium[WORD_LENGTH];
};