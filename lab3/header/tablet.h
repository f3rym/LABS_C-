#include "computer.h"
#include "portableMachine.h"

class Tablet : public PortableMachine
{
    char OS[MAX_STR];

public:
    Tablet();
    Tablet(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, char *OS);
    Tablet(const Tablet &other);
    virtual ~Tablet() {};
    virtual void print() override;
};