#include "Stadium.h"

Stadium::Stadium(
    string codeOfStadiumType, 
    string nameOfStadiumType, 
    string stadiumCode, 
    string stadiumName, 
    string address, 
    string phoneNumber, 
    string masterHead, 
    string notes
) : StadiumType(codeOfStadiumType, nameOfStadiumType)
{
    this->setStadiumName(stadiumName);
    this->setStadiumCode(stadiumCode);
    this->setAddress(address);
    this->setPhoneNumber(phoneNumber);
    this->setMasterHead(masterHead);
    this->setNotes(notes);
}

string Stadium::getStadiumCode()
{
    return this->stadiumCode;
}

string Stadium::getStadiumName()
{
    return this->stadiumName;
}

string Stadium::getAddress()
{
    return this->address;
}

string Stadium::getPhoneNumber()
{
    return this->phoneNumber;
}

string Stadium::getMasterHead()
{
    return this->masterHead;
}

string Stadium::getNotes()
{
    return this->notes;
}

void Stadium::setStadiumCode(string stadiumCode)
{
    this->stadiumCode = stadiumCode;
}

void Stadium::setStadiumName(string stadiumName)
{
    this->stadiumName = stadiumName;
}

void Stadium::setAddress(string address)
{
    this->address = address;
}

void Stadium::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Stadium::setMasterHead(string masterHead)
{
    this->masterHead = masterHead;
}

void Stadium::setNotes(string notets)
{
    this->notes = notets;
}
