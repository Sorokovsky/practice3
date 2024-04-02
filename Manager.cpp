#include "Manager.h"
Manager::Manager(
	string stadiumTypesFile,
	string stadiumsFile,
	string positionsFile,
	string coachesFile,
	string teamsFile,
	string playersFile,
	string gamesFile)
{
	this->stadiumTypesFile = stadiumTypesFile;
	this->stadiumsFile = stadiumsFile;
	this->positionsFile = positionsFile;
	this->coachesFile = coachesFile;
	this->teamsFile = teamsFile;
	this->playersFile = playersFile;
	this->gamesFile = gamesFile;
}

void Manager::add(StadiumType item)
{
	this->add<StadiumType>(item, &this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::add(Stadium item)
{
	this->add<Stadium>(item, &this->stadiums, this->stadiumsFile);
}

void Manager::add(Position item)
{
	this->add<Position>(item, &this->positions, this->positionsFile);
}

void Manager::add(Coach item)
{
	this->add<Coach>(item, &this->coaches, this->coachesFile);
}

void Manager::add(Team item)
{
	this->add<Team>(item, &this->teams, this->teamsFile);
}

void Manager::add(Player item)
{
	this->add<Player>(item, &this->players, this->playersFile);
}

void Manager::add(Game item)
{
	this->add<Game>(item, &this->games, this->gamesFile);
}

void Manager::loadStadiumTypes()
{
	this->load<StadiumType>(&this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::loadStadiums()
{
	this->load<Stadium>(&this->stadiums, this->stadiumsFile);
}

void Manager::loadPositions()
{
	this->load<Position>(&this->positions, this->positionsFile);
}

void Manager::loadCoaches()
{
	this->load<Coach>(&this->coaches, this->coachesFile);
}

void Manager::loadTeams()
{
	this->load<Team>(&this->teams, this->teamsFile);
}

void Manager::loadPlayers()
{
	this->load<Player>(&this->players, this->playersFile);
}

void Manager::loadGames()
{
	this->load<Game>(&this->games, this->gamesFile);
}

void Manager::loadAll()
{
	this->loadStadiumTypes();
	this->loadStadiums();
	this->loadPositions();
	this->loadCoaches();
	this->loadTeams();
	this->loadPlayers();
	this->loadGames();
}

void Manager::showStadiumTypes()
{
	this->showAll<StadiumType>(&this->stadiumTypes);
}

void Manager::showStadiums()
{
	this->showAll<Stadium>(&this->stadiums);
}

void Manager::showPositions()
{
	this->showAll<Position>(&this->positions);
}

void Manager::showCoaches()
{
	this->showAll<Coach>(&this->coaches);
}

void Manager::showTeams()
{
	this->showAll<Team>(&this->teams);
}

void Manager::showPlayers()
{
	this->showAll<Player>(&this->players);
}

void Manager::showGames()
{
	this->showAll<Game>(&this->games);
}

template<typename T>
void Manager::add(T item, vector<T>* list, string& filePath)
{
	ofstream file(filePath, ios::binary | ios::app);
	if (!file)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << " not opened";
		return;
	}
	list->push_back(item);
	file.write(reinterpret_cast<char*>(&item), sizeof(item));
	file.close();
}

template<typename T>
void Manager::load(vector<T>* list, const string& filePath)
{
	ifstream file(filePath, ios::binary | ios::in);
	if (!file)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << " not opened";
		return;
	}

	T item;
	while (file.read(reinterpret_cast<char*>(&item), sizeof(item)))
	{
		list->push_back(item);
	}

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
