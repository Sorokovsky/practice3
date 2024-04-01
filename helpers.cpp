#include "helpers.h"
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
