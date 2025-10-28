#pragma once

#include "../header.h"
#include "NonResidential.h"

class Garage : public NonResidential
{
    bool hasElectricity;
    bool hasHeating;

public:
    Garage() : NonResidential()
    {
        hasElectricity = false;
        hasHeating = false;
    };

    Garage(double area, int pr, char *c, char *r, char *s, int ownerId,
           char *purp, bool vent, bool fire, bool electricity, bool heating)
        : NonResidential(area, pr, c, r, s, ownerId, purp, vent, fire)
    {
        hasElectricity = electricity;
        hasHeating = heating;
    };

    Garage(const Garage &other) : NonResidential(other)
    {
        hasElectricity = other.hasElectricity;
        hasHeating = other.hasHeating;
    };

    virtual ~Garage() = default;
    virtual void info();

    friend std::ostream &operator<<(std::ostream &os, Garage &gar);
    friend std::istream &operator>>(std::istream &is, Garage &gar);
    virtual bool writeToFile(const char *filename);
    LinkedList<Garage> readFromFile(const char *filename);
    bool getHasElectricity();
    bool getHasHeating();

    void setHasElectricity(bool electricity);
    void setHasHeating(bool heating);
};