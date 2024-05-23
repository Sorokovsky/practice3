#include "Rating.h"

Rating::Rating()
{
}

Rating::Rating(string name, int count, int score, int goals, int wrongs)
{
	this->setName(name);
	this->setCountOfGame(count);
	this->setScore(score);
	this->setGoals(goals);
	this->setWrongs(wrongs);
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

void Rating::setGoals(int goals)
{
	this->goals = goals;
}

void Rating::setWrongs(int wrongs)
{
	this->wrongs = wrongs;
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

int Rating::getGoals()
{
	return this->goals;
}

int Rating::getWrongs()
{
	return this->wrongs;
}