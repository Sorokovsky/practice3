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

	this->stadiumTypes = vector<StadiumType>();
}

void Manager::add(StadiumType stadiumType)
{
	fstream file;
	bool isOpen = this->open(&file, this->stdadiumTypesFile, ios::binary | ios::app);
	if (isOpen == false)
	{
		cout << "\n \t Error";
		return;
	}
	StadiumType item;
	file.write((char*)&item, sizeof(StadiumType));
	this->stadiumTypes.push_back(item);
	file.close();
}

void Manager::showStadiumTypes()
{
	for (int i = 0; i < this->stadiumTypes.size(); i++)
	{
		this->stadiumTypes.at(i).print();
	}
}

void Manager::loadStadiumTypes()
{
	fstream file;
	bool isOpen = this->open(&file, this->stdadiumTypesFile, ios::binary | ios::in);
	if (isOpen == false)
	{
		cout << "\n \t Error";
		return;
	}
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

bool Manager::open(fstream* file, string path, ios_base::openmode mode)
{
	*file = fstream(path, mode);
	if (file->is_open() == false)
	{
		cout << "\n \t file undefined. Error.";
		return false;
	}
	return true;
}
