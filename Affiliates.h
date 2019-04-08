#ifndef Affiliates_H
#define Affiliates_H

#include <string>
#include "NameInfo.h"
#include "ContactInfo.h"

class Affiliates
{
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string eMail;
public:
    Affiliates(){}
    Affiliates(string, string, string, string);
    string getFirstName();
    void setFirstName(string fName);
    string getLastName();
    void setLastName(string lName);
    void setPhone(string mobile);
    string getPhone();
    void setEMail(string emial);
    string getEMail();
    
    
};

#endif