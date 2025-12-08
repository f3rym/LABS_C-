#ifndef TABLET_H
#define TABLET_H

#include "../header.h"
#include "portableMachine.h"

class Tablet : public portableMachine
{
    char OS[MAX_STR];

public:
    Tablet() : portableMachine()
    {
        OS[MAX_STR];
    };
    Tablet(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay, char *OS)
        : portableMachine(name, processor, ram, batteryHealth, sizeDisplay)
    {
        strcpy_s(this->OS, OS);
    };
    Tablet(const Tablet &other) : portableMachine(other)
    {
        strcpy_s(this->OS, other.OS);
    };
    Tablet &operator=(const Tablet &other);

    friend std::ostream &operator<<(std::ostream &os, const Tablet &mono);
    friend std::istream &operator>>(std::istream &is, Tablet &mono);
    void info();
    void setMenu();
    virtual ~Tablet() = default;
    const char *getOS() const;
    void setOS(const char *OS);

    void writeToStream(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;
};

#endif