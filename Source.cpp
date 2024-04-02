#include<iostream>
#include "StadiumType.h"
#include "constants.h"
#include "helpers.h"
#include "Manager.h"
using namespace std;
int main()
{
	Manager manager = Manager(stadiumTypesFile, stadiumsFile, positionsFile, coachesFile, teamsFile, playersFile, gamesFile);
	manager.loadAll();
	while (true)
	{
		int operation = chooseOperation();
		switch (operation)
		{
		case 0:
		{
			return 0;
			break;
		}
		case 1:
		{
			StadiumType type = enterType();
			manager.add(type);
			break;
		}
		case 2:
		{
			manager.showStadiumTypes();
			break;
		}
		default:
		{
			cout << "\n \t Try again.";
			break;
		}
		}
	}
	return 0;
}