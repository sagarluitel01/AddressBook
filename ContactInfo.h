#ifndef ContactInfo_
#define ContactInfo_

#include <string>
using namespace std;

class ContactInfo
{
private:
    string homePhone;
    string officePhone;
    string mobileNumber;
    string eMail;
    
public:
    ContactInfo();
    void setHomePhone(string home);
    string getHomePhone();
    void setOffiePhone(string office);
    string getOfficePhone();
    void setMobile(string mobile);
    string getMobile();
    void setEMail(string emial);
    string getEMail();

};

#endif