#pragma once
#include "helpers.h"
Date enterDate()
{
	int year, month, day;
	cout << "\n \t Enter year: "; cin >> year;
	cout << "\n \t Enter number of month: "; cin >> month;
	cout << "\n \t Enter day: "; cin >> day;
	return Date(year, month, day);
}
Time enterTime()
{
	int hours, minutes, seconts;
	cout << "\n \t Enter a hours: "; cin >> hours;
	cout << "\n \t Enter a minutes: "; cin >> minutes;
	cout << "\n \t Enter a seconts: "; cin >> seconts;
	return Time(seconts, minutes, hours);
}
StadiumType enterType()
{
	string code, name;
	cout << "\n \t Enter a stadium type code: "; cin >> code;
	cout << "\n \t Enter a stadium type name: "; cin >> name;
	return StadiumType(code, name);
}

Stadium enterStadium()
{
	StadiumType type = enterType();
	string code, address, name, phoneNumber, masterHead, notes;
	cout << "\n \t Enter stadium code: "; cin >> code;
	cout << "\n \t Enter stadium name: "; cin >> name;
	cout << "\n \t Enter stadium address: "; cin >> address;
	cout << "\n \t Enter stadium phoneNumber: "; cin >> phoneNumber;
	cout << "\n \t Enter stadium masterhead: "; cin >> masterHead;
	cout << "\n \t Enter notes: "; cin >> notes;
	return Stadium(type, code, name, address, phoneNumber, masterHead, notes);
}

Position enterPosition()
{
	string name, requirements;
	int salary;
	cout << "\n \t Enter position Name: "; cin >> name;
	cout << "\n \t Enter requirements: "; cin >> requirements;
	cout << "\n \t Enter position salary: "; cin >> salary;
	return Position(name, requirements, salary);
}

Coach enterCoach()
{
	Position position = enterPosition();
	string phoneNumber, address;
	int age;
	cout << "\n \t Enter Coach phone number: "; cin >> phoneNumber;
	cout << "\n \t Enter Coach address: "; cin >> phoneNumber;
	cout << "\n \t Enter Coach age: "; cin >> age;
	return Coach(position, phoneNumber, address, age);
}

Team enterTeam()
{
	Coach coach = enterCoach();
	string code, name;
	cout << "\n \t Enter Team code: "; cin >> code;
	cout << "\n \t Enter Team name: "; cin >> name;
	return Team(coach, code, name);
}

Player enterPlayer()
{
	Team team = enterTeam();
	string playerCode, name, surname, fatherName, role;
	int height, weight, number;
	Date birthday = enterDate();
	cout << "\n \t Enter Player code: "; cin >> playerCode;
	cout << "\n \t Enter Player Name: "; cin >> name;
	cout << "\n \t Enter Player Surname: "; cin >> surname;
	cout << "\n \t Enter Player Father name: "; cin >> fatherName;
	cout << "\n \t Enter Player Height: "; cin >> height;
	cout << "\n \t Enter Player Weight: "; cin >> weight;
	cout << "\n \t Enter Player Role: "; cin >> role;
	cout << "\n \t Enter Player Number: "; cin >> number;
	return Player(team, playerCode, surname, name, fatherName, birthday, height, weight, role, number);
}

Game enterGame()
{
	Stadium stadium = enterStadium();
	cout << "\n \t 1 Team.";
	Team team = enterTeam();
	cout << "\n \t 2 Team.";
	Team secondTeam = enterTeam();
	Time time = enterTime();
	Date date = enterDate();
	string code, name;
	cout << "\n \t Game code: "; cin >> code;
	cout << "\n \t Game name: "; cin >> name;
	Game game = Game(stadium, team, code, name, date, time, secondTeam);
	if (Date::compare(Date::getNow(), game.getDateOfGame()) == Equels::firstMore)
	{
		game.play();
	}
	return game;
}

int chooseOperation()
{
	int operation;
	cout << "\n \t Choose operation: ";
	cout << "\n \t 0-Exit.";
	cout << "\n \t 1-Add stadium type.";
	cout << "\n \t 2-Show stadium types.";
	cout << "\n \t 3-Add stadium.";
	cout << "\n \t 4-Show stadiums.";
	cout << "\n \t 5-Add position.";
	cout << "\n \t 6-Show positions.";
	cout << "\n \t 7-Add coach.";
	cout << "\n \t 8-Show coaches.";
	cout << "\n \t 9-Add team.";
	cout << "\n \t 10-Show teams.";
	cout << "\n \t 11-Add player.";
	cout << "\n \t 12-Show players.";
	cout << "\n \t 13-Add game.";
	cout << "\n \t 14-Show games.";
	cout << "\n \t 15-Show sorted players by DESC birthday.";
	cout << "\n \t 16-Get games in July.";
	cout << "\n \t 17-Get players that younger 20 years.";
	cout << "\n \t 18-Get stadiums by type";
	cout << "\n \t 19-Games in August 2012";
	cout << "\n \t 20-Avarage age of players.";
	cout << "\n \t 21-Get date of first game.";
	cout << "\n \t 22-Change phone of stadium.";
	cout << "\n \t 23-Delete player by code.";
	cout << "\n \t 24-Copy players from 1986.";
	cout << "\n \t 25-Show players from 1986.";
	cout << "\n \t 26-Get games in 11 september 2011.";
	cout << "\n \t 27-Get stadium which had games.";
	cout << "\n \t 28-Get surname of younger player.";
	cout << "\n \t 29-Get Rating tample.";
	cout << "\n \t >> ";
	cin >> operation;
	return operation;
}

bool orderPlayersByDate(Player i1, Player i2)
{
	return Date::compare(i1.getBirthday(), i2.getBirthday()) == Equels::secondMore;
}

bool gamesInMonth(Game item, int comparer)
{
	return item.getDateOfGame().getMonth() == comparer;
}

bool findPlayerYounger(Player item, int year)
{
	Date currentYear = Date::getNow();
	return getAge(item.getBirthday()) < year;
}

bool byStadiumType(Stadium item, StadiumType type)
{
	return (item.getCodeOfStadiumType().compare(type.getCodeOfStadiumType()) == 0) && (item.getNameOfStadiumType().compare(type.getNameOfStadiumType()) == 0);
}

bool findGameByMonthAndYear(Game item, Date date)
{
	return (item.getDateOfGame().getYear() == date.getYear()) && (item.getDateOfGame().getMonth() == date.getMonth());
}

int getAge(Date birthday)
{
	return abs(birthday.getYear() - Date::getNow().getYear());
}

int accomulateAvarageAge(Player item, int result)
{
	return result += getAge(item.getBirthday());
}

bool sortGamesByDate(Game i1, Game i2)
{
	return Date::compare(i1.getDateOfGame(), i2.getDateOfGame()) == Equels::firstMore;
}

bool findStadiumByCodePredicate(Stadium item, string code)
{
	return item.getCodeOfStadiumType().compare(code) == 0;
}

bool findPlayerByCode(Player item, string code)
{
	return item.getPlayerCode().compare(code) == 0;
}

bool findPlayerByYear(Player item, int year)
{
	return item.getBirthday().getYear() == year;
}

bool findGameByDate(Game game, Date date)
{
	return Date::compare(game.getDateOfGame(), date) == Equels::equel;
}

bool findRatingByName(Rating item, string name)
{
	return item.getName().compare(name) == 0;
}

bool sortRatingPredicateByScore(Rating i1, Rating i2)
{
	return i1.getScore() < i2.getScore();
}

bool sortRatingPredicateByDifference(Rating i1, Rating i2)
{
	int diff1 = i1.getGoals() - i1.getWrongs();
	int diff2 = i2.getGoals() - i2.getWrongs();
	return diff1 < diff2;
}
