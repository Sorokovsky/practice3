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
	void findStadiumTypes(vector<StadiumType>* founded, bool isNeed(StadiumType item, C comparer), C comparer);
	template<typename C>
	void findStadiums(vector<Stadium>* founded, bool isNeed(Stadium item, C comparer), C comparer);
	template<typename C>
	void findPositions(vector<Position>* founded, bool isNeed(Position item, C comparer), C comparer);
	template<typename C>
	void findCoaches(vector<Coach>* founded, bool isNeed(Coach item, C comparer), C comparer);
	template<typename C>
	void findTeams(vector<Team>* founded, bool isNeed(Team item, C comparer), C comparer);
	template<typename C>
	void findPlayers(vector<Player>* founded, bool isNeed(Player item, C comparer), C comparer);
	template<typename C>
	void findGames(vector<Game>* founded, bool isNeed(Game item, C comparer), C comparer);
	void sortStadiumTypes(bool canSwap(StadiumType i1, StadiumType i2));
	void sortStadiums(bool canSwap(Stadium i1, Stadium i2));
	void sortPositions(bool canSwap(Position i1, Position i2));
	void sortCoaches(bool canSwap(Coach i1, Coach i2));
	void sortTeams(bool canSwap(Team i1, Team i2));
	void sortPlayers(bool canSwap(Player i1, Player i2));
	void sortGames(bool canSwap(Game i1, Game i2));
	void saveStadiumTypes();
	void saveStadiums();
	void savePositions();
	void saveCoaches();
	void saveTeams();
	void savePlayers();
	void saveGames();
	void saveAll();
	void removeStadiumType(bool canRemove(StadiumType item));
	void removeStadium(bool canRemove(Stadium item));
	void removePosition(bool canRemove(Position item));
	void removeCoach(bool canRemove(Coach item));
	void removeTeam(bool canRemove(Team item));
	void removePlayer(bool canRemove(Player item));
	void removeGame(bool canRemove(Game item));
private:
	template<typename T>
	void add(T item, vector<T>* list, string& filePath);
	template<typename T>
	void load(vector<T>* list, const string& filePath);
	template<typename T>
	void showAll(vector<T>* list);
	template<typename T, typename C>
	void find(vector<T>* founded, vector<T>* list, bool isNeed(T item, C comparer), C comparer);
	template<typename T>
	void sort(vector<T>* list, bool canSwap(T i1, T i2));
	template<typename T>
	void save(vector<T>* list, string& filePath);
	template<typename T>
	void remove(vector<T>* list, bool canRemove(T item));
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
