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

void Manager::add(StadiumType stadiumType)
{
	this->add<StadiumType>(this->stdadiumTypesFile, stadiumType, &this->stadiumTypes);
}

void Manager::add(Stadium stadium)
{
	this->add<Stadium>(this->stadiumsFile, stadium, &this->stadiums);
}

void Manager::add(Team team)
{
	this->add<Team>(this->teamsFile, team, &this->teams);
}

void Manager::add(Coach coach)
{
	this->add<Coach>(this->coachesFile, coach, &this->coaches);
}

void Manager::add(Game game)
{
	this->add<Game>(this->gamesFile, game, &this->games);
}

void Manager::add(Player player)
{
	this->add<Player>(this->playersFile, player, &this->players);
}

void Manager::add(Position position)
{
	this->add<Position>(this->positionsFiles, position, &this->positions);
}

void Manager::loadStadiumTypes()
{
	this->load<StadiumType>(this->stdadiumTypesFile, &this->stadiumTypes);
}

void Manager::loadStadiums()
{
	this->load<Stadium>(this->stadiumsFile, &this->stadiums);
}

void Manager::loadTeams()
{
	this->load<Team>(this->teamsFile, &this->teams);
}

void Manager::loadCoaches()
{
	this->load<Coach>(this->coachesFile, &this->coaches);
}

void Manager::loadGames()
{
	this->load<Game>(this->gamesFile, &this->games);
}

void Manager::loadPlayers()
{
	this->load<Player>(this->playersFile, &this->players);
}

void Manager::loadPositions()
{
	this->load<Position>(this->positionsFiles, &this->positions);
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

template<typename T>
void Manager::add(string filePath, T item, vector<T>* to)
{
	fstream file;
	bool isOpen = this->open(&file, filePath, ios::binary | ios::app);
	if (isOpen == false)
		return;
	file.write((char*)&item, sizeof(T));
	to->push_back(item);
	file.close();
}

template<typename T>
void Manager::load(string filePath, vector<T>* to)
{
	fstream file;
	bool isOpen = this->open(&file, filePath, ios::binary | ios::in);
	if (isOpen == false)
		return;
	T item;
	while (!file.eof())
	{
		file.read((char*)&item, sizeof(T));
		if (file.eof()) break;
		to->push_back(item);
	}
	file.close();
}
