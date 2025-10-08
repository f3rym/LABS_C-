#include "../header.h"

#include "../header/stationaryMachine.h"

class MonoBlock : public StationaryMachine
{
    int sizeDisplay;
    bool touchScreen;

public:
    MonoBlock();
    MonoBlock(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, bool touchScreen);
    MonoBlock(const MonoBlock &other);
    virtual ~MonoBlock() {};
    virtual void print() override;
};