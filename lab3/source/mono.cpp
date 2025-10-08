#include "../header.h"
#include "../header/mono.h"
// #include "../header/stationaryMachine.h"

MonoBlock::MonoBlock() : StationaryMachine()
{
    sizeDisplay = 0;
    touchScreen = false;
}
MonoBlock::MonoBlock(char *name, char *processor, int ram, int PCISlots, int sizeDisplay, bool touchScreen) : StationaryMachine(name, processor, ram, PCISlots)
{
    this->sizeDisplay = sizeDisplay;
    this->touchScreen = touchScreen;
}
MonoBlock::MonoBlock(const MonoBlock &other) : StationaryMachine(other)
{
    this->sizeDisplay = other.sizeDisplay;
    this->touchScreen = other.touchScreen;
}
void MonoBlock::print()
{
    StationaryMachine::print();
    std::cout << "Размер дисплея: " << sizeDisplay << " дюймов" << std::endl;
    if (touchScreen == true)
        std::cout << "Имеется Сенсорный экран." << std::endl;
}