#pragma once
#include <iostream>
#include "List.h"
#include <algorithm>
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
	template<class C>
	void findStadiumTypes(List<StadiumType>* founded, bool isNeed(StadiumType item, C comparer), C comparer);
	template<class C>
	void findStadiums(List<Stadium>* founded, bool isNeed(Stadium item, C comparer), C comparer);
	template<class C>
	void findPositions(List<Position>* founded, bool isNeed(Position item, C comparer), C comparer);
	template<class C>
	void findCoaches(List<Coach>* founded, bool isNeed(Coach item, C comparer), C comparer);
	template<class C>
	void findTeams(List<Team>* founded, bool isNeed(Team item, C comparer), C comparer);
	template<class C>
	void findPlayers(List<Player>* founded, bool isNeed(Player item, C comparer), C comparer);
	template<class T>
	void findGames(List<Game>* founded, bool isNeed(Game item, T comparer), T comparer);
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
	template<class C>
	void removeStadiumType(bool canRemove(StadiumType item, C comparer), C Comparer);
	template<class C>
	void removeStadium(bool canRemove(Stadium item, C comparer), C Comparer);
	template<class C>
	void removePosition(bool canRemove(Position item, C comparer), C Comparer);
	template<class C>
	void removeCoach(bool canRemove(Coach item, C comparer), C Comparer);
	template<class C>
	void removeTeam(bool canRemove(Team item, C comparer), C Comparer);
	template<class C>
	void removePlayer(bool canRemove(Player item, C comparer), C Comparer);
	template<class C>
	void removeGame(bool canRemove(Game item, C comparer), C Comparer);
	template<class T>
	static void show(T item, int index);
private:
	template<class T>
	void add(T item, List<T>* list, string& filePath);
	template<class T>
	void load(List<T>* list, const string& filePath);
	template<class T>
	void showAll(List<T>* list);
	template<class T, class C>
	void find(List<T>* founded, List<T>* list, bool isNeed(T item, C comparer), C comparer);
	template<class T>
	void sort(List<T>* list, bool canSwap(T i1, T i2));
	template<class T>
	void save(List<T>* list, string& filePath);
	template<class T, class C>
	void remove(List<T>* list, bool canRemove(T item, C comparer), C comparer);
	string stadiumTypesFile;
	string stadiumsFile;
	string positionsFile;
	string coachesFile;
	string teamsFile;
	string playersFile;
	string gamesFile;
	List<StadiumType> stadiumTypes;
	List<Stadium> stadiums;
	List<Position> positions;
	List<Coach> coaches;
	List<Team> teams;
	List<Player> players;
	List<Game> games;
};
//#include "Manager.cpp"