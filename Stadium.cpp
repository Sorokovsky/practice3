#include "Stadium.h"

Stadium::Stadium(
    string codeOfStadiumType, 
    string nameOfStadiumType, 
    string stadiumCode, 
    string stadiumName, 
    string stadiumAddress, 
    string stadiumPhoneNumber, 
    string masterHead, 
    string notes
) : StadiumType(codeOfStadiumType, nameOfStadiumType)
{
    this->setStadiumName(stadiumName);
    this->setStadiumCode(stadiumCode);
    this->setStadiumAddress(stadiumAddress);
    this->setStadiumPhoneNumber(stadiumPhoneNumber);
    this->setMasterHead(masterHead);
    this->setNotes(notes);
}

Stadium::Stadium(
    StadiumType stadiumType,
    string stadiumCode,
    string stadiumName,
    string stadiumAddress,
    string stadiumPhoneNumber,
    string masterHead,
    string notes
) : StadiumType(stadiumType.getCodeOfStadiumType(), stadiumType.getNameOfStadiumType())
{
    this->setStadiumCode(stadiumCode);
    this->setStadiumName(stadiumName);
    this->setStadiumAddress(stadiumAddress);
    this->setStadiumPhoneNumber(stadiumPhoneNumber);
    this->setMasterHead(masterHead);
    this->setNotes(notes);
}

Stadium::Stadium() : StadiumType()
{
}

string Stadium::getStadiumCode()
{
    return this->stadiumCode;
}

string Stadium::getStadiumName()
{
    return this->stadiumName;
}

string Stadium::getStadiumAddress()
{
    return this->stadiumAddress;
}

string Stadium::getStadiumPhoneNumber()
{
    return this->stadiumPhoneNumber;
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

void Stadium::setStadiumAddress(string address)
{
    this->stadiumAddress = address;
}

void Stadium::setStadiumPhoneNumber(string phoneNumber)
{
    this->stadiumPhoneNumber = phoneNumber;
}

void Stadium::setMasterHead(string masterHead)
{
    this->masterHead = masterHead;
}

void Stadium::setNotes(string notets)
{
    this->notes = notets;
}

void Stadium::print()
{
    cout << "\n \t Stadium { ";
    cout << "Stadium type code: " << this->getCodeOfStadiumType();
    cout << ", Stadium type name: "; cout << this->getNameOfStadiumType();
    cout << ", Stadium code: " << this->getStadiumCode();
    cout << ", Stadium name: " << this->getStadiumName();
    cout << ", Stadium address: " << this->getStadiumAddress();
    cout << ", Stadium phoneNumber: " << this->getStadiumPhoneNumber();
    cout << ", Stadium masterhead: " << this->getMasterHead();
    cout << " }";
}
