#pragma once
#include<iostream> 
#include<vector>
#include<fstream>
#include "StadiumType.h"
#include "Stadium.h"
#include "Team.h"
#include "Coach.h"
#include "Game.h"
#include "Manager.h"
#include "Player.h"
#include "Position.h"
#define isDev false
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
private:
	template<typename T>
	void load(vector<T>* to, string filePath);
	template<typename T>
	void add(T item, vector<T>* to, string filePath);
	template<typename T>
	void showAll(vector<T>* list);
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