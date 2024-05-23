#pragma once
#include "Team.h"
#include "Game.h"
class Rating
{
public:
	Rating();
	Rating(string name, int count, int score, int goals, int wrongs);

	void setName(string name);
	void setCountOfGame(int count);
	void setScore(int score);
	void setGoals(int goals);
	void setWrongs(int wrongs);

	string getName();
	int getCountOfGame();
	int getScore();
	int getGoals();
	int getWrongs();
private:
	string name;
	int countOfGame;
	int score;
	int goals;
	int wrongs;
};