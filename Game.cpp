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
	Date dateOfGame,
	Time timeOfGame
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
	Date dateOfGame,
	Time timeOfGame
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

Date Game::getDateOfGame()
{
	return this->dateOfGame;
}

Time Game::getTimeOfGame()
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

void Game::setDateOfGame(Date dateOfGame)
{
	this->dateOfGame = dateOfGame;
}

void Game::setTimeOfGame(Time timeOfGame)
{
	this->timeOfGame = timeOfGame;
}

void Game::print()
{
	this->printHead();
	this->printBody();
	this->printEnd();
}

void Game::printHead()
{
	cout << "\n \t Game { ";
}

void Game::printBody()
{
	Team::printBody();
	cout << ", Game code: " << this->getGameCode();
	cout << ", Game name: " << this->getGameName();
	cout << ", Date of game { Year:  " << dateOfGame.getYear() << ", Month: " << dateOfGame.monthToString() << ", Day: " << dateOfGame.getDay() << " }";
	cout << ", Time of game: { Hours: " << timeOfGame.getHours() << ", Minutes: " << timeOfGame.getMinutes() << ", Seconds: " << timeOfGame.getSeconds() << " }";
}

void Game::printEnd()
{
	cout << " }";
}
