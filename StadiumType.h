#pragma once
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class StadiumType
{
public:
	StadiumType(string codeOfStadiumType, string nameOfStadiumType);
	StadiumType();
	string getCodeOfStadiumType();
	string getNameOfStadiumType();
	void setCodeOfStadiumType(string code);
	void setNameOfStadiumType(string name);
	virtual void print();
private:
	string codeOfStadiumType;
	string nameOfStadiumType;
};