#pragma once
#include<iostream> 
#include<vector>
#include<fstream>
#include "StadiumType.h"
#include "Stadium.h"
#include "Team.h"
#include "Coach.h"
#include "Game.h"
#include "Player.h"
#include "Position.h"
#include <algorithm>
#include "helpers.h"
#include "Date.h"
#define isDev true
using namespace std;
class Manager
{
public:
	Manager(
		string stadiumTypesFile,
		string stadiumsFile,
		string teamsFile,
		string coachesFile,
		string gamesFile,
		string playersFile,
		string positionsFile
	);
	void add(StadiumType item);
	void add(Stadium item);
	void add(Team item);
	void add(Coach item);
	void add(Game item);
	void add(Player item);
	void add(Position item);
	void loadAll();
	void loadStadiumTypes();
	void loadStadiums();
	void loadTeams();
	void loadCoaches();
	void loadGames();
	void loadPlayers();
	void loadPositions();
	void showStadiumTypes();
	void showStadiums();
	void showTeams();
	void showCoaches();
	void showGames();
	void showPlayers();
	void showPositions();
	void setStadiumTypesFile(string filePath);
	void setStadiumsFile(string filePath);
	void setTeamsFile(string filePath);
	void setCoachesFile(string filePath);
	void setGamesFile(string filePath);
	void setPlayersFile(string filePath);
	void setPositionsFile(string filePath);
	void sortPlayers(bool canSwap(Player i1, Player i2));
	void findGames(bool isNeed(Game item));
	void findPlayers(bool isNeed(Player player));
	void findStadium(bool isNeed(Stadium stadium, StadiumType type), StadiumType type);
	double avarageAgeOfPlayers();
	Date dateOfFirstGame();
	void changeStadiumPhone(bool canEdit(Stadium stadium, Stadium comparer));
	void deletePlayer(bool canDelete(Player item, string code), string code);
	void copyPlayerByYear(vector<Player>* newList, bool canCopy(Player item, int comparer), int comparer);
	void deleteGameByDate(bool canDelete(Game item, Date comparer), Date comparer);
	void getStadiumsWhichHavedGame();
	void surnameOfYangerPlayer();
	static Date today;
private:
	template<typename T>
	void load(vector<T>* to, string filePath);
	template<typename T>
	void add(T item, vector<T>* to, string filePath);
	template<typename T>
	void showAll(vector<T>* list);
	template<typename T>
	void sort(vector<T>* list, string filePath, bool canSwap(T i1, T i2));
	template<typename T>
	void find(vector<T>* list, bool isNeed(T item));
	template<typename T, typename R>
	void find(vector<T>* list, bool isNeed(T item, R comparer), R comparer);
	vector<StadiumType> stadiumTypes;
	vector<Stadium> stadiums;
	vector<Team> teams;
	vector<Coach> coaches;
	vector<Game> games;
	vector<Player> players;
	vector<Position> positions;
	string stadiumTypesFile;
	string stadiumsFile;
	string teamsFile;
	string coachesFile;
	string gamesFile;
	string playersFile;
	string positionsFiles;
};