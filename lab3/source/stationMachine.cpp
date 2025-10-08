#include "../header/stationaryMachine.h"

StationaryMachine::StationaryMachine() : Computer()
{
    PCISlots = 0;
}
StationaryMachine::StationaryMachine(char *name, char *processor, int ram, int PCISlots) : Computer(name, processor, ram)
{
    this->PCISlots = PCISlots;
}
StationaryMachine::StationaryMachine(const StationaryMachine &other) : Computer(other)
{
    this->PCISlots = other.PCISlots;
}
void StationaryMachine::print()
{
    Computer::print();
    std::cout << "Количество PCI слотов: " << PCISlots << std::endl;
}