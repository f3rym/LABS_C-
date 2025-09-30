#include "../header.h"
#include "Property.h"

class Office : public Property
{
    int numHouse;
    int countPremises;
    int numFloor;
    char metro[MAX_STR];
    bool hasParking;

};