#ifndef PORTABLEMACHINE_H
#define PORTABLEMACHINE_H

#include "../header.h"
#include "computingMachine.h"

class PortableMachine : public ComputingMachine
{
    int batteryHealth;
    int sizeDisplay;

public:
    PortableMachine() : ComputingMachine()
    {
        sizeDisplay = 0;
        batteryHealth = 0;
    };
    PortableMachine(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay)
        : ComputingMachine(name, processor, ram)
    {
        this->batteryHealth = batteryHealth;
        this->sizeDisplay = sizeDisplay;
    };
    PortableMachine(const PortableMachine &other) : ComputingMachine(other)
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