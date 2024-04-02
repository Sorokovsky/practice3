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
			cout << "\n \t Stadium types";
			manager.showStadiumTypes();
			break;
		}
		case 3:
		{
			Stadium stadium = enterStadium();
			manager.add(stadium);
			break;
		}
		case 4:
		{
			cout << "\n \t Stadiums";
			manager.showStadiums();
			break;
		}
		case 5:
		{
			Position position = enterPosition();
			manager.add(position);
			break;
		}
		case 6:
		{
			cout << "\n \t Positions";
			manager.showPositions();
			break;
		}
		case 7:
		{
			Coach coach = enterCoach();
			manager.add(coach);
			break;
		}
		case 8:
		{
			cout << "\n \t Coaches";
			manager.showCoaches();
			break;
		}
		case 9:
		{
			Team team = enterTeam();
			manager.add(team);
			break;
		}
		case 10:
		{
			cout << "\n \t Teams";
			manager.showTeams();
			break;
		}
		case 11:
		{
			Player player = enterPlayer();
			manager.add(player);
			break;
		}
		case 12:
		{
			cout << "\n \t Players";
			manager.showPlayers();
			break;
		}
		case 13:
		{
			Game game = enterGame();
			manager.add(game);
			break;
		}
		case 14:
		{
			cout << "\n \t Games";
			manager.showGames();
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