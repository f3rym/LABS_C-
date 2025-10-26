#pragma once

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
    Apartment() : Property()
    {
        countRoom = 0;
        numHouse = 0;
        numApartment = 0;
        numFloor = 0;
        metro[0] = '\0';
        repair = false;
    };

    Apartment(double area, int pr, char *c, char *r, char *s,
              int rooms, int house, int apartment, int floor, char *m, bool rep, int ownerId) : Property(area, pr, c, r, s, ownerId)
    {
        countRoom = rooms;
        numHouse = house;
        numApartment = apartment;
        numFloor = floor;
        strcpy_s(metro, m);
        repair = rep;
    };

    Apartment(const Apartment &other) : Property(other)
    {
        countRoom = other.countRoom;
        numFloor = other.numFloor;
        numHouse = other.numHouse;
        numApartment = other.numApartment;
        strcpy_s(metro, other.metro);
        repair = other.repair;
    };

    virtual ~Apartment() = default;
    virtual void info();

    friend std::ostream &operator<<(std::ostream &os, Apartment &apart);
    friend std::istream &operator>>(std::istream &is, Apartment &apart);
    int getCountRoom();
    int getNumHouse();
    int getNumApartment();
    int getNumFloor();
    char *getMetro();
    bool getRepair();

    void setCountRoom(int rooms);
    void setNumHouse(int house);
    void setNumApartment(int apartment);
    void setNumFloor(int floor);
    void setMetro(char *m);
    void setRepair(bool rep);
};