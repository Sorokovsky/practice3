#pragma once
#include<iostream>
#include <ctime>
#include "StadiumType.h"
#include "Stadium.h"
#include "Position.h"
#include "Coach.h"
#include "Team.h"
#include "Date.h"
#include "Player.h"
#include "Game.h"
#include "Time.h"
using namespace std;
Date enterDate();
Time enterTime();
StadiumType enterType();
Stadium enterStadium();
Position enterPosition();
Coach enterCoach();
Team enterTeam();
Player enterPlayer();
Game enterGame();
int chooseOperation();
bool orderPlayersByDate(Player i1, Player i2);
bool gamesInMonth(Game item, int comparer);
bool findPlayerYounger(Player item, int year);
bool byStadiumType(Stadium item, StadiumType type);
bool findGameByMonthAndYear(Game item, Date date);
int getAge(Date birthday);
int accomulateAvarageAge(Player, int result);
bool sortGamesByDate(Game i1, Game i2);
bool findStadiumByCodePredicate(Stadium item, string code);
bool findPlayerByCode(Player item, string code);
bool findPlayerByYear(Player item, int year);
bool findGameByDate(Game game, Date date);