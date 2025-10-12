#ifndef PORTABLEMACHINE_H
#define PORTABLEMACHINE_H

#include "../header.h"
#include "computer.h"

class PortableMachine : public Computer
{
    int batteryHealth;
    int sizeDisplay;

public:
    PortableMachine() : Computer()
    {
        sizeDisplay = 0;
        batteryHealth = 0;
    };
    PortableMachine(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay)
        : Computer(name, processor, ram)
    {
        this->batteryHealth = batteryHealth;
        this->sizeDisplay = sizeDisplay;
    };
    PortableMachine(const PortableMachine &other) : Computer(other)
    {
        this->batteryHealth = other.batteryHealth;
        this->sizeDisplay = other.sizeDisplay;
    };
    PortableMachine &operator=(const PortableMachine &other);
    friend std::ostream &operator<<(std::ostream &os, PortableMachine &pm);
    friend std::istream &operator>>(std::istream &is, PortableMachine &pm);
    virtual void info() override;
    virtual ~PortableMachine() = default;
    int getBatteryHealth() const;
    int getSizeDisplay() const;
    void setBatteryHealth(int batteryHealth);
    void setSizeDisplay(int sizeDisplay);
};

#endif