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

void Manager::sortPlayers(bool canSwap(Player i1, Player i2))
{
	this->sort<Player>(&this->players, this->playersFile, canSwap);
}

void Manager::findGames(bool isNeed(Game item))
{
	this->find<Game>(&this->games, isNeed);
}

void Manager::findPlayers(bool isNeed(Player player))
{
	this->find<Player>(&this->players, isNeed);
}

void Manager::findStadium(bool isNeed(Stadium stadium, StadiumType type), StadiumType comparer)
{
	this->find<Stadium, StadiumType>(&this->stadiums, isNeed, comparer);
}

double Manager::avarageAgeOfPlayers()
{
	double sum = 0.0;
	for (int i = 0; i < this->players.size(); i++)
	{
		sum += (Manager::today.getYear() - this->players.at(i).getBirthday().getYear());
	}
	return sum / this->players.size();
}

Date Manager::dateOfFirstGame()
{
	Date date;
	if (this->games.size() == 0)
	{
		cout << "\n \t No games";
		return date;
	}
	date = this->games.at(0).getDateOfGame();
	for (int i = 0; i < this->games.size(); i++)
	{
		if (Date::compare(this->games.at(i).getDateOfGame(), date) == Equels::secondMore)
		{
			date = this->games.at(i).getDateOfGame();
		}
	}
	return date;
}

void Manager::changeStadiumPhone(bool canEdit(Stadium stadium, Stadium comparer))
{
	string phone;
	cout << "\n \t Enter phone: "; cin >> phone;
	cout << "\n \n Enter stadium: "; Stadium stadium = enterStadium();
	for (int i = 0; i < this->stadiums.size(); i++)
	{
		if (canEdit(this->stadiums.at(i), stadium))
		{
			this->stadiums.at(i).setStadiumPhoneNumber(phone);
		}
	}
}

void Manager::deletePlayer(bool canDelete(Player item, string code), string code)
{
	for (int i = 0; i < this->players.size(); i++)
	{
		if (canDelete(this->players.at(i), code))
		{
			this->players.erase(this->players.begin() + i);
		}
	}
}

void Manager::copyPlayerByYear(vector<Player>* newList, bool canCopy(Player item, int comparer), int comparer)
{
	for (int i = 0; i < this->players.size(); i++)
	{
		if (canCopy(this->players.at(i), comparer))
		{
			newList->push_back(this->players.at(i));
		}
	}
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

template<typename T>
void Manager::sort(vector<T>* list, string filePath, bool canSwap(T i1, T i2))
{
	std::sort(list->begin(), list->end(), canSwap);
	if (list->size() == 0)
		return;
}

template<typename T>
void Manager::find(vector<T>* list, bool isNeed(T item))
{
	for (int i = 0; i < list->size(); i++)
	{
		if (isNeed(list->at(i)))
		{
			list->at(i).print();
		}
	}
}

template<typename T, typename R>

void Manager::find(vector<T>* list, bool isNeed(T item, R comparer), R comparer)
{
	for (int i = 0; i < list->size(); i++)
	{
		if (isNeed(list->at(i), comparer))
		{
			list->at(i).print();
		}
	}
}

Date Manager::today = Date();