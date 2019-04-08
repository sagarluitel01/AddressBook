#ifndef Entry_H
#define Entry_H

#include <iostream>
#include <string>
#include <vector>
#include "BSTree.h"

using namespace std;

#include "NameInfo.h"
#include "ContactInfo.h"
#include "Address.h"
#include "Affiliates.h"

class Entry
{
private:
    NameInfo iName;
    ContactInfo iContact;
    Address iAddress;
    //Affiliates iAffiliates;
    vector<Affiliates> afVector;
    
public:
    NameInfo &getNameInfo(){return iName; }
    void setNameInfo(NameInfo nameInformation) {iName = nameInformation;}
    ContactInfo &getContactInfo() {return iContact; }
    void setContactInfo(ContactInfo contactInformation) { iContact = contactInformation;}
    Address &getAddress() { return iAddress; }
    void setAddress(Address addressInformation) {iAddress = addressInformation; }
    
    
    vector<Affiliates>& getAffiliates() {return afVector; }

    
};

#endif