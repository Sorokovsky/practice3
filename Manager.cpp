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

void Manager::addStadiumType(StadiumType item)
{
	this->add<StadiumType>(item, &this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::loadStadiumTypes()
{
	this->load<StadiumType>(&this->stadiumTypes, this->stadiumTypesFile);
}

void Manager::showStadiumTypes()
{
	this->showAll<StadiumType>(&this->stadiumTypes);
}

template<typename T>
void Manager::add(T item, vector<T>* list, string filePath)
{
	ofstream file = ofstream(filePath, ios::binary | ios::app);
	if (file.is_open() == false)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << "not opened";
		return;
	}
	list->push_back(item);
	file.write((char*)&item, sizeof(T));
	file.close();
}

template<typename T>
void Manager::load(vector<T>* list, string filePath)
{
	ifstream file = ifstream(filePath, ios::binary | ios::in);
	if (file.is_open() == false)
	{
		if (IsDev)
			cout << "\n \t file " << filePath << "not opened";
		return;
	}
	T item;
	while (file.read((char*)&item, sizeof(T)))
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
