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
	Time timeOfGame,
	Team secondTeam
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
	this->setSecondTeam(secondTeam);
}

Game::Game(
	Stadium stadium,
	Team team,
	string gameCode,
	string gameName,
	Date dateOfGame,
	Time timeOfGame,
	Team secondTeam
) : Team(team.getPositionName(), team.getRequirements(), team.getSalary(), team.getCoachPhoneNumber(), team.getCoachAddress(), team.getAge(), team.getTeamCode(), team.getTeamName()),
	Stadium(stadium.getCodeOfStadiumType(), stadium.getNameOfStadiumType(), stadium.getStadiumCode(), stadium.getStadiumName(), stadium.getStadiumAddress(), stadium.getStadiumPhoneNumber(), stadium.getMasterHead(), stadium.getNotes())
{
	this->setGameCode(gameCode);
	this->setGameName(gameName);
	this->setDateOfGame(dateOfGame);
	this->setTimeOfGame(timeOfGame);
	this->setSecondTeam(secondTeam);
}

Game::Game() : Stadium(), Team()
{
	this->firstGoals = 0;
	this->secondGoals = 0;
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

Team Game::getSecondTeam()
{
	return this->secondTeam;
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

void Game::setSecondTeam(Team secondTeam)
{
	this->secondTeam = secondTeam;
}

void Game::print()
{
	this->printHead();
	this->printBody();
	this->printEnd();
}

int Game::getFirstGoals()
{
	return this->firstGoals;
}

int Game::getSecondGoals()
{
	return this->secondGoals;
}

void Game::setFirstGoals(int goals)
{
	this->firstGoals = goals;
}

void Game::setSecondGoals(int goals)
{
	this->secondGoals = goals;
}

void Game::printHead()
{
	cout << "\n \t Game { ";
}

void Game::printBody()
{
	cout << "\n \t First team:";
	Team::printBody();
	cout << "\n \t Second team:";
	this->getSecondTeam().print();
	Stadium::printBody();
	cout << ",\n \t Game code: " << this->getGameCode();
	cout << ",\n \t Game name: " << this->getGameName();
	cout << ", \n \t Goals of first team: " << this->getFirstGoals();
	cout << ", \n \t Goals of second team: " << this->getSecondGoals();
	cout << ",\n \t Date of game { Year:  " << dateOfGame.getYear() << ", Month: " << dateOfGame.monthToString() << ", Day: " << dateOfGame.getDay() << " }";
	cout << ",\n \t Time of game: { Hours: " << timeOfGame.getHours() << ", Minutes: " << timeOfGame.getMinutes() << ", Seconds: " << timeOfGame.getSeconds() << " }";
}

void Game::printEnd()
{
	cout << "\n \t }";
}

void Game::play()
{
	this->setFirstGoals(getRandomGoals());
	this->setSecondGoals(getRandomGoals());
}

int Game::getRandomGoals()
{
	srand(time(0));
	return rand() % 21;
}
