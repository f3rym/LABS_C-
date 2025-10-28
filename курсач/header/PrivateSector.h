#pragma once

#include "../header.h"
#include "Property.h"

class PrivateSector : public Property
{
    double sizeRegion;
    double distanceToMKAD;
    char relief[MAX_STR];
    bool hasUtilities;

public:
    PrivateSector() : Property()
    {
        sizeRegion = 0.0;
        distanceToMKAD = 0.0;
        relief[0] = '\0';
        hasUtilities = false;
    };

    PrivateSector(double area, int pr, char *c, char *r, char *s, int ownerId,
                  double sizeReg, double distMKAD, char *rel, bool utils)
        : Property(area, pr, c, r, s, ownerId)
    {
        sizeRegion = sizeReg;
        distanceToMKAD = distMKAD;
        strcpy_s(relief, rel);
        hasUtilities = utils;
    };

    PrivateSector(const PrivateSector &other) : Property(other)
    {
        sizeRegion = other.sizeRegion;
        distanceToMKAD = other.distanceToMKAD;
        strcpy_s(relief, other.relief);
        hasUtilities = other.hasUtilities;
    };

    virtual ~PrivateSector() = default;
    virtual void info() override;

    friend std::ostream &operator<<(std::ostream &os, PrivateSector &apart);
    friend std::istream &operator>>(std::istream &is, PrivateSector &apart);
    PrivateSector readFromFile(std::ifstream &file);
    virtual bool writeToFile(std::ofstream &file) override;
    double getSizeRegion();
    double getDistanceToMKAD();
    char *getRelief();
    bool getHasUtilities();

    void setSizeRegion(double sizeReg);
    void setDistanceToMKAD(double distMKAD);
    void setRelief(char *rel);
    void setHasUtilities(bool utils);
};