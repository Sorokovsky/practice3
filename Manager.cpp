#pragma once
#include "Manager.h"
Manager::Manager(
	string stadiumTypesFile,
	string stadiumsFile,
	string positionsFile,
	string coachesFile,
	string teamsFile,
	string playersFile,
	string gamesFile
)
{
	this->stadiumTypesFile = stadiumTypesFile;
	this->stadiumsFile = stadiumsFile;
	this->positionsFile = positionsFile;
	this->coachesFile = coachesFile;
	this->teamsFile = teamsFile;
	this->playersFile = playersFile;
	this->gamesFile = gamesFile;
}

template<class T>
void Manager::create(LinkedList<T>& list, T data)
{
	list.create(data);
}

template<class T>
void Manager::insert(LinkedList<T>& list, int index, T data)
{
	list.insert(data, index);
}

template<class T>
void Manager::sort(LinkedList<T>& list, bool predicate(T first, T second))
{
	list.sort(predicate);
}

template<class T, class C>
void Manager::remove(LinkedList<T>& list, bool predicate(T item, C comparer), C comparer)
{
	list.remove(predicate, comparer);
}

template<class T, class C>
LinkedList<T> Manager::find(LinkedList<T>& list, bool predicate(T item, C comparer), C comparer)
{
	return list.find(predicate, comparer);
}
