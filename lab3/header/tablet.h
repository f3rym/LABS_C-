#include "../header.h"
#include "portableMachine.h"

class Tablet : public PortableMachine
{
    char OS[MAX_STR];

public:
    Tablet() : PortableMachine()
    {
        char OS[MAX_STR];
    };
    Tablet(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay, char *OS)
        : PortableMachine(name, processor, ram, batteryHealth, sizeDisplay)
    {
        std::strcpy(this->OS, OS);
    };
    Tablet(const Tablet &other) : PortableMachine()
    {
        std::strcpy(this->OS, other.OS);
    };

    friend std::ostream &operator<<(std::ostream &os, Tablet &mono);
    friend std::istream &operator>>(std::istream &is, Tablet &mono);
    virtual int getPowerConsumption() override;
    virtual void info() override;
    virtual ~Tablet() = default;
};