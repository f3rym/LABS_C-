#pragma once

#include "../header.h"
#include "Commercial.h"

class Office : public Commercial
{
    int totalWorkplaces;
    int numHouse;
    int countPremises;
    int numFloor;

public:
    Office() : Commercial()
    {
        totalWorkplaces = 0;
        numHouse = 0;
        countPremises = 0;
        numFloor = 0;
    };

    Office(double area, int pr, char *c, char *r, char *s, int ownerId,
           char *cond, char *m, bool parking, bool secure,
           int workplaces, int numH, int premises, int floor)
        : Commercial(area, pr, c, r, s, ownerId, cond, m, parking, secure)
    {
        totalWorkplaces = workplaces;
        numHouse = numH;
        countPremises = premises;
        numFloor = floor;
    };

    Office(const Office &other) : Commercial(other)
    {
        totalWorkplaces = other.totalWorkplaces;
        numHouse = other.numHouse;
        countPremises = other.countPremises;
        numFloor = other.numFloor;
    };

    virtual ~Office() = default;

    friend std::ostream &operator<<(std::ostream &os, Office &ofc);
    friend std::istream &operator>>(std::istream &is, Office &ofc);
    virtual void info();

    int getTotalWorkplaces();
    int getNumHouse();
    int getCountPremises();
    int getNumFloor();

    void setTotalWorkplaces(int workplaces);
    void setNumHouse(int numH);
    void setCountPremises(int premises);
    void setNumFloor(int floor);
};