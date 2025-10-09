#include "../header.h"
#include "portableMachine.h"

class Laptop : public PortableMachine
{
    bool hasBacklitKeyboard;

public:
    Laptop() : PortableMachine()
    {
        bool hasBacklitKeyboard;
    };
    Laptop(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay, bool hasBacklitKeyboard)
        : PortableMachine(name, processor, ram, batteryHealth, sizeDisplay)
    {
        this->hasBacklitKeyboard = hasBacklitKeyboard;
    };
    Laptop(const Laptop &other) : PortableMachine(other)
    {
        this->hasBacklitKeyboard = other.hasBacklitKeyboard;
    };
    friend std::ostream &operator<<(std::ostream &os, Laptop &lap);
    friend std::istream &operator>>(std::istream &is, Laptop &lap);
    virtual int getPowerConsumption() override;
    virtual void info() override;
    virtual ~Laptop() = default;
};