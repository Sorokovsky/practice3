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

template<class C>
void Manager::findStadiumTypes(List<StadiumType>* founded, bool isNeed(StadiumType item, C comparer), C comparer)
{
	this->find<StadiumType, C>(founded, &this->stadiumTypes, isNeed, comparer);
}

template<class C>
void Manager::findStadiums(List<Stadium>* founded, bool isNeed(Stadium item, C comparer), C comparer)
{
	this->find<Stadium, C>(founded, &this->stadiums, isNeed, comparer);
}

template<class C>
void Manager::findPositions(List<Position>* founded, bool isNeed(Position item, C comparer), C comparer)
{
	this->find<Position, C>(founded, &this->positions, isNeed, comparer);
}

template<class C>
void Manager::findCoaches(List<Coach>* founded, bool isNeed(Coach item, C comparer), C comparer)
{
	this->find<Coach, C>(founded, &this->coaches, isNeed, comparer);
}

template<class C>
void Manager::findTeams(List<Team>* founded, bool isNeed(Team item, C comparer), C comparer)
{
	this->find<Team, C>(founded, founded, &this->teams, isNeed, comparer);
}

template<class C>
void Manager::findPlayers(List<Player>* founded, bool isNeed(Player item, C comparer), C comparer)
{
	this->find<Player, C>(founded, &this->players, isNeed, comparer);
}

template<class T>
void Manager::findGames(List<Game>* founded, bool isNeed(Game item, T comparer), T comparer)
{
	this->find<Game, T>(founded, &this->games, isNeed, comparer);
}

template<class T>
void Manager::add(T item, List<T>* list, string& filePath)
{
	ofstream file(filePath, ios::binary | ios::app);
	if (!file)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << " not opened";
		return;
	}
	list->create(item);
	file.write(reinterpret_cast<char*>(&item), sizeof(item));
	file.close();
}

template<class T>
void Manager::load(List<T>* list, const string& filePath)
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
		list->create(item);
	}

	file.close();
}



template<class T>
void Manager::showAll(List<T>* list)
{
	list->loop(Manager::show);
}

template<class T, class C>
void Manager::find(List<T>* founded, List<T>* list, bool isNeed(T item, C comparer), C comparer)
{
	if (founded == nullptr || list == nullptr)
		return;

	*founded = list->find<C>(isNeed);
}

template<class T>
void Manager::sort(List<T>* list, bool canSwap(T i1, T i2))
{
	list->sort(canSwap);
}

template<class T>
void Manager::save(List<T>* list, string& filePath)
{
	ofstream file(filePath, ios::binary | ios::app);
	if (!file)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << " not opened";
		return;
	}
	file.clear();
	Node<T>* current = list->getHead();
	while (current != NULL)
	{
		T item = current->getData();
		file.write(reinterpret_cast<char*>(&item), sizeof(item));
		current = current->getNext();
	}
	file.close();
}

template<class T, class C>
void Manager::remove(List<T>* list, bool canRemove(T item, C comparer), C comparer)
{
	list->remove<C>(canRemove, comparer);
}

template<class T>
void Manager::show(T item, int index)
{
		cout << "\n \n #" << index + 1;
		item.print();
}

void Manager::sortStadiumTypes(bool canSwap(StadiumType i1, StadiumType i2))
{
	this->sort<StadiumType>(&this->stadiumTypes, canSwap);
	this->saveStadiumTypes();
}

void Manager::sortStadiums(bool canSwap(Stadium i1, Stadium i2))
{
	this->sort<Stadium>(&this->stadiums, canSwap);
	this->saveStadiums();
}

void Manager::sortPositions(bool canSwap(Position i1, Position i2))
{
	this->sort<Position>(&this->positions, canSwap);
	this->savePositions();
}

void Manager::sortCoaches(bool canSwap(Coach i1, Coach i2))
{
	this->sort<Coach>(&this->coaches, canSwap);
	this->savePositions();
}

void Manager::sortTeams(bool canSwap(Team i1, Team i2))
{
	this->sort<Team>(&this->teams, canSwap);
	this->saveTeams();
}

void Manager::sortPlayers(bool canSwap(Player i1, Player i2))
{
	this->sort<Player>(&this->players, canSwap);
	this->savePlayers();
}

void Manager::sortGames(bool canSwap(Game i1, Game i2))
{
	this->sort<Game>(&this->games, canSwap);
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

template<class C>
void Manager::removeStadiumType(bool canRemove(StadiumType item, C comparer), C comparer)
{
	this->remove<StadiumType>(&this->stadiumTypes, canRemove, comparer);
	this->saveStadiumTypes();
}

template<class C>
void Manager::removeStadium(bool canRemove(Stadium item, C comparer), C comparer)
{
	this->remove<Stadium>(&this->stadiums, canRemove, comparer);
	this->saveStadiums();
}

template<class C>
void Manager::removePosition(bool canRemove(Position item, C comparer), C comparer)
{
	this->remove<Position>(&this->positions, canRemove, comparer);
	this->savePositions();
}

template<class C>
void Manager::removeCoach(bool canRemove(Coach item, C comparer), C comparer)
{
	this->remove<Coach>(&this->coaches, canRemove, comparer);
	this->saveCoaches();
}

template<class C>
void Manager::removeTeam(bool canRemove(Team item, C comparer), C comparer)
{
	this->remove<Team>(&this->teams, canRemove, comparer);
	this->saveTeams();
}

template<class C>
void Manager::removePlayer(bool canRemove(Player item, C comparer), C comparer)
{
	this->remove<Player>(&this->players, canRemove, comparer);
	this->savePlayers();
}

template<class C>
void Manager::removeGame(bool canRemove(Game item, C comparer), C comparer)
{
	this->remove<Game>(&this->games, canRemove, comparer);
	this->saveGames();
}
