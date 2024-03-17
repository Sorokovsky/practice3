#pragma once
#include<string.h>
#include "Coach.h"
#include "constants.h"
class Team : Coach
{
public:

	Team(
		char position[WORD_LENGTH],
		char requirements[WORD_LENGTH],
		int salary,
		char phoneNumber[WORD_LENGTH],
		char address[WORD_LENGTH],
		int age,
		int teamCode,
		char teamName[WORD_LENGTH]
	) : Coach(position, requirements, salary, phoneNumber, address, age)
	{
		this->setTeamCode(teamCode);
		this->setTeamName(teamName);
	}

	Team() : Coach()
	{

	}

	void setTeamCode(int code)
	{
		this->teamCode = code;
	}

	int getTeamCode()
	{
		return this->teamCode;
	}

	void setTeamName(char name[WORD_LENGTH])
	{
		strcpy_s(this->teamName, WORD_LENGTH, name);
	}

	char* getTeamName()
	{
		char team[WORD_LENGTH];
		strcpy_s(team, WORD_LENGTH, this->teamName);
		return team;
	}

protected:
	int teamCode;
	char teamName[WORD_LENGTH];
};