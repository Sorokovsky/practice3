#pragma once
#include<iostream>
#include "StadiumType.h"
#include "Stadium.h"
#include "Position.h"
#include "Coach.h"
#include "Team.h"
#include "Date.h"
#include "Player.h"
#include "Game.h"
#include "Time.h"
#include "Manager.h"
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
bool comparePlayersByDescDates(Player i1, Player i2);
bool compareGameInJuly(Game item);
bool comparePlayerBy20Years(Player item);
bool compareStadiumByType(Stadium item, StadiumType type);
bool compareGameAugust2012(Game item);
bool canStadiumEdit(Stadium stadium, Stadium comparer);
bool canDeletePlayer(Player item, string code);
bool canCopyPlayer(Player item, int year);
bool canDeleteGameByDate(Game item, Date comparer);
bool isNeedSadium(Stadium item, string code);