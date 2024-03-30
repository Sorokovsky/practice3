#include<iostream>
#include "StadiumType.h"
#include "Manager.h"
#include "constants.h"
using namespace std;
StadiumType enterType()
{
	string code, name;
	cout << "\n \t Enter a code: "; cin >> code;
	cout << "\n \t Enter a name: "; cin >> name;
	return StadiumType(code, name);
}
int main()
{
	Manager manager(stadiumTypesFile, stadiumsFile, teamsFile, coachesFile, gamesFile, playersFile, positionsFile);
	manager.loadStadiumTypes();
	manager.add(enterType());
	manager.showStadiumTypes();
	return 0;
}