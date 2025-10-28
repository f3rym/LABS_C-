#pragma once

#include "../header.h"
#include "Property.h"

class Commercial : public Property
{
    char condition[MAX_STR];
    char metro[MAX_STR];
    bool hasParking;
    bool secureSystem;

public:
    Commercial() : Property()
    {
        condition[0] = '\0';
        metro[0] = '\0';
        hasParking = false;
        secureSystem = false;
    };

    Commercial(double area, int pr, char *c, char *r, char *s, int ownerId,
         char *cond, char *m, bool parking, bool secure) : Property(area, pr, c, r, s, ownerId)
    {
        strcpy_s(condition, cond);
        strcpy_s(metro, m);
        hasParking = parking;
        secureSystem = secure;
    };

    Commercial(const Commercial &other) : Property(other)
    {
        strcpy_s(condition, other.condition);
        strcpy_s(metro, other.metro);
        hasParking = other.hasParking;
        secureSystem = other.secureSystem;
    };

    virtual ~Commercial() = default;
    virtual void info() override;

    friend std::ostream &operator<<(std::ostream &os, Commercial &com);
    friend std::istream &operator>>(std::istream &is, Commercial &com);
    virtual bool writeToFile(std::ofstream &file) override;
    Commercial readFromFile(std::ifstream &file);

    char *getCondition();
    char *getMetro(); 
    bool getHasParking(); 
    bool getSecureSystem(); 

    void setCondition(char *cond);
    void setMetro(char *m); 
    void setHasParking(bool parking); 
    void setSecureSystem(bool secure);
};