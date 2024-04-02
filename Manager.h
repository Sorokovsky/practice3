#pragma once
#include<iostream>
#include<vector>
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
private:
	template<typename T>
	void add(T item, vector<T>* list, string& filePath);
	template<typename T>
	void load(vector<T>* list, const string& filePath);
	template<typename T>
	void showAll(vector<T>* list);
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