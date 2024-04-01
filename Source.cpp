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
		{
			return 0;
			break;
		}
		case 1:
		{
			cout << "\n \t Stadiums";
			manager.showStadiums();
			break;
		}
		case 2:
		{
			manager.sortPlayers(comparePlayersByDescDates);
			manager.showPlayers();
			break;
		}
		case 3:
		{
			manager.findGames(compareGameInJuly);
			break;
		}
		case 4:
		{
			manager.findPlayers(comparePlayerBy20Years);
			break;
		}
		case 5:
		{
			StadiumType type = enterType();
			manager.findStadium(compareStadiumByType, type);
			break;
		}
		case 6:
		{
			manager.findGames(compareGameAugust2012);
			break;
		}
		case 7:
		{
			cout << "\n \t Avarage of players age: " << manager.avarageAgeOfPlayers();
			break;
		}
		case 8:
		{
			cout << "\n \t Date of first game: "; 
			Date date = manager.dateOfFirstGame();
			cout << "{ Year: " << date.getYear() << ", Month: " << date.monthToString() << ", Day: " << date.getDay() << " }";
			break;
		}
		case 9:
		{
			Game game = enterGame();
			manager.add(game);
			cout << "\n \t Games";
			manager.showGames();
			break;
		}
		case 10:
		{
			
			manager.changeStadiumPhone(canStadiumEdit);
			cout << "\n \t Stadiums";
			manager.showStadiums();
			break;
		}
		case 11:
		{
			string code;
			cout << "\n \t Enter player code: "; cin >> code;
			manager.deletePlayer(canDeletePlayer, code);
			cout << "\n \t Players: ";
			manager.showPlayers();
		}
		default:
			cout << "\n \t Try again.";
			break;
		}
	}
}