#ifndef PORTABLEMACHINE_H
#define PORTABLEMACHINE_H

#include "../header.h"
#include "computingMachine.h"
#include "listNode.h"

class portableMachine : public ComputingMachine
{
    int batteryHealth;
    int sizeDisplay;

public:
    portableMachine() : ComputingMachine()
    {
        sizeDisplay = 0;
        batteryHealth = 0;
    };
    portableMachine(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay)
        : ComputingMachine(name, processor, ram)
    {
        this->batteryHealth = batteryHealth;
        this->sizeDisplay = sizeDisplay;
    };
    portableMachine(const portableMachine &other) : ComputingMachine(other)
    {
        this->batteryHealth = other.batteryHealth;
        this->sizeDisplay = other.sizeDisplay;
    };
    portableMachine &operator=(const portableMachine &other);
    friend std::ostream &operator<<(std::ostream &os, portableMachine &pm);
    friend std::istream &operator>>(std::istream &is, portableMachine &pm);
    bool operator==(const portableMachine &other) const
    {
        return ComputingMachine::operator==(other) &&
               batteryHealth == other.batteryHealth &&
               sizeDisplay == other.sizeDisplay;
    }

    virtual void info() override;
    virtual void setMenu() override;
    virtual void sortList(LinkedList<ComputingMachine*> &list) override;
    ~portableMachine() = default;
    int getBatteryHealth() const;
    int getSizeDisplay() const;
    void setBatteryHealth(int batteryHealth);
    void setSizeDisplay(int sizeDisplay);
};

#endif