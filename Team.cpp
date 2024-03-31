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
	cout << "\n \t Team {";
	cout << "Coach Position Name: " << this->getPositionName();
	cout << ", Coach Requirements: " << this->getRequirements();
	cout << ", Coach Salary: "; this->getSalary();
	cout << ", Coach phone number: " << this->getCoachPhoneNumber();
	cout << ", Coach address: " << this->getCoachAddress();
	cout << ", Coach age: " << this->getAge();
	cout << ", Team code: " << this->getTeamCode();
	cout << ", Team name: " << this->getTeamName();
	cout << " }";
}
