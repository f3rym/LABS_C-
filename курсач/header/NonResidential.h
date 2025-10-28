#pragma once

#include "../header.h"
#include "Property.h"

class NonResidential : public Property
{
    char purpose[MAX_STR];
    bool hasVentilation;
    bool hasFireSafety;

public:
    NonResidential() : Property()
    {
        purpose[0] = '\0';
        hasVentilation = false;
        hasFireSafety = false;
    };

    NonResidential(double area, int pr, char *c, char *r, char *s, int ownerId,
                   char *purp, bool vent, bool fire) : Property(area, pr, c, r, s, ownerId)
    {
        strcpy_s(purpose, purp);
        hasVentilation = vent;
        hasFireSafety = fire;
    };

    NonResidential(const NonResidential &other) : Property(other)
    {
        strcpy_s(purpose, other.purpose);
        hasVentilation = other.hasVentilation;
        hasFireSafety = other.hasFireSafety;
    };

    virtual ~NonResidential() = default;
    friend std::ostream &operator<<(std::ostream &os, NonResidential &noRes);
    friend std::istream &operator>>(std::istream &is, NonResidential &noRes);
    virtual void info() override;
    virtual bool writeToFile(std::ofstream &file) override;
    NonResidential readFromFile(std::ifstream &file);

    char *getPurpose();
    bool getHasVentilation();
    bool getHasFireSafety();

    void setPurpose(char *purp);
    void setHasVentilation(bool vent);
    void setHasFireSafety(bool fire);
};