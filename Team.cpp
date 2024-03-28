#include "Team.h"

Team::Team(string positionName,
	string requirements,
	int salary,
	string phoneNumber,
	string address,
	int age,
	string teamCode,
	string teamName
) : Coach(positionName, requirements, salary, phoneNumber, address, age)
{
	this->setTeamCode(teamCode);
	this->setTeamName(teamName);
}

string Team::getTeamCode()
{
    return this->teamCode;
}

string Team::getTeamName()
{
	return this->teamName;
}

void Team::setTeamCode(string teamCode)
{
	this->teamCode = teamCode;
}

void Team::setTeamName(string teamName)
{
	this->teamName = teamName;
}
