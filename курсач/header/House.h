#include "../header.h"
#include "Land.h"

class House : public Land
{
    int numHouse;
    int countRoom;
    int floor;
    char waterSupply[MAX_STR];
    char typeHeating[MAX_STR];
    char wallMaterial[MAX_STR];
};