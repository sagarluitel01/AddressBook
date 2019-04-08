#ifndef Address_h
#define Address_h

#include <string>

using namespace std;

class Address
{
private:
    string streetAddress;
    string city;
    string states;
    string zipCode;
    string counrty;
    
public:
    void setStreetAdderss(string street);
    string getStreetAddress();
    void setCity(string Icity);
    string getCity();
    void setStates(string Istate);
    string getStates();
    void setZipCode(string zip);
    string getZipCode();
    void setCountry(string Icounrty){counrty = Icounrty; }
    string getCountry(){ return counrty;}
};

#endif