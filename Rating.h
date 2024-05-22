#pragma once
#include "Team.h"
#include "Game.h"
class Rating
{
public:
	Rating();
	Rating(string name, int count, int score);

	void setName(string name);
	void setCountOfGame(int count);
	void setScore(int score);

	string getName();
	int getCountOfGame();
	int getScore();
private:
	string name;
	int countOfGame;
	int score;
};