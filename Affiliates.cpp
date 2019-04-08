#include "Affiliates.h"



Affiliates::Affiliates(string frName, string lsName, string poNumber, string emAil)
{
    firstName = frName;
    lastName = lsName;
    phoneNumber = poNumber;
    eMail = emAil;
}
string Affiliates::getFirstName()
{
    return firstName;
}
void Affiliates::setFirstName(string fName)
{
    firstName = fName;
}
string Affiliates::getLastName()
{
    return lastName;
}
void Affiliates::setLastName(string lName)
{
    lastName = lName;
}
void Affiliates::setPhone(string mobile)
{
    phoneNumber = mobile;
}
string Affiliates::getPhone()
{
    return phoneNumber;
}
void Affiliates::setEMail(string email)
{
    eMail = email;
}
string Affiliates::getEMail()
{
    return eMail;
}