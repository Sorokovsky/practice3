#include "Rating.h"

Rating::Rating()
{
}

Rating::Rating(string name, int count, int score)
{
	this->setName(name);
	this->setCountOfGame(count);
	this->setScore(score);
}

void Rating::setName(string name)
{
	this->name = name;
}

void Rating::setCountOfGame(int count)
{
	this->countOfGame = count;
}

void Rating::setScore(int score)
{
	this->score = score;
}

string Rating::getName()
{
	return this->name;
}

int Rating::getCountOfGame()
{
	return this->countOfGame;
}

int Rating::getScore()
{
	return this->score;
}
