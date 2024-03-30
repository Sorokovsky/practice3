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
	void add(StadiumType stadiumType);
	void add(Stadium stadium);
	void add(Team team);
	void add(Coach coach);
	void add(Game game);
	void add(Player player);
	void add(Position position);
	void showStadiumTypes();
	void loadStadiumTypes();
	void loadStadiums();
	void loadTeams();
	void loadCoaches();
	void loadGames();
	void loadPlayers();
	void loadPositions();
	void setStadiumTypesFile(string filePath);
	void setStadiumsFile(string filePath);
	void setTeamsFile(string filePath);
	void setCoachesFile(string filePath);
	void setGamesFile(string filePath);
	void setPlayersFile(string filePath);
	void setPositionsFile(string filePath);
private:
	bool open(fstream* file, string path, ios_base::openmode mode);
	vector<StadiumType> stadiumTypes;
	vector<Stadium> stadiums;
	vector<Team> teams;
	vector<Coach> coaches;
	vector<Game> games;
	vector<Player> players;
	vector<Position> positions;
	string stdadiumTypesFile;
	string stadiumsFile;
	string teamsFile;
	string coachesFile;
	string gamesFile;
	string playersFile;
	string positionsFiles;
};