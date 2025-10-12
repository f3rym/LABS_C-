#ifndef STATIONARYMACHINE_H
#define STATIONARYMACHINE_H

#include "../header.h"
#include "computer.h"

class StationaryMachine : public Computer
{
    int PCISlots;

public:
    StationaryMachine()
    {
        PCISlots = 0;
    };
    StationaryMachine(char *name, char *processor, int ram, int PCISlots)
        : Computer(name, processor, ram)
    {
        this->PCISlots = PCISlots;
    };
    StationaryMachine(const StationaryMachine &other) : Computer(other)
    {
        this->PCISlots = other.PCISlots;
    };
    StationaryMachine &operator=(const StationaryMachine &other);
    friend std::ostream &operator<<(std::ostream &os, StationaryMachine &sm);
    friend std::istream &operator>>(std::istream &is, StationaryMachine &sm);
    virtual void info() override;

    virtual ~StationaryMachine() = default;
    int getPCISlots() const;
    void setPCISlots(int PCISlots);
};

#endif