#include "computer.h"

class StationaryMachine : public Computer
{
    int PCISlots;

public:
    StationaryMachine();
    StationaryMachine(char *name, char *processor, int ram, int PCISlots);
    StationaryMachine(const StationaryMachine &other);
    virtual ~StationaryMachine() {};
    virtual void print() override;
};