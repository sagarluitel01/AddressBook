#ifndef NameInfo_h
#define NameInfo_h

#include <string>
#include <iostream>

using namespace std;

class NameInfo
{
private:
    string firstName;
    string middleName;
    string lastName;
    string companyName;
    string iD;

public:
    void setFirstName(string);
    string getFirstName();
    void setMiddleName(string);
    string getMiddleName();
    void setLastName(string);
    string getLastName();
    void setCompanyName(string);
    string getCompanyName();
    void setID(string idNumber);
    string getID();
};

#endif