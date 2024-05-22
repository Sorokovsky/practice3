#include <iostream>
#include <conio.h>
#include <map>
#include "StadiumType.h"
#include "Stadium.h"
#include "Position.h"
#include "Coach.h"
#include "Team.h"
#include "Player.h"
#include "Game.h"
#include "Repository.h"
#include "Rating.h"
#include "helpers.h"
using namespace std;
string adminPassword = "admin", password;
template<class T>
void showItem(T item, int index)
{
	cout << "\n \t #" << index + 1;
	item.print();
}
template<class T, class C>
bool findAllPredicate(T item, C comparer)
{
	return true;
}
int main()
{
	cout << "\n \t Enter password: "; cin >> password;
	bool isAdmin = password.compare(adminPassword) == 0;
	if (isAdmin)
	{
		cout << "\n \t You are admin.";
	}
	else
	{
		cout << "\n \t You are user.";
	}
	Repository<StadiumType> stadiumTypes("stadium-types");
	Repository<Stadium> stadiums("stadiums");
	Repository<Position> positions("positions");
	Repository<Coach> coaches("coaches");
	Repository<Team> teams("teams");
	Repository<Player> players("players");
	Repository<Game> games("games");
	Repository<Player> playersFrom1986("players-1986");
	while (true)
	{
		cout << "\n \t Press any key to continue."; _getch();
		int operation = chooseOperation();
		system("CLS");
		switch (operation)
		{
		case 0:
		{
			return 0;
			break;
		}
		case 1:
		{
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
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
			cout << "\n \t Enter type for search.";
			StadiumType type = enterType();
			LinkedList<Stadium> founded = stadiums.find<StadiumType>(byStadiumType, type);
			cout << "\n \t Founded: ";
			founded.loop(showItem);
			break;
		}
		case 19:
		{
			LinkedList<Game> result = games.find<Date>(findGameByMonthAndYear, Date(2012, 8, 0));
			cout << "\n \t Games in August 2012";
			for (int i = 0; i < result.getSize(); i++)
			{
				((Stadium)result[i]).print();
				((Team)result[i]).print();
			}
			break;
		}
		case 20:
		{
			int avarageAge = players.reduce<int>(accomulateAvarageAge, 0);
			cout << "\n \t Avarage age of players: " << avarageAge;
			break;
		}
		case 21:
		{
			LinkedList<Game> gamesList = games.find<void*>(findAllPredicate, NULL);
			gamesList.sort(sortGamesByDate);
			cout << "\n \t The date of first game.";
			gamesList[0].getDateOfGame().print();
			break;
		}
		case 22:
		{
			string stadiumCode, phone;
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
			cout << "\n \t Enter a stadium code for search: "; cin >> stadiumCode;
			cout << "\n \t Enter a new phone: "; cin >> phone;
			for (int i = 0; i < stadiums.getSize(); i++)
			{
				Stadium stadium = stadiums[i];
				if (stadium.getStadiumCode().compare(stadiumCode) == 0)
				{
					stadium.setStadiumPhoneNumber(phone);
					stadiums.edit(findStadiumByCodePredicate, stadiumCode, stadium);
				}
			}
			break;
		}
		case 23:
		{
			string code;
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
			cout << "\n \t Enter a player code: "; cin >> code;
			players.remove(findPlayerByCode, code);
			break;
		}
		case 24:
		{
			if (!isAdmin)
			{
				cout << "\n \t You must be admin.";
				continue;
			}
			LinkedList<Player> list = players.find(findPlayerByYear, 1986);
			for (int i = 0; i < list.getSize(); i++)
			{
				playersFrom1986.add(list[i]);
			}
			break;
		}
		case 25:
		{
			cout << "\n \t Player from 1986.";
			playersFrom1986.loop(showItem);
			break;
		}
		case 26:
		{
			if (!isAdmin)
			{
				cout << "\n \t You must be a admin";
				continue;
			}
			games.remove(findGameByDate, Date(2011, 9, 11));
			break;
		}
		case 27:
		{
			for (int i = 0; i < games.getSize(); i++)
			{
				Game game = games[i];
				if (Date::compare(game.getDateOfGame(), Date::getNow()) == Equels::secondMore)
				{
					((Stadium)game).print();
				}
			}
			break;
		}
		case 28:
		{
			if (players.getSize() > 0)
			{
				Player temp = players[0];
				for (int i = 0; i < players.getSize(); i++)
				{
					if (Date::compare(temp.getBirthday(), players[i].getBirthday()) == Equels::secondMore)
					{
						temp = players[i];
					}
				}
				cout << "\n \t Surname of youngest player: " << temp.getSurname();
			}
			else
			{
				cout << "\n  \t Players list is empty.";
			}
			break;
		}
		case 29:
		{
			LinkedList<Rating> ratings = LinkedList<Rating>();
			for (int i = 0; i < games.getSize(); i++)
			{
				Game game = games[i];
				Team firstTeam = (Team)game;
				Team secondTeam = game.getSecondTeam();
				bool foundFirst = false;
				bool foundSecond = false;
				for (int j = 0; j < ratings.getSize(); j++)
				{
					Rating rating = ratings[j];
					bool isFirstTeam = rating.getName().compare(firstTeam.getTeamName()) == 0;
					bool isSecondTeam = rating.getName().compare(secondTeam.getTeamName()) == 0;
					Equels wins;
					if (game.getFirstGoals() == game.getSecondGoals())
					{
						wins = Equels::equel;
					}
					if (game.getFirstGoals() > game.getSecondGoals())
					{
						wins = Equels::firstMore;
					}
					if (game.getFirstGoals() < game.getSecondGoals())
					{
						wins = Equels::secondMore;
					}

					if (isFirstTeam || isSecondTeam)
					{
						if (isFirstTeam)
						{
							foundFirst = true;
							if (wins == Equels::firstMore)
							{
								rating.setScore(rating.getScore() + 3);
							}
							else if (wins == Equels::secondMore)
							{
								rating.setScore(rating.getScore() + 0);
							}
							else
							{
								rating.setScore(rating.getScore() + 1);
							}
						}
						if (isSecondTeam)
						{
							foundSecond = true;
							if (wins == Equels::secondMore)
							{
								rating.setScore(rating.getScore() + 3);
							}
							else if (wins == Equels::firstMore)
							{
								rating.setScore(rating.getScore() + 0);
							}
							else
							{
								rating.setScore(rating.getScore() + 1);
							}
						}
						rating.setCountOfGame(rating.getCountOfGame() + 1);
						ratings.edit(findRatingByName, rating.getName(), rating);
					}
				}
				if (foundFirst == false)
				{
					int score;
					if (game.getFirstGoals() > game.getSecondGoals())
					{
						score = 3;
					}
					else if (game.getFirstGoals() < game.getSecondGoals())
					{
						score = 0;
					}
					else
					{
						score = 1;
					}
					Rating rating(game.getTeamName(), 1, score);
					ratings.create(rating);
				}
				if (foundSecond == false)
				{
					int score;
					if (game.getFirstGoals() < game.getSecondGoals())
					{
						score = 3;
					}
					else if (game.getFirstGoals() > game.getSecondGoals())
					{
						score = 0;
					}
					else
					{
						score = 1;
					}
					Rating rating(game.getSecondTeam().getTeamName(), 1, score);
					ratings.create(rating);
				}
			}
			cout << "\n \t -----------------------------";
			cout << "\n \t | Team name | Games | Score |";
			cout << "\n \t -----------------------------";
			for (int i = 0; i < ratings.getSize(); i++)
			{
				Rating rating = ratings[i];
				cout << "\n \t | "; cout.width(4); cout << rating.getName(); cout.width(4);
				cout << " | "; cout.width(4); cout << rating.getCountOfGame(); cout.width(4);
				cout << " | "; cout.width(4); cout << rating.getScore(); cout.width(4);
				cout << " |";
				cout << "\n \t -----------------------------";
			}
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