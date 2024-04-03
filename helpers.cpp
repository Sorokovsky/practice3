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
	Team team = enterTeam();
	Time time = enterTime();
	Date date = enterDate();
	string code, name;
	cout << "\n \t Game code: "; cin >> code;
	cout << "\n \t Game name: "; cin >> name;
	return Game(stadium, team, code, name, date, time);
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
	cout << "\n \t 15-Show sorted players by DESC birthday";
	cout << "\n \t >> ";
	cin >> operation;
	return operation;
}

bool orderPlayersByDate(Player i1, Player i2)
{
	return Date::compare(i1.getBirthday(), i2.getBirthday()) == Equels::firstMore;
}
