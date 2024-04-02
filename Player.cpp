#include "Player.h"

Player::Player(
	string positionName,
	string requirements,
	int salary,
	string phoneNumber,
	string address,
	int age,
	string teamCode,
	string teamName,
	string playerCode,
	string surname,
	string name,
	string fatherName,
	Date birthday,
	int height, 
	int weight, 
	string role, 
	int number
) : Team(positionName, requirements, salary, phoneNumber, address, age, teamCode, teamName)
{
	this->setPlayerCode(playerCode);
	this->setSurname(surname);
	this->setName(name);
	this->setFatherName(fatherName);
	this->setBirthday(birthday);
	this->setHeight(height);
	this->setWeight(weight);
	this->setRole(role);
	this->setNumber(number);
}

Player::Player(
	Team team, 
	string playerCode, 
	string surname, 
	string name, 
	string fatherName, 
	Date birthday, 
	int height, 
	int weight, 
	string role, 
	int number
) : Team(team.getPositionName(), team.getRequirements(), team.getSalary(), team.getCoachPhoneNumber(), team.getCoachAddress(), team.getAge(), team.getTeamCode(), team.getTeamName())
{
	this->setPlayerCode(playerCode);
	this->setSurname(surname);
	this->setName(name);
	this->setFatherName(fatherName);
	this->setBirthday(birthday);
	this->setHeight(height);
	this->setWeight(weight);
	this->setRole(role);
	this->setNumber(number);
}


Player::Player() : Team()
{
}

string Player::getPlayerCode()
{
	return this->playerCode;
}

string Player::getSurname()
{
	return this->surname;
}

string Player::getName()
{
	return this->name;
}

string Player::getFatherName()
{
	return this->fatherName;
}

Date Player::getBirthday()
{
	return this->birthday;
}

int Player::getHeight()
{
	return this->height;
}

int Player::getWeight()
{
	return this->weight;
}

string Player::getRole()
{
	return this->role;
}

int Player::getNumber()
{
	return this->number;
}

void Player::setPlayerCode(string playerCode)
{
	this->playerCode = playerCode;
}

void Player::setSurname(string surname)
{
	this->surname = surname;
}

void Player::setName(string name)
{
	this->name = name;
}

void Player::setFatherName(string fatherName)
{
	this->fatherName = fatherName;
}

void Player::setBirthday(Date birthday)
{
	this->birthday = birthday;
}

void Player::setHeight(int height)
{
	this->height = height;
}

void Player::setWeight(int weight)
{
	this->weight = weight;
}

void Player::setRole(string role)
{
	this->role = role;
}

void Player::setNumber(int number)
{
	this->number = number;
}

void Player::print()
{
	this->printHead();
	this->printBody();
	this->printEnd();
}

void Player::printHead()
{
	cout << "\n \t Player { ";
}

void Player::printBody()
{
	Team::printBody();
	cout << ",\n \t Player code: " << this->getPlayerCode();
	cout << ",\n \t Name: " << this->getName();
	cout << ",\n \t Surname: " << this->getSurname();
	cout << ",\n \t Father name: " << this->getFatherName();
	cout << ",\n \t Birthday: { Year: " << birthday.getYear() << ", Month: " << birthday.monthToString() << ", Day: " << birthday.getDay() << " }";
	cout << ",\n \t Height: " << this->getHeight();
	cout << ",\n \t Weight: " << this->getHeight();
	cout << ",\n \t Role: " << this->getRole();
	cout << ",\n \t Number: " << this->getNumber();
}

void Player::printEnd()
{
	cout << "\n \t }";
}
