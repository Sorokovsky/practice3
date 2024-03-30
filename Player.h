#pragma once
#include "Team.h"
#include<iostream>
using namespace std;
class Player : public Team
{
public:
	Player(string positionName,
		string requirements,
		int salary,
		string phoneNumber,
		string address,
		int age,
		string teamCode,
		string teamName,
		string playerCode,
		string surname,
		string name,
		string fatherName,
		time_t birthday,
		int height,
		int weight,
		string role,
		int number
	);
	Player(
		Team team,
		string playerCode,
		string surname,
		string name,
		string fatherName,
		time_t birthday,
		int height,
		int weight,
		string role,
		int number
	);
	string getPlayerCode();
	string getSurname();
	string getName();
	string getFatherName();
	time_t getBirthday();
	int getHeight();
	int getWeight();
	string getRole();
	int getNumber();
	void setPlayerCode(string playerCode);
	void setSurname(string surname);
	void setName(string name);
	void setFatherName(string fatherName);
	void setBirthday(time_t birthday);
	void setHeight(int height);
	void setWeight(int weight);
	void setRole(string role);
	void setNumber(int number);
private:
	string playerCode;
	string surname;
	string name;
	string fatherName;
	time_t birthday;
	int height;
	int weight;
	string role;
	int number;
};