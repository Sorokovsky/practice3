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
	cout << "\n \t Enter a code: "; cin >> code;
	cout << "\n \t Enter a name: "; cin >> name;
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
	cout << "\n \t Enter alary: "; cin >> salary;
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
	cout << "\n \t Enter Name: "; cin >> name;
	cout << "\n \t Enter Surname: "; cin >> surname;
	cout << "\n \t Enter Father name: "; cin >> fatherName;
	cout << "\n \t Enter Height: "; cin >> height;
	cout << "\n \t Enter Weight: "; cin >> weight;
	cout << "\n \t Enter  Role: "; cin >> role;
	cout << "\n \t Enter Number: "; cin >> number;
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
