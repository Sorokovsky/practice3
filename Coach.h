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
		  string phoneNumber, 
		  string address, 
		  int age
		);
	string getPhoneNumber();
	string getAddress();
	int getAge();
	void setPhoneNumber(string phoneNumber);
	void setAddress(string address);
	void setAge(int age);
private:
	string phoneNumber;
	string address;
	int age;
};