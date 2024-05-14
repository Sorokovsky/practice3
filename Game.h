#pragma once
#include <iostream>
#include "Stadium.h"
#include "Team.h"
#include "Date.h"
#include "Time.h"
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
		Date dateOfGame,
		Time timeOfGame,
		Team secondTeam
	);
	Game(
		Stadium stadium,
		Team team,
		string gameCode,
		string gameName,
		Date dateOfGame,
		Time timeOfGame,
		Team secondTeam
	);
	Game();
	string getGameCode();
	string getGameName();
	Date getDateOfGame();
	Time getTimeOfGame();
	void setGameCode(string gameCode);
	void setGameName(string gameName);
	void setDateOfGame(Date dateOfGame);
	void setTimeOfGame(Time timeOfGame);
	void print() override;
protected:
	void printHead() override;
	void printBody() override;
	void printEnd() override;
private:
	string gameCode;
	string gameName;
	Date dateOfGame;
	Time timeOfGame;
};