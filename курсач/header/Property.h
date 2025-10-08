#include "../header.h"

class Property
{
    int propertyId;
    double totalArea;
    int price;
    char city[MAX_STR];
    char region[MAX_STR];
    char street[MAX_STR];
   ///////// char house[MAX_STR];

public:
    Property();
   // Property(//////////////);
    Property(const Property& other);
    ~Property(){};
};
