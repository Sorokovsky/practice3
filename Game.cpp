#include "Game.h"

Game::Game(
	string positionName, 
	string requirements, 
	int salary, 
	string coachPhoneNumber, 
	string coachAddress, 
	int age, 
	string teamCode, 
	string teamName, 
	string codeOfStadiumType, 
	string nameOfStadiumType, 
	string stadiumCode, 
	string stadiumName, 
	string stadiumAddress, 
	string stadiumPhoneNumber, 
	string masterHead, 
	string notes,
	string gameCode,
	string gameName,
	time_t dateOfGame,
	time_t timeOfGame
) : Stadium(
	codeOfStadiumType,
	nameOfStadiumType,
	stadiumCode,
	stadiumName,
	stadiumAddress,
	stadiumPhoneNumber,
	masterHead,
	notes
),
	Team(
	positionName, 
	requirements, 
	salary, 
	coachPhoneNumber, 
	coachAddress, 
	age, 
	teamCode, 
	teamName
)
{
	this->setGameCode(gameCode);
	this->setGameName(gameName);
	this->setDateOfGame(dateOfGame);
	this->setTimeOfGame(timeOfGame);
}

Game::Game(
	Stadium stadium,
	Team team,
	string gameCode,
	string gameName,
	time_t dateOfGame,
	time_t timeOfGame
) : Team(team.getPositionName(), team.getRequirements(), team.getSalary(), team.getCoachPhoneNumber(), team.getCoachAddress(), team.getAge(), team.getTeamCode(), team.getTeamName()),
	Stadium(stadium.getCodeOfStadiumType(), stadium.getNameOfStadiumType(), stadium.getStadiumCode(), stadium.getStadiumName(), stadium.getStadiumAddress(), stadium.getStadiumPhoneNumber(), stadium.getMasterHead(), stadium.getNotes())
{
	this->setGameCode(gameCode);
	this->setGameName(gameName);
	this->setDateOfGame(dateOfGame);
	this->setTimeOfGame(timeOfGame);
}

Game::Game() : Stadium(), Team()
{
}

string Game::getGameCode()
{
	return this->gameCode;
}

string Game::getGameName()
{
	return this->gameName;
}

time_t Game::getDateOfGame()
{
	return this->dateOfGame;
}

time_t Game::getTimeOfGame()
{
	return this->timeOfGame;
}

void Game::setGameCode(string gameCode)
{
	this->gameCode = gameCode;
}

void Game::setGameName(string gameName)
{
	this->gameName = gameName;
}

void Game::setDateOfGame(time_t dateOfGame)
{
	this->dateOfGame = dateOfGame;
}

void Game::setTimeOfGame(time_t timeOfGame)
{
	this->timeOfGame = timeOfGame;
}

void Game::print()
{
	cout << "\n \t Game { ";
	cout << "Stadium type code: " << this->getCodeOfStadiumType();
	cout << ", Stadium type name: "; cout << this->getNameOfStadiumType();
	cout << ", Stadium code: " << this->getStadiumCode();
	cout << ", Stadium name: " << this->getStadiumName();
	cout << ", Stadium address: " << this->getStadiumAddress();
	cout << ", Stadium phoneNumber: " << this->getStadiumPhoneNumber();
	cout << ", Stadium masterhead: " << this->getMasterHead();
	cout << "Coach Position Name: " << this->getPositionName();
	cout << ", Coach Requirements: " << this->getRequirements();
	cout << ", Coach Salary: "; this->getSalary();
	cout << ", Coach phone number: " << this->getCoachPhoneNumber();
	cout << ", Coach address: " << this->getCoachAddress();
	cout << ", Coach age: " << this->getAge();
	cout << ", Team code: " << this->getTeamCode();
	cout << ", Team name: " << this->getTeamName();
	cout << ", Game code: " << this->getGameCode();
	cout << ", Game name: " << this->getGameName();
	cout << ", Date of game: " << this->getDateOfGame();
	cout << ", Time of game: " << this->getTimeOfGame();
	cout << " }";
}
