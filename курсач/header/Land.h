#pragma once

#include "../header.h"
#include "PrivateSector.h"

class Land : public PrivateSector
{
    char landType[MAX_STR];

public:
    Land() : PrivateSector()
    {
        landType[0] = '\0';
    };

    Land(double area, int pr, char *c, char *r, char *s, int ownerId,
         double sizeReg, double distMKAD, char *rel, bool utils, char *type)
        : PrivateSector(area, pr, c, r, s, ownerId, sizeReg, distMKAD, rel, utils)
    {
        strcpy_s(landType, type);
    };

    Land(const Land &other) : PrivateSector(other)
    {
        strcpy_s(landType, other.landType);
    };
    virtual void info();

    ~Land() = default;
    friend std::ostream &operator<<(std::ostream &os, Land &land);
    friend std::istream &operator>>(std::istream &is, Land &land);

    virtual bool writeToFile(const char *filename);
    LinkedList<Land> readFromFile(const char *filename);
    char *getLandType();

    void setLandType(char *type);
};