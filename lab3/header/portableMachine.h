#include "../computer.h"

class PortableMachine : public Computer
{
    int butteryHealth;
    int sizeDisplay;

public:
    PortableMachine();
    PortableMachine(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay);
    PortableMachine(const PortableMachine &other);
    virtual ~PortableMachine() {};
    virtual void print() override;
};