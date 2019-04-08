
#include "Address.h"

void Address::setStreetAdderss(string street)
{
    streetAddress = street;
}
string Address::getStreetAddress()
{
    return streetAddress;
}
void Address::setCity(string Icity)
{
    city = Icity;
}
string Address::getCity()
{
    return city;
}
void Address::setStates(string Istate)
{
    states = Istate;
}
string Address::getStates()
{
    return states;
}
void Address::setZipCode(string zip)
{
    zipCode = zip;
}
string Address::getZipCode()
{
    return zipCode;
}