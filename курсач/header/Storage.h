#pragma once

#include "../header.h"
#include "Commercial.h"

class Storage : public Commercial
{
    char tempRegime[MAX_STR];
    int storageVolume;
    bool truckAccess;

public:
    Storage() : Commercial()
    {
        tempRegime[0] = '\0';
        storageVolume = 0;
        truckAccess = false;
    };

    Storage(double area, int pr, char *c, char *r, char *s, int ownerId,
            char *cond, char *m, bool parking, bool secure,
            char *temp, int volume, bool truck)
        : Commercial(area, pr, c, r, s, ownerId, cond, m, parking, secure)
    {
        strcpy_s(tempRegime, temp);
        storageVolume = volume;
        truckAccess = truck;
    };

    Storage(const Storage &other) : Commercial(other)
    {
        strcpy_s(tempRegime, other.tempRegime);
        storageVolume = other.storageVolume;
        truckAccess = other.truckAccess;
    };
    virtual void info();

    ~Storage() = default;

    friend std::ostream &operator<<(std::ostream &os, Storage &st);
    friend std::istream &operator>>(std::istream &is, Storage &st);

    virtual bool writeToFile(const char *filename);
    LinkedList<Storage> readFromFile(const char *filename);

    char *getTempRegime();
    int getStorageVolume();
    bool getTruckAccess();

    void setTempRegime(char *temp);
    void setStorageVolume(int volume);
    void setTruckAccess(bool truck);
};