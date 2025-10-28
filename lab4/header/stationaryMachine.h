#pragma once

#include "../header.h"
#include "computingMachine.h"

class StationaryMachine : public ComputingMachine
{
    int PCISlots;

public:
    StationaryMachine()
    {
        PCISlots = 0;
    };
    StationaryMachine(char *name, char *processor, int ram, int PCISlots)
        : ComputingMachine(name, processor, ram)
    {
        this->PCISlots = PCISlots;
    };
    StationaryMachine(const StationaryMachine &other) : ComputingMachine(other)
    {
        this->PCISlots = other.PCISlots;
    };
    StationaryMachine &operator=(const StationaryMachine &other);
    friend std::ostream &operator<<(std::ostream &os, StationaryMachine &sm);
    friend std::istream &operator>>(std::istream &is, StationaryMachine &sm);
    virtual void info() override;
    virtual void setMenu() override;
    virtual ~StationaryMachine() = default;
    int getPCISlots() const;
    void setPCISlots(int PCISlots);
};
