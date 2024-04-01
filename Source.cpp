#include<iostream>
#include "StadiumType.h"
#include "Manager.h"
#include "constants.h"
#include "helpers.h"
using namespace std;
int main()
{
	Manager manager(stadiumTypesFile, stadiumsFile, teamsFile, coachesFile, gamesFile, playersFile, positionsFile);
	manager.loadAll();
	manager.showStadiumTypes();
	return 0;
}