#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include "StadiumType.h"
#include "Stadium.h"
#include "Position.h"
#include "Coach.h"
#include "Team.h"
#include "Player.h"
#include "Game.h"
#define IsDev true
using namespace std;
class Manager
{
public:
	Manager(
		string stadiumTypesFile,
		string stadiumsFile,
		string positionsFile,
		string coachesFile,
		string teamsFile,
		string playersFile,
		string gamesFile
	);
	void add(StadiumType item);
	void add(Stadium item);
	void add(Position item);
	void add(Coach item);
	void add(Team item);
	void add(Player item);
	void add(Game item);
	void loadStadiumTypes();
	void loadStadiums();
	void loadPositions();
	void loadCoaches();
	void loadTeams();
	void loadPlayers();
	void loadGames();
	void loadAll();
	void showStadiumTypes();
	void showStadiums();
	void showPositions();
	void showCoaches();
	void showTeams();
	void showPlayers();
	void showGames();
	template<typename C>
	vector<StadiumType> findStadiumTypes(bool isNeed(StadiumType item, C comparer), C comparer);
	template<typename C>
	vector<Stadium> findStadiums(bool isNeed(Stadium item, C comparer), C comparer);
	template<typename C>
	vector<Position> findPositions(bool isNeed(Position item, C comparer), C comparer);
	template<typename C>
	vector<Coach> findCoaches(bool isNeed(Coach item, C comparer), C comparer);
	template<typename C>
	vector<Team> findTeams(bool isNeed(Team item, C comparer), C comparer);
	template<typename C>
	vector<Player> findPlayers(bool isNeed(Player item, C comparer), C comparer);
	template<typename C>
	vector<Game> findCoaches(bool isNeed(Game item, C comparer), C comparer);
	void sortStadiumTypes(bool canSwap(StadiumType i1, StadiumType i2));
	void sortStadiums(bool canSwap(Stadium i1, Stadium i2));
	void sortPositions(bool canSwap(Position i1, Position i2));
	void sortCoaches(bool canSwap(Coach i1, Coach i2));
	void sortTeams(bool canSwap(Team i1, Team i2));
	void sortPlayers(bool canSwap(Player i1, Player i2));
	void sortGames(bool canSwap(Game i1, Game i2));
private:
	template<typename T>
	void add(T item, vector<T>* list, string& filePath);
	template<typename T>
	void load(vector<T>* list, const string& filePath);
	template<typename T>
	void showAll(vector<T>* list);
	template<typename T, typename C>
	vector<T> find(vector<T>* list, bool isNeed(T item, C comparer), C comparer);
	template<typename T>
	void sort(vector<T>* list, bool canSwap(T i1, T i2));
	string stadiumTypesFile;
	string stadiumsFile;
	string positionsFile;
	string coachesFile;
	string teamsFile;
	string playersFile;
	string gamesFile;
	vector<StadiumType> stadiumTypes;
	vector<Stadium> stadiums;
	vector<Position> positions;
	vector<Coach> coaches;
	vector<Team> teams;
	vector<Player> players;
	vector<Game> games;
};
