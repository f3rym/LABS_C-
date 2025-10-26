#pragma once

#include "../header.h"
#include "listNode.h"
class Property
{
    static int nextPropertyId;
    double totalArea;
    int price;
    char city[MAX_STR];
    char region[MAX_STR];
    char street[MAX_STR];

    int ownerId;
    int propertyId;
    bool isActive;

public:
    Property()
    {
        ownerId = -1;
        propertyId = nextPropertyId++;
        isActive = true;
        totalArea = 0.0;
        price = 0;
        city[0] = '\0';
        region[0] = '\0';
        street[0] = '\0';
    }

    Property(double area, int pr, char *c, char *r, char *s, int ownerId)
    {
        totalArea = area;
        price = pr;
        this->ownerId = ownerId;
        isActive = true;
        propertyId = nextPropertyId++;
        strcpy_s(city, c);
        strcpy_s(region, r);
        strcpy_s(street, s);
    }

    Property(const Property &other)
    {
        this->ownerId = other.ownerId;
        isActive = other.isActive;
        propertyId = other.propertyId;
        totalArea = other.totalArea;
        price = other.price;
        strcpy_s(city, other.city);
        strcpy_s(region, other.region);
        strcpy_s(street, other.street);
    }
    virtual void info();
    virtual ~Property() = default;

    friend std::ostream &operator<<(std::ostream &os, Property &pr);
    friend std::istream &operator>>(std::istream &is, Property &pr);

    double getTotalArea();
    int getPrice();
    char *getCity();
    char *getRegion();
    char *getStreet();

    void setTotalArea(double area);
    void setPrice(int pr);
    void setCity(char *c);
    void setRegion(char *r);
    void setStreet(char *s);
    int getOwnerId() const { return ownerId; }
    int getPropertyId() const  { return propertyId; }
    bool getIsActive() const { return isActive; }

    void setOwnerId(int id) { ownerId = id; }
    void setPropertyId(int id) { propertyId = id; }
    void setIsActive(bool active) { isActive = active; }
};
void savePropertyToFile(const char *type, Property *prop);
LinkedList<Property *> loadPropertyFromFile();