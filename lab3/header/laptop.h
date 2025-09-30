#include "portableMachine.h"

class Laptop : public PortableMachine
{
    bool hasBacklitKeyboard;

public:
    Laptop();
    Laptop(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, bool hasBacklitKeyboard);
    Laptop(const Laptop &other);
    virtual ~Laptop() {};
    virtual void print() override;
};