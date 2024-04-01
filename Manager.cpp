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

void Manager::add(StadiumType item)
{
	this->add<StadiumType>(item, &this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::add(Stadium item)
{
	this->add<Stadium>(item, &this->stadiums, this->stadiumsFile);
}

void Manager::add(Team item)
{
	this->add<Team>(item, &this->teams, this->teamsFile);
}

void Manager::add(Coach item)
{
	this->add<Coach>(item, &this->coaches, this->coachesFile);
}

void Manager::add(Game item)
{
	this->add<Game>(item, &this->games, this->gamesFile);
}

void Manager::add(Player item)
{
	this->add<Player>(item, &this->players, this->playersFile);
}

void Manager::add(Position item)
{
	this->add<Position>(item, &this->positions, this->positionsFiles);
}

void Manager::loadAll()
{
	this->loadStadiumTypes();
	this->loadStadiums();
	this->loadTeams();
	this->loadCoaches();
	this->loadPlayers();
	this->loadGames();
	this->loadPositions();
}

void Manager::loadStadiumTypes()
{
	this->load<StadiumType>(&this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::loadStadiums()
{
	this->load<Stadium>(&this->stadiums, this->stadiumsFile);
}

void Manager::loadTeams()
{
	this->load<Team>(&this->teams, this->teamsFile);
}

void Manager::loadCoaches()
{
	this->load<Coach>(&this->coaches, this->coachesFile);
}

void Manager::loadGames()
{
	this->load<Game>(&this->games, this->gamesFile);
}

void Manager::loadPlayers()
{
	this->load<Player>(&this->players, this->playersFile);
}

void Manager::loadPositions()
{
	this->load<Position>(&this->positions, this->positionsFiles);
}

void Manager::showStadiumTypes()
{
	this->showAll<StadiumType>(&this->stadiumTypes);
}

void Manager::showStadiums()
{
	this->showAll<Stadium>(&this->stadiums);
}

void Manager::showTeams()
{
	this->showAll<Team>(&this->teams);
}

void Manager::showCoaches()
{
	this->showAll<Coach>(&this->coaches);
}

void Manager::showGames()
{
	this->showAll<Game>(&this->games);
}

void Manager::showPlayers()
{
	this->showAll<Player>(&this->players);
}

void Manager::showPositions()
{
	this->showAll<Position>(&this->positions);
}

void Manager::setStadiumTypesFile(string filePath)
{
	this->stadiumTypesFile = filePath;
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

template<typename T>
void Manager::load(vector<T>* to, string filePath)
{
	ifstream file(filePath, ios::binary);
	if (!file.is_open()) {
		if (isDev)
		{
			std::cout << "\n \t File " << filePath << " undefined";
		}
		return;
	}

	T item;
	while (!file.eof()) {
		file.read((char*)&item, sizeof(T));
		if (file.eof()) break;
		to->push_back(item);
	}

	file.close();
}

template<typename T>
void Manager::add(T item, vector<T>* to, string filePath)
{
	ofstream file(filePath, ios::app);
	if (file.is_open() == false)
	{
		file = ofstream(filePath, ios::binary | ios::out);
	}
	if (file.is_open() == false)
	{
		return;
	}
	to->push_back(item);
	file.write((char*)&item, sizeof(T));
	file.close();
}

template<typename T>
void Manager::showAll(vector<T>* list)
{
	for (int i = 0; i < list->size(); i++)
	{
		list->at(i).print();
	}
}
