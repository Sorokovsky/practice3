#pragma once
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class StadiumType
{
public:
	StadiumType(string codeOfStadiumType, string nameOfStadiumType);
	string getCodeOfStadiumType();
	string getNameOfStadiumType();
	void setCodeOfStadiumType(string code);
	void setNameOfStadiumType(string name);
private:
	string codeOfStadiumType;
	string nameOfStadiumType;
};