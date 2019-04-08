
#include "ContactInfo.h"

ContactInfo::ContactInfo()
{
    
}
void ContactInfo::setHomePhone(string home)
{
    homePhone = home;
}
string ContactInfo::getHomePhone()
{
    return homePhone;
}
void ContactInfo::setOffiePhone(string office)
{
    officePhone = office;
}
string ContactInfo::getOfficePhone()
{
    return officePhone;
}
void ContactInfo::setMobile(string mobile)
{
    mobileNumber = mobile;
}
string ContactInfo::getMobile()
{
    return mobileNumber;
}
void ContactInfo::setEMail(string emial)
{
    eMail = emial;
}
string ContactInfo::getEMail()
{
    return eMail;
}