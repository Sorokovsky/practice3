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
		string stadiumAddress,
		string stadiumPhoneNumber,
		string masterHead,
		string notes
		);
	Stadium(
		StadiumType stadiumType,
		string stadiumCode,
		string stadiumName,
		string stadiumAddress,
		string stadiumAhoneNumber,
		string masterHead,
		string notes
	);
	Stadium();
	string getStadiumCode();
	string getStadiumName();
	string getStadiumAddress();
	string getStadiumPhoneNumber();
	string getMasterHead();
	string getNotes();
	void setStadiumCode(string stadiumCode);
	void setStadiumName(string stadiumName);
	void setStadiumAddress(string address);
	void setStadiumPhoneNumber(string phoneNumber);
	void setMasterHead(string masterHead);
	void setNotes(string notets);
	void print() override;
protected:
	void printHead() override;
	void printBody() override;
	void printEnd() override;
private:
	string stadiumCode;
	string stadiumName;
	string stadiumAddress;
	string stadiumPhoneNumber;
	string masterHead;
	string notes;
};