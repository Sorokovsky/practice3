#pragma once
#include "Position.h"
#include<iostream>
using namespace std;
class Coach : public Position
{
public:
	Coach(string positionName, 
		  string requirements, 
		  int salary, 
		  string coachPhoneNumber, 
		  string coachAddress, 
		  int age
		);
	Coach(
		Position position,
		string coachPhoneNumber,
		string coachAddress,
		int age
	);
	string getCoachPhoneNumber();
	string getCoachAddress();
	int getAge();
	void setCoachPhoneNumber(string phoneNumber);
	void setCoachAddress(string address);
	void setAge(int age);
private:
	string coachPhoneNumber;
	string coachAddress;
	int age;
};