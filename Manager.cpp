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
	this->loadAll();
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

template<typename C>
void Manager::findStadiumTypes(vector<StadiumType>* founded, bool isNeed(StadiumType item, C comparer), C comparer)
{
	this->find<StadiumType, C>(founded, &this->stadiumTypes, isNeed, comparer);
}

template<typename C>
void Manager::findStadiums(vector<Stadium>* founded, bool isNeed(Stadium item, C comparer), C comparer)
{
	this->find<Stadium, C>(founded, &this->stadiums, isNeed, comparer);
}

template<typename C>
void Manager::findPositions(vector<Position>* founded, bool isNeed(Position item, C comparer), C comparer)
{
	this->find<Position, C>(founded, &this->positions, isNeed, comparer);
}

template<typename C>
void Manager::findCoaches(vector<Coach>* founded, bool isNeed(Coach item, C comparer), C comparer)
{
	this->find<Coach, C>(founded, &this->coaches, isNeed, comparer);
}

template<typename C>
void Manager::findTeams(vector<Team>* founded, bool isNeed(Team item, C comparer), C comparer)
{
	this->find<Team, C>(founded, founded, &this->teams, isNeed, comparer);
}

template<typename C>
void Manager::findPlayers(vector<Player>* founded, bool isNeed(Player item, C comparer), C comparer)
{
	this->find<Player, C>(founded, &this->players, isNeed, comparer);
}

template<typename C>
void Manager::findGames(vector<Game>* founded, bool isNeed(Game item, C comparer), C comparer)
{
	this->find<Game, C>(founded, &this->games, isNeed, comparer);
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
	list->clear();
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
		cout << "\n \t #" << i + 1;
		list->at(i).print();
	}
}

template<typename T, typename C>
void Manager::find(vector<T>* founded, vector<T>* list, bool isNeed(T item, C comparer), C comparer)
{
	if (founded == nullptr || list == nullptr)
		return;

	for (int i = 0; i < list->size(); i++)
	{
		if (isNeed(list->at(i), comparer))
		{
			founded->push_back(list->at(i));
		}
	}
}

template<typename T>
void Manager::sort(vector<T>* list, bool canSwap(T i1, T i2))
{
	std::sort(list->begin(), list->end(), canSwap);
}

template<typename T>
void Manager::save(vector<T>* list, string& filePath)
{
	ofstream file(filePath, ios::binary | ios::app);
	if (!file)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << " not opened";
		return;
	}
	file.clear();
	for (int i = 0; i < list->size(); i++)
	{
		T item = list->at(i);
		file.write(reinterpret_cast<char*>(&item), sizeof(item));
	}
	file.close();
}

template<typename T>
void Manager::remove(vector<T>* list, bool canRemove(T item))
{
	list->erase(std::remove_if(list->begin(), list->end(), canRemove), list->end());
}

void Manager::sortStadiumTypes(bool canSwap(StadiumType i1, StadiumType i2))
{
	this->sort(&this->stadiumTypes, canSwap);
	this->saveStadiumTypes();
}

void Manager::sortStadiums(bool canSwap(Stadium i1, Stadium i2))
{
	this->sort(&this->stadiums, canSwap);
	this->saveStadiums();
}

void Manager::sortPositions(bool canSwap(Position i1, Position i2))
{
	this->sort(&this->positions, canSwap);
	this->savePositions();
}

void Manager::sortCoaches(bool canSwap(Coach i1, Coach i2))
{
	this->sort(&this->coaches, canSwap);
	this->savePositions();
}

void Manager::sortTeams(bool canSwap(Team i1, Team i2))
{
	this->sort(&this->teams, canSwap);
	this->saveTeams();
}

void Manager::sortPlayers(bool canSwap(Player i1, Player i2))
{
	this->sort(&this->players, canSwap);
	this->savePlayers();
}

void Manager::sortGames(bool canSwap(Game i1, Game i2))
{
	this->sort(&this->games, canSwap);
	this->saveGames();
}

void Manager::saveStadiumTypes()
{
	this->save<StadiumType>(&this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::saveStadiums()
{
	this->save<Stadium>(&this->stadiums, this->stadiumsFile);
}

void Manager::savePositions()
{
	this->save<Position>(&this->positions, this->positionsFile);
}

void Manager::saveCoaches()
{
	this->save<Coach>(&this->coaches, this->coachesFile);
}

void Manager::saveTeams()
{
	this->save<Team>(&this->teams, this->teamsFile);
}

void Manager::savePlayers()
{
	this->save<Player>(&this->players, this->playersFile);
}

void Manager::saveGames()
{
	this->save<Game>(&this->games, this->gamesFile);
}

void Manager::saveAll()
{
	this->saveStadiumTypes();
	this->saveStadiums();
	this->savePositions();
	this->saveCoaches();
	this->saveTeams();
	this->savePlayers();
	this->saveGames();
}

void Manager::removeStadiumType(bool canRemove(StadiumType item))
{
	this->remove<StadiumType>(&this->stadiumTypes, canRemove);
	this->saveStadiumTypes();
}

void Manager::removeStadium(bool canRemove(Stadium item))
{
	this->remove<Stadium>(&this->stadiums, canRemove);
	this->saveStadiums();
}

void Manager::removePosition(bool canRemove(Position item))
{
	this->remove<Position>(&this->positions, canRemove);
	this->savePositions();
}

void Manager::removeCoach(bool canRemove(Coach item))
{
	this->remove<Coach>(&this->coaches, canRemove);
	this->saveCoaches();
}

void Manager::removeTeam(bool canRemove(Team item))
{
	this->remove<Team>(&this->teams, canRemove);
	this->saveTeams();
}

void Manager::removePlayer(bool canRemove(Player item))
{
	this->remove<Player>(&this->players, canRemove);
	this->savePlayers();
}

void Manager::removeGame(bool canRemove(Game item))
{
	this->remove<Game>(&this->games, canRemove);
	this->saveGames();
}
