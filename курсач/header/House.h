#pragma once

#include "../header.h"
#include "PrivateSector.h"

class House : public PrivateSector
{
    int numHouse;
    int countRoom;
    int floorCount;
    char waterSupply[MAX_STR];
    bool typeHeating;
    char wallMaterial[MAX_STR];

public:
    House() : PrivateSector()
    {
        numHouse = 0;
        countRoom = 0;
        floorCount = 0;
        waterSupply[0] = '\0';
        typeHeating = false;
        wallMaterial[0] = '\0';
    };

    House(double area, int pr, char *c, char *r, char *s, int ownerId,
          double sizeReg, double distMKAD, char *rel, bool utils,
          int numH, int rooms, int floors, char *water, bool heating, char *material)
        : PrivateSector(area, pr, c, r, s, ownerId, sizeReg, distMKAD, rel, utils)
    {
        numHouse = numH;
        countRoom = rooms;
        floorCount = floors;
        strcpy_s(waterSupply, water);
        typeHeating = heating;
        strcpy_s(wallMaterial, material);
    };

    House(const House &other) : PrivateSector(other)
    {
        numHouse = other.numHouse;
        countRoom = other.countRoom;
        floorCount = other.floorCount;
        strcpy_s(waterSupply, other.waterSupply);
        typeHeating = other.typeHeating;
        strcpy_s(wallMaterial, other.wallMaterial);
    };

    ~House() = default;
    virtual void info();

    friend std::ostream &operator<<(std::ostream &os, House &house);
    friend std::istream &operator>>(std::istream &is, House &house);

    virtual bool writeToFile(const char *filename);
    LinkedList<House> readFromFile(const char *filename);
    int getNumHouse();
    int getCountRoom();
    int getFloorCount();
    char *getWaterSupply();
    bool getTypeHeating();
    char *getWallMaterial();
    void setNumHouse(int numH);
    void setCountRoom(int rooms);
    void setFloorCount(int floors);
    void setWaterSupply(char *water);
    void setTypeHeating(bool heating);
    void setWallMaterial(char *material);
};