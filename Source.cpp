#include<iostream>
#include "StadiumType.h"
#include "Manager.h"
#include "constants.h"
using namespace std;
int main()
{
	Manager manager(stadiumTypesFile, stadiumsFile, teamsFile, coachesFile, gamesFile, playersFile, positionsFile);
	manager.loadStadiumTypes();
	return 0;
}