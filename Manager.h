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
private:
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