#include<iostream>
#include "StadiumType.h"
#include "Manager.h"
#include "constants.h"
#include "helpers.h"
using namespace std;
int main()
{
	Manager manager(stadiumTypesFile, stadiumsFile, teamsFile, coachesFile, gamesFile, playersFile, positionsFile);
	cout << "\n \t Enter today date.";
	Manager::today = enterDate();
	manager.loadAll();
	while (true)
	{
		int operation = chooseOperation();
		switch (operation)
		{
		case 0:
			return 0;
			break;
		case 1:
			cout << "\n \t Stadiums";
			manager.showStadiums();
			break;
		case 2:
			manager.sortPlayers(comparePlayersByDescDates);
			manager.showPlayers();
			break;
		case 3:
			manager.findGames(compareGameInJuly);
			break;
		case 4:
			manager.findPlayers(comparePlayerBy20Years);
			break;
		case 5:
		{
			StadiumType type = enterType();
			manager.findStadium(compareStadiumByType, type);
			break;
		}
		case 6:
		{

		}
		default:
			cout << "\n \t Try again.";
			break;
		}
	}
}