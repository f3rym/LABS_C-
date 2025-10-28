#ifndef MONO_H
#define MONO_H

#include "../header.h"
#include "../header/stationaryMachine.h"
#include "listNode.h"

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
    MonoBlock &operator=(const MonoBlock &other);
    friend std::ostream &operator<<(std::ostream &os, MonoBlock &mono);
    friend std::istream &operator>>(std::istream &is, MonoBlock &mono);
    void info() override;
    void setMenu() override;

    virtual ~MonoBlock() = default;
    int getSizeDisplay() const;
    bool getTouchScreen() const;
    void setTouchScreen(bool touchScreen);
    void setSizeDisplay(int sizeDisplay);
};

#endif