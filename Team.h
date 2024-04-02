#pragma once
#include "Coach.h"
#include<iostream>
using namespace std;
class Team : public Coach
{
public:
	Team(string positionName,
		string requirements,
		int salary,
		string phoneNumber,
		string address,
		int age,
		string teamCode,
		string teamName
	);
	Team(
		Coach coach,
		string teamCode,
		string teamName
	);
	Team();
	string getTeamCode();
	string getTeamName();
	void setTeamCode(string teamCode);
	void setTeamName(string teamName);
	void print() override;
protected:
	void printHead() override;
	void printBody() override;
	void printEnd() override;
private:
	string teamCode;
	string teamName;
};