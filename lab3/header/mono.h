#include "../header.h"

#include "../header/stationaryMachine.h"

class MonoBlock : public StationaryMachine
{
    int sizeDisplay;
    bool touchScreen;

public:
    MonoBlock() : StationaryMachine()
    {
        sizeDisplay = 0;
        touchScreen = false;
    };
    MonoBlock(char *name, char *processor, int ram, int batteryHealth, int PCISlots, int sizeDisplay, bool touchScreen)
        : StationaryMachine(name, processor, ram, PCISlots)
    {
        this->sizeDisplay = sizeDisplay;
        this->touchScreen = touchScreen;
    };
    MonoBlock(const MonoBlock &other) : StationaryMachine(other)
    {
        this->sizeDisplay = other.sizeDisplay;
        this->touchScreen = other.touchScreen;
    };
    friend std::ostream &operator<<(std::ostream &os, MonoBlock &mono);
    friend std::istream &operator>>(std::istream &is, MonoBlock &mono);
    virtual int getPowerConsumption() override;
    virtual void info() override;

    virtual ~MonoBlock() = default;
};