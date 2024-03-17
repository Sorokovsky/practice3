#pragma once
#include "constants.h"
#include<stdlib.h>
#include<string.h>
class Position
{
public:

	Position(char nameOfPosition[WORD_LENGTH], char requirements[WORD_LENGTH], int salary)
	{
		this->setNameOfPosition(nameOfPosition);
		this->setRequirements(requirements);
		this->setSalary(salary);
	}

	Position()
	{
		char name[WORD_LENGTH] = "Employer";
		char requirements[WORD_LENGTH] = "Careful";
		this->setNameOfPosition(name);
		this->setRequirements(requirements);
		this->setSalary(rand());
	}

	void setNameOfPosition(char name[WORD_LENGTH])
	{
		strcpy_s(this->nameOfPosition, WORD_LENGTH, name);
	}

	char* getNameOfPosition()
	{
		char name[WORD_LENGTH];
		strcpy_s(name, WORD_LENGTH, this->nameOfPosition);
		return name;
	}

	void setRequirements(char requirements[WORD_LENGTH])
	{
		strcpy_s(this->requirements, WORD_LENGTH, requirements);
	}

	char* getRequirements()
	{
		char requirements[WORD_LENGTH];
		strcpy_s(requirements, WORD_LENGTH, this->requirements);
		return requirements;
	}

	void setSalary(int salary)
	{
		this->salary = salary;
	}

	int getSalary()
	{
		return this->salary;
	}

protected:
	char nameOfPosition[WORD_LENGTH];
	char requirements[WORD_LENGTH];
	int salary;
};