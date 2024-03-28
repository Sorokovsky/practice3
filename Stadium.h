#pragma once
#include "StadiumType.h"
#include<iostream>
using namespace std;
class Stadium : public StadiumType
{
public:
	Stadium(
		string codeOfStadiumType,
		string nameOfStadiumType,
		string stadiumCode,
		string stadiumName,
		string address,
		string phoneNumber,
		string masterHead,
		string notes
		);
	string getStadiumCode();
	string getStadiumName();
	string getAddress();
	string getPhoneNumber();
	string getMasterHead();
	string getNotes();
	void setStadiumCode(string stadiumCode);
	void setStadiumName(string stadiumName);
	void setAddress(string address);
	void setPhoneNumber(string phoneNumber);
	void setMasterHead(string masterHead);
	void setNotes(string notets);
private:
	string stadiumCode;
	string stadiumName;
	string address;
	string phoneNumber;
	string masterHead;
	string notes;
};