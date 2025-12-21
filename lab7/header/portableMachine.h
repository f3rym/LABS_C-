#ifndef PORTABLEMACHINE_H
#define PORTABLEMACHINE_H

#include "../header.h"
#include "computingMachine.h"

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
    friend std::ostream &operator<<(std::ostream &os, const portableMachine &pm);
    friend std::istream &operator>>(std::istream &is, portableMachine &pm);
    virtual void info() override;
    virtual void setMenu() override;
    virtual void sortList(std::vector<ComputingMachine *> &list) override;
    ~portableMachine() = default;
    int getBatteryHealth() const;
    int getSizeDisplay() const;
    void setBatteryHealth(int batteryHealth);
    void setSizeDisplay(int sizeDisplay);

    void writeToStream(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;
};

#endif