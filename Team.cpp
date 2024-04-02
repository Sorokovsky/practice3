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

Team::Team(
	Coach coach, 
	string teamCode, 
	string teamName
) : Coach(coach.getPositionName(), coach.getRequirements(), coach.getSalary(), coach.getCoachPhoneNumber(), coach.getCoachAddress(), coach.getAge())
{
	this->setTeamCode(teamCode);
	this->setTeamName(teamName);
}

Team::Team() : Coach()
{
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

void Team::print()
{
	this->printHead();
	this->printBody();
	this->printEnd();
}

void Team::printHead()
{
	cout << "\n \t Team {";
}

void Team::printBody()
{
	Coach::printBody();
	cout << ",\n \t Team code: " << this->getTeamCode();
	cout << ",\n \t Team name: " << this->getTeamName();
}

void Team::printEnd()
{
	cout << "\n \t }";
}
