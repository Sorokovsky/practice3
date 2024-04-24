#pragma once
#include <iostream>
#include "LinkedList.h"
#include "StadiumType.h"
#include "Stadium.h"
#include "Position.h"
#include "Coach.h"
#include "Team.h"
#include "Player.h"
#include "Game.h"
using namespace std;
class Manager
{
	Manager(
		string stadiumTypesFile,
		string stadiumsFile,
		string positionsFile,
		string coachesFile,
		string teamsFile,
		string playersFile,
		string gamesFile
	);
private:
	template<class T>
	void create(LinkedList<T>& list, T data);
	template<class T>
	void insert(LinkedList<T>& list, int index, T data);
	template<class T>
	void sort(LinkedList<T>& list, bool predicate(T first, T second));
	template<class T, class C>
	void remove(LinkedList<T>& list, bool predicate(T item, C comparer), C comparer);
	template<class T, class C>
	LinkedList<T> find(LinkedList<T>& list, bool predicate(T item, C comparer), C comparer);
	LinkedList<StadiumType> stadiumTypes;
	LinkedList<Stadium> stadiums;
	LinkedList<Position> positions;
	LinkedList<Coach> coaches;
	LinkedList<Team> teams;
	LinkedList<Player> players;
	LinkedList<Game> games;
	string stadiumTypesFile;
	string stadiumsFile;
	string positionsFile;
	string coachesFile;
	string teamsFile;
	string playersFile;
	string gamesFile;
};