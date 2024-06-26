#pragma once
#include<iostream>
using namespace std;
class Position
{
public:
	Position(string positionName, string requirements, int salary);
	Position();
	string getPositionName();
	string getRequirements();
	int getSalary();
	void setPositionName(string positionName);
	void setRequirements(string requirements);
	void setSalary(int salary);
	virtual void print();
protected:
	virtual void printHead();
	virtual void printBody();
	virtual void printEnd();
private:
	string positionName;
	string requirements;
	int salary;
};