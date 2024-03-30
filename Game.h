#pragma once
#include<iostream>
#include "Stadium.h"
#include "Team.h"
using namespace std;
class Game : public Stadium, public Team
{
public:
	Game(string positionName,
		string requirements,
		int salary,
		string coachPhoneNumber,
		string coachAddress,
		int age,
		string teamCode,
		string teamName,
		string codeOfStadiumType,
		string nameOfStadiumType,
		string stadiumCode,
		string stadiumName,
		string stadiumAddress,
		string stadiumPhoneNumber,
		string masterHead,
		string notes,
		string gameCode,
		string gameName,
		time_t dateOfGame,
		time_t timeOfGame
	);
	Game(
		Stadium stadium, 
		Team team,
		string gameCode,
		string gameName,
		time_t dateOfGame,
		time_t timeOfGame
	);
	string getGameCode();
	string getGameName();
	time_t getDateOfGame();
	time_t getTimeOfGame();
	void setGameCode(string gameCode);
	void setGameName(string gameName);
	void setDateOfGame(time_t dateOfGame);
	void setTimeOfGame(time_t timeOfGame);
private:
	string gameCode;
	string gameName;
	time_t dateOfGame;
	time_t timeOfGame;
};