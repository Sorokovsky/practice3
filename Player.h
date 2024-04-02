#pragma once
#include "Team.h"
#include "Date.h"
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
		Date birthday,
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
		Date birthday,
		int height,
		int weight,
		string role,
		int number
	);
	Player();
	string getPlayerCode();
	string getSurname();
	string getName();
	string getFatherName();
	Date getBirthday();
	int getHeight();
	int getWeight();
	string getRole();
	int getNumber();
	void setPlayerCode(string playerCode);
	void setSurname(string surname);
	void setName(string name);
	void setFatherName(string fatherName);
	void setBirthday(Date birthday);
	void setHeight(int height);
	void setWeight(int weight);
	void setRole(string role);
	void setNumber(int number);
	void print() override;
protected:
	void printHead() override;
	void printBody() override;
	void printEnd() override;
private:
	string playerCode;
	string surname;
	string name;
	string fatherName;
	Date birthday;
	int height;
	int weight;
	string role;
	int number;
};