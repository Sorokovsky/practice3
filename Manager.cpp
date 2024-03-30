#include "Manager.h"

Manager::Manager(
	string stadiumTypesFile, 
	string stadiumsFile, 
	string teamsFile, 
	string coachesFile, 
	string gamesFile, 
	string playersFile, 
	string positionsFile
)
{
	this->setStadiumTypesFile(stadiumTypesFile);
	this->setStadiumsFile(stadiumsFile);
	this->setTeamsFile(teamsFile);
	this->setCoachesFile(coachesFile);
	this->setGamesFile(gamesFile);
	this->setPlayersFile(playersFile);
	this->setPositionsFile(positionsFile);
}

void Manager::setStadiumTypesFile(string filePath)
{
	this->stdadiumTypesFile = filePath;
}

void Manager::setStadiumsFile(string filePath)
{
	this->stadiumsFile = filePath;
}

void Manager::setTeamsFile(string filePath)
{
	this->teamsFile = filePath;
}

void Manager::setCoachesFile(string filePath)
{
	this->coachesFile = filePath;
}

void Manager::setGamesFile(string filePath)
{
	this->gamesFile = gamesFile;
}

void Manager::setPlayersFile(string filePath)
{
	this->playersFile = filePath;
}

void Manager::setPositionsFile(string filePath)
{
	this->positionsFiles = filePath;
}
