#include "../header/stationaryMachine.h"

StationaryMachine &StationaryMachine::operator=(const StationaryMachine &other)
{
    if (this != &other)
    {
        ComputingMachine::operator=(other);
        PCISlots = other.PCISlots;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, StationaryMachine &sm)
{
    ComputingMachine &comp = sm;
    os << comp;
    os << std::setw(20) << sm.PCISlots;
    return os;
}

std::istream &operator>>(std::istream &is, StationaryMachine &sm)
{
    ComputingMachine &comp = sm;
    is >> comp;
    std::cout << "Введите количество PCI слотов: ";
    is >> sm.PCISlots;
    return is;
}

void StationaryMachine::info()
{
    ComputingMachine::info();
    std::cout << "- Стационарная";
}

int StationaryMachine::getPCISlots() const { return PCISlots; };
void StationaryMachine::setPCISlots(int PCISlots)
{
    this->PCISlots = PCISlots;
}