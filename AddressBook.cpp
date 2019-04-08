#include "AddressBook.h"
#include <sstream>
#include <string>
#include <vector>

/*
it reads all the data from the databasesmall.txt and stores them in tree
each information is first store in Entry & after all information is read 
from a record than the entery will be added as a node in the tree
*/
void AddressBook::readfromFile()
{
    ifstream dataIN;
    Entry newEntry;     //newEntery
    int id;
    string fName;
    string mName;
    string lName;
    string comName;
    string id1;
    string hPhone;
    string oPhone;
    string email1;
    string mNumber;
    string sAddress;
    string city1;
    string states1;
    string zCode;
    string counrty1;
    string affiliates;
    
    dataIN.open("AddressBook/databasesmall.txt");

    while (!dataIN.eof())       //while untill the file is empty
    {
        getline(dataIN, id1);   //read id
        //newEntry.getNameInfo().setID(id1);
        id = stoi(id1);        
        newEntry.getNameInfo().setID(id1);      //stor it win newEntry
        getline(dataIN, fName);
        newEntry.getNameInfo().setFirstName(fName);
        getline(dataIN, mName);
        newEntry.getNameInfo().setMiddleName(mName);
        getline(dataIN, lName);
        newEntry.getNameInfo().setLastName(lName);
        getline(dataIN, comName);
        newEntry.getNameInfo().setCompanyName(comName);
        getline(dataIN, hPhone);
        newEntry.getContactInfo().setHomePhone(hPhone);
        getline(dataIN, oPhone);
        newEntry.getContactInfo().setOffiePhone(oPhone);
        getline(dataIN, email1);
        newEntry.getContactInfo().setEMail(email1);
        getline(dataIN, mNumber);
        newEntry.getContactInfo().setMobile(mNumber);
        getline(dataIN, sAddress);
        newEntry.getAddress().setStreetAdderss(sAddress);
        getline(dataIN, city1);
        newEntry.getAddress().setCity(city1);
        getline(dataIN, states1);
        newEntry.getAddress().setStates(states1);
        getline(dataIN, zCode);
        newEntry.getAddress().setZipCode(zCode);
        getline(dataIN, counrty1);
        newEntry.getAddress().setCountry(counrty1);
        getline(dataIN, affiliates);
        while (affiliates != "|")
        {
            getline(dataIN, affiliates);
            string name1;
            string firstName;
            string lastName;
            string phoneNumber;
            string eMail;
            stringstream affList(affiliates);
            getline(affList, name1, ',');
            stringstream coma(name1);
            getline(coma, firstName, ' ');
            getline(coma, lastName, ' ');
            getline(affList, phoneNumber, ',');
            getline(affList, eMail, ';');
            
            Affiliates newAffiliates = Affiliates(firstName, lastName, phoneNumber, eMail);
            newEntry.getAffiliates().push_back(newAffiliates);
            
        }
        tree->addNode(id, newEntry); //add newEntry in tree
        
      /*  for (int i = 0; i < newEntry.getAffiliates().size(); i++)
        {
            newEntry.getAffiliates().clear();
        } */
    }

}
void AddressBook::searchId(int searchItem,  Node* node)
{
    Node* temp;
    temp = tree->findNode(searchItem, node);
   
    if (temp->ID() == searchItem)
    {
       // found = true;
        
        cout << temp->getData().getNameInfo().getID() << endl;
        cout << temp->getData().getNameInfo().getFirstName() << endl;
        cout << temp->getData().getNameInfo().getMiddleName() << endl;
        cout << temp->getData().getNameInfo().getLastName() << endl;
        cout << temp->getData().getNameInfo().getCompanyName() << endl;
        cout << temp->getData().getContactInfo().getOfficePhone() << endl;
        cout << temp->getData().getContactInfo().getHomePhone() << endl;
        cout << temp->getData().getContactInfo().getMobile() << endl;
        cout << temp->getData().getContactInfo().getEMail() << endl;
        cout << temp->getData().getAddress().getStreetAddress() << endl;
        cout << temp->getData().getAddress().getCity() << endl;
        cout << temp->getData().getAddress().getStates() << endl;
        cout << temp->getData().getAddress().getZipCode() << endl;
        cout << temp->getData().getAddress().getCountry() << endl;
        //cout << &newEntry.getAffiliates();
        
        for (int i = 0; i < temp->getData().getAffiliates().size(); i++)
        {
            cout << temp->getData().getAffiliates()[i].getFirstName() << " "
                 << temp->getData().getAffiliates()[i].getLastName() << ", "
                 << temp->getData().getAffiliates()[i].getEMail() << ", "
                 << temp->getData().getAffiliates()[i].getPhone() << ";" << endl;
        }
    }
    else
    {
       // found = false;
        cout << " not found " << endl;
    }
}
void AddressBook::add()
{
    Entry newEntry;
    int iD;
    
    string fName;
    string mName;
    string lName;
    string comName;
    string id1;
    string hPhone;
    string oPhone;
    string mNumber;
    string email1;
    string sAddress;
    string city1;
    string states1;
    string zCode;
    string counrty1;
    string afFName;
    string afLName;
    string afNumber;
    string afEmail;
    
    cout << " Please enter ID " << endl;
    cin >> id1;
    newEntry.getNameInfo().setID(id1);
    cout << " Please Enter First Name: ";
    cin >> fName;
    newEntry.getNameInfo().setFirstName(fName);
    cout << " Please Enter Middle Name: ";
    cin >> mName;
    newEntry.getNameInfo().setMiddleName(mName);
    cout << " Please Enter Last Name: ";
    cin >> lName;
    newEntry.getNameInfo().setLastName(lName);
    cout << " Please Enter Company Name: ";
    cin.ignore();
    getline(cin, comName);
    newEntry.getNameInfo().setCompanyName(comName);
    cout << " Please Enter Home Phone: ";
    cin >> hPhone;
    newEntry.getContactInfo().setHomePhone(hPhone);
    cout << " Please Enter Office Number: ";
    cin >> oPhone;
    newEntry.getContactInfo().setOffiePhone(oPhone);
    cout << " Please Enter Mobile Number: ";
    cin >> mNumber;
    newEntry.getContactInfo().setMobile(mNumber);
    cout << " Please Enter Email: ";
    cin >> email1;
    newEntry.getContactInfo().setEMail(email1);
    cout << " Please Enter Street Address: ";
    cin.ignore();
    getline(cin, sAddress);
    newEntry.getAddress().setStreetAdderss(sAddress);
    cout << " Please Enter City: ";
    cin >> city1;
    newEntry.getAddress().setCity(city1);
    cout << " Please Enter State: ";
    cin >> states1;
    newEntry.getAddress().setStates(states1);
    cout << " Please Enter zip code: ";
    cin >> zCode;
    newEntry.getAddress().setZipCode(zCode);
    cout << " Please Enter Country: ";
    cin >> counrty1;
    newEntry.getAddress().setCountry(counrty1);
    
    int numOfAff;
    cout << "how many Affiliates: ";
    cin >> numOfAff;
    
    for (int i = 0; i < numOfAff; i++) {
        cout << " Affiliates First Name: ";
        cin >> afFName;
        cout << " Laset name: ";
        cin >> afLName;
        cout << " Phone Number: ";
        cin >> afNumber;
        cout << " Email: ";
        cin >> afEmail;
        Affiliates newAffiliates = Affiliates(afFName, afLName, afNumber, afEmail);
        newEntry.getAffiliates().push_back(newAffiliates);
    }
    
    
    tree->addNode(iD, newEntry);
}
void AddressBook::update(int searchItem, Node* node)
{
    Entry xEntry;
    string fName;
    string mName;
    string lName;
    string comName;
    string id1;
    string hPhone;
    string oPhone;
    string mNumber;
    string email1;
    string sAddress;
    string city1;
    string states1;
    string zCode;
    string counrty1;
    string affiliatesName;
    
    Node* temp;
    cout << " enter id ";
    cin >> searchItem;
    temp = tree->findNode(searchItem, node);
    
    xEntry = temp->getData();
    if (temp->ID() == searchItem)
    {
        int selection;
        cout << endl;
        cout << "******************************************" << endl;
        cout << " Please select what you want to update " << endl;
        cout << " 1:    ID \n"
                " 2:    First Name \n"
                " 3:    Middle Name \n"
                " 4:    Last name \n"
                " 5:    Company Name \n"
                " 6:    Home Phone \n"
                " 7:    Offic phone \n"
                " 8:    Mobile Phone \n"
                " 9:    Email \n"
                " 10:   Street Address \n"
                " 11:   City \n"
                " 12:   State \n"
                " 13:   Zip Code \n"
                " 14:   Country \n"
                " 15:   Affiliates \n" << endl;
        cin >> selection;
    
        switch (selection)
        {
            case 1:
                cout << " Please enter the ID: ";
                cin >> id1;
                //temp->getData().getNameInfo().setID(id1);
                xEntry.getNameInfo().setID(id1);
                
                break;
            case 2:
                cout << " Please enter the first name: ";
                cin >> fName;
                //temp->getData().getNameInfo().setFirstName(fName);
                xEntry.getNameInfo().setFirstName(fName);
                break;
            case 3:
                cout << " Please enter the Middle name: ";
                cin >> mName;
                xEntry.getNameInfo().setMiddleName(mName);
                break;
            case 4:
                cout << " Please enter the last name: ";
                cin >> lName;
                xEntry.getNameInfo().setLastName(lName);
                break;
            case 5:
                cout << " Please enter the Company name: ";
                cin >> comName;
                xEntry.getNameInfo().setCompanyName(comName);
                break;
            case 6:
                cout << " Please enter the Home phone: ";
                cin >> hPhone;
                xEntry.getContactInfo().setHomePhone(hPhone);
                break;
            case 7:
                cout << " Please enter the Office Phone: ";
                cin >> oPhone;
                xEntry.getContactInfo().setOffiePhone(oPhone);
                break;
            case 8:
                cout << " Please enter the mobile number: ";
                cin >> mNumber;
                xEntry.getContactInfo().setMobile(mNumber);
                break;
            case 9:
                cout << " Please enter the Email address: ";
                cin >> email1;
                xEntry.getContactInfo().setEMail(email1);
                break;
            case 10:
                cout << " Please enter the Street address: ";
                cin >> sAddress;
                xEntry.getAddress().setStreetAdderss(sAddress);
                break;
            case 11:
                cout << " Please enter the City name: ";
                cin >> city1;
                xEntry.getAddress().setCity(city1);
                break;
            case 12:
                cout << " Please enter the State name: ";
                cin >> states1;
                xEntry.getAddress().setStates(states1);
                break;
            case 13:
                cout << " Please enter the zipcode: ";
                cin >> zCode;
                xEntry.getAddress().setZipCode(zCode);
                break;
            case 14:
                cout << " Please enter the country name: ";
                cin >> counrty1;
                xEntry.getAddress().setCountry(counrty1);
                break;
            case 15:
                Affiliates xAffiliates;
                string afFName;
                string afLName;
                string afNumber;
                string afEmail;
                
                cout << " Please enter the name of the Affiliates that you want to search: ";
                cin >> affiliatesName;
                for (int i = 0; i < xEntry.getAffiliates().size(); i++)
                {
                    if(affiliatesName == xAffiliates.getFirstName())
                    {
                        cout << " Enter the first name: ";
                        cin >> afFName;
                        cout << " Enter the last name: ";
                        cin >> afLName;
                        cout << " Enter the phone number: ";
                        cin >> afNumber;
                        cout << " Enter the Email Address: ";
                        cin >> afEmail;
                        
                        Affiliates newAffiliates = Affiliates(afFName, afLName, afNumber, afEmail);
                        xEntry.getAffiliates().push_back(newAffiliates);
                    }
                }
                break;
        }
       
       tree->addNode(searchItem, xEntry);
        tree->deleteNode(temp->ID());
    }
    else
    {
        cout << " not found " << endl;
    }

    
    
}
void AddressBook::remove(Node* node)
{
    int searchItem;
    string word;
    vector<Node*> searchResult;
    cout << endl;
    cout << "******************************************" << endl;
    cout << " Please select what you want to Delete By " << endl;
    cout << " 0:    ID \n"
    " 1:    First Name \n"
    " 2:    Middle Name \n"
    " 3:    Last name \n"
    " 4:    Company Name \n"
    " 5:    Home Phone \n"
    " 6:    Offic phone \n"
    " 7:    Mobile Phone \n"
    " 8:    Email \n"
    " 9:    Street Address \n"
    " 10:   City \n"
    " 11:   State \n"
    " 12:   Zip Code \n"
    " 13:   Country \n"
    " 14:   Affiliates \n" << endl;
    
    cin >> searchItem;
    
    if (searchItem == 0)
    {
        int wordID;
        cout << " Enter the ID ";
        cin >> wordID;
        searchId(wordID, node);
        
        tree->deleteNode(wordID);
    }
    if (searchItem == 1)
    {
        cout << " Enter the name: ";
        cin.clear();
        cin.ignore();
        cin >> word;
    }
    if (searchItem == 2)
    {
        cout << " Enter the Middle ";
        cin.clear();
        cin.ignore();
        cin >> word;
    }
    if (searchItem == 3)
    {
        cout << " Enter the Last Name  ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 4)
    {
        cout << " Enter the Company ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 5)
    {
        cout << " Enter the  Home Phone# ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 6)
    {
        cout << " Enter the Office Phone# ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 7)
    {
        cout << " Enter the  Mobile Number ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
        
    }
    if (searchItem == 8)
    {
        cout << " Enter the  Email ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 9)
    {
        cout << " Enter the  street Address ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 10)
    {
        cout << " Enter the City ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 11)
    {
        cout << " Enter the States ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 12)
    {
        cout << " Enter the Zip-Code ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 13)
    {
        cout << " Enter the Country ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    if (searchItem == 14)
    {
        cout << " Enter the  Affiliates ";
        cin.clear();
        cin.ignore();
        getline(cin, word);
    }
    tree->search(node, word, searchItem, searchResult);
    
    for (int i = 0; i < searchResult.size(); i++)
    {
        Node* temp;
        temp = searchResult[i];
        
        tree->deleteNode(temp->ID());
        cout << word << " Has Been deleted " << endl;
    }
    

}

void AddressBook::display(Node* node)
{
    int searchItem;
    vector<Node*> serchResult;
    cout << endl;
    cout << "******************************************" << endl;
    cout << " Please select what you want to Display By " << endl;
    cout << " 0:    ID \n"
    " 1:    First Name \n"
    " 2:    Last Neme \n"
    " 3:    Company Neme \n"
    " 4:    Email \n"
    " 5:    Mobile Number \n"
    " 6:    Print All \n" << endl;
    
    cin >> searchItem;
    
    if (searchItem == 0)
    {
        tree->printPreorder(node);
    }
    if (searchItem == 1)
    {
        tree->printPreordername(node, searchItem);
    }
    if (searchItem == 2)
    {
       tree->printPreordername(node, searchItem);
    }
    if (searchItem == 3)
    {
       tree->printPreordername(node, searchItem);
    }
    if (searchItem == 4)
    {
       tree->printPreordername(node, searchItem);
    }
    if (searchItem == 5)
    {
        tree->printPreordername(node, searchItem);
    }
    if (searchItem == 6)
    {
        tree->printPreordername(node, searchItem);
    }
   
//    tree->search(node, word, searchItem, serchResult);
//    for (int i = 0; i < serchResult.size(); i++)
//    {
//        cout << serchResult[i]->getData().getNameInfo().getID() << endl;
//        cout << serchResult[i]->getData().getNameInfo().getFirstName() << endl;
//        cout << serchResult[i]->getData().getNameInfo().getMiddleName() << endl;
//        cout << serchResult[i]->getData().getNameInfo().getLastName() << endl;
//        cout << serchResult[i]->getData().getNameInfo().getCompanyName() << endl;
//        cout << serchResult[i]->getData().getContactInfo().getHomePhone() << endl;
//        cout << serchResult[i]->getData().getContactInfo().getOfficePhone() << endl;
//        cout << serchResult[i]->getData().getContactInfo().getEMail() << endl;
//        cout << serchResult[i]->getData().getContactInfo().getMobile() << endl;
//        cout << serchResult[i]->getData().getAddress().getStreetAddress() << endl;
//        cout << serchResult[i]->getData().getAddress().getCity() << endl;
//        cout << serchResult[i]->getData().getAddress().getStates() << endl;
//        cout << serchResult[i]->getData().getAddress().getZipCode() << endl;
//        cout << serchResult[i]->getData().getAddress().getCountry() << endl;
//
//        for (int i = 0; i < serchResult[i]->getData().getAffiliates().size(); i++)
//        {
//            cout << serchResult[i]->getData().getAffiliates()[i].getFirstName() << " "
//                 << serchResult[i]->getData().getAffiliates()[i].getLastName() << ", "
//                 << serchResult[i]->getData().getAffiliates()[i].getPhone() << ", "
//                 << serchResult[i]->getData().getAffiliates()[i].getEMail() << ";" << endl;
//        }
//    }
    
}

void AddressBook::search(Node* node, int searchItem, vector<Node*>& searchResult)
{
    string str1;
    cout << endl;
    cout << "******************************************" << endl;
    cout << " Please select what you want to sarch By " << endl;
    cout << " 0:    ID \n"
    " 1:    First Name \n"
    " 2:    Middle Name \n"
    " 3:    Last name \n"
    " 4:    Company Name \n"
    " 5:    Home Phone \n"
    " 6:    Offic phone \n"
    " 7:    Mobile Phone \n"
    " 8:    Email \n"
    " 9:    Street Address \n"
    " 10:   City \n"
    " 11:   State \n"
    " 12:   Zip Code \n"
    " 13:   Country \n"
    " 14:   Affiliates \n" << endl;
    
    cin >> searchItem;
    if (searchItem == 0)
    {
        int wordID;
        cout << " Enter the ID ";
        cin >> wordID;
        searchId(wordID, node);
    }
    if (searchItem == 1)
    {
        cout << " Enter the name: ";
        cin.clear();
        cin.ignore();
        cin >> str1;
    }
    if (searchItem == 2)
    {
        cout << " Enter the Middle ";
        cin.clear();
        cin.ignore();
        cin >> str1;
    }
    if (searchItem == 3)
    {
        cout << " Enter the Last Name  ";
        cin.clear();
        cin.ignore();
        getline(cin, str1);
       
    }
    if (searchItem == 4)
    {
        cout << " Enter the Company ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 5)
    {
        cout << " Enter the  Home Phone# ";
        cin.clear();
        cin.ignore();
       getline (cin, str1);
    }
    if (searchItem == 6)
    {
        cout << " Enter the Office Phone# ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 7)
    {
        cout << " Enter the  Mobile Number ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 8)
    {
        cout << " Enter the  Email ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 9)
    {
        cout << " Enter the  street Address ";
        cin.clear();
        cin.ignore();
       getline (cin, str1);
    }
    if (searchItem == 10)
    {
        cout << " Enter the City ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 11)
    {
        cout << " Enter the States ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 12)
    {
        cout << " Enter the Zip-Code ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 13)
    {
        cout << " Enter the Country ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    if (searchItem == 14)
    {
        cout << " Enter the  Affiliates ";
        cin.clear();
        cin.ignore();
        getline (cin, str1);
    }
    tree->search(node, str1, searchItem, searchResult);
    
    for (int i = 0; i < searchResult.size(); i++)
    {
        cout << searchResult[i]->getData().getNameInfo().getID() << endl;
        cout << searchResult[i]->getData().getNameInfo().getFirstName() << endl;
        cout << searchResult[i]->getData().getNameInfo().getLastName() << endl;
        cout << searchResult[i]->getData().getNameInfo().getCompanyName() << endl;
        cout << searchResult[i]->getData().getContactInfo().getHomePhone() << endl;
        cout << searchResult[i]->getData().getContactInfo().getOfficePhone() << endl;
        cout << searchResult[i]->getData().getContactInfo().getEMail() << endl;
        cout << searchResult[i]->getData().getContactInfo().getMobile() << endl;
        cout << searchResult[i]->getData().getAddress().getStreetAddress() << endl;
        cout << searchResult[i]->getData().getAddress().getCity() << endl;
        cout << searchResult[i]->getData().getAddress().getStates() << endl;
        cout << searchResult[i]->getData().getAddress().getZipCode() << endl;
        cout << searchResult[i]->getData().getAddress().getCountry() << endl;
        
                for (int j = 0; j < searchResult[i]->getData().getAffiliates().size(); j++)
                {
                    cout << searchResult[i]->getData().getAffiliates()[j].getFirstName() << " "
                         << searchResult[i]->getData().getAffiliates()[j].getLastName() << ", "
                         << searchResult[i]->getData().getAffiliates()[j].getPhone() << ", "
                         << searchResult[i]->getData().getAffiliates()[j].getEMail() << ";" << endl;
                }
        
    }
}

/*void AddressBook::inorder(BSTree tree1)
{
    if(tree1.Root() == nullptr)
    {
        cout << " The Tree is empty" << endl;
        return;
    }
    
    if (tree1.Root()->Right() != nullptr)
    {
        
    }
 
}*/


