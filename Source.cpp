#include<iostream>
#include "StadiumType.h"
#include "Stadium.h"
#include "Position.h"
#include "Coach.h"
#include "Team.h"
#include "Player.h"
#include "Game.h"
#include "Repository.h"
#include "helpers.h"
using namespace std;
template<class T>
void showItem(T item, int index)
{
	cout << "\n \t #" << index + 1;
	item.print();
}
int main()
{
	Repository<StadiumType> stadiumTypes("stadium-types");
	Repository<Stadium> stadiums("stadiums");
	Repository<Position> positions("positions");
	Repository<Coach> coaches("coaches");
	Repository<Team> teams("teams");
	Repository<Player> players("players");
	Repository<Game> games("games");
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
			stadiumTypes.add(type);
			break;
		}
		case 2:
		{
			cout << "\n \t Stadium types";
			stadiumTypes.loop(showItem);
			break;
		}
		case 3:
		{
			Stadium stadium = enterStadium();
			stadiums.add(stadium);
			break;
		}
		case 4:
		{
			cout << "\n \t Stadiums";
			stadiums.loop(showItem);
			break;
		}
		case 5:
		{
			Position position = enterPosition();
			positions.add(position);
			break;
		}
		case 6:
		{
			cout << "\n \t Positions";
			positions.loop(showItem);
			break;
		}
		case 7:
		{
			Coach coach = enterCoach();
			coaches.add(coach);
			break;
		}
		case 8:
		{
			cout << "\n \t Coaches";
			coaches.loop(showItem);
			break;
		}
		case 9:
		{
			Team team = enterTeam();
			teams.add(team);
			break;
		}
		case 10:
		{
			cout << "\n \t Teams";
			teams.loop(showItem);
			break;
		}
		case 11:
		{
			Player player = enterPlayer();
			players.add(player);
			break;
		}
		case 12:
		{
			cout << "\n \t Players";
			players.loop(showItem);
			break;
		}
		case 13:
		{
			Game game = enterGame();
			games.add(game);
			break;
		}
		case 14:
		{
			cout << "\n \t Games";
			games.loop(showItem);
			break;
		}
		case 15:
		{
			players.sort(orderPlayersByDate);
			players.loop(showItem);
			break;
		}
		case 16:
		{
			int month = 7;
			LinkedList<Game> gamesInJuly = games.find<int>(gamesInMonth, month);
			cout << "\n \t Games in July";
			gamesInJuly.loop(showItem);
			break;
		}
		case 17:
		{
			LinkedList<Player> playersYounger20Years = players.find<int>(findPlayerYounger, 20);
			cout << "\n \t Players younger 20 year";
			playersYounger20Years.loop(showItem);
			break;
		}
		case 18:
		{
			cout << "\n \t Enter type fo search.";
			StadiumType type = enterType();
			LinkedList<Stadium> founded = stadiums.find<StadiumType>(byStatiumType, type);
			cout << "\n \t Founded: ";
			founded.loop(showItem);
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