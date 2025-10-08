#include "../header.h"
#include "Property.h"

class Apartment : public Property 
{
    int countRoom;
    int numHouse;
    int numApartment;
    int numFloor;
    char metro[MAX_STR];
    bool repair;

public:
    Apartment();
   ///// Apartment()
   Apartment(const Apartment& other);
   ~Apartment(){};
};