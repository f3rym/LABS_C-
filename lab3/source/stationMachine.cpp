#include "../header/stationaryMachine.h"

StationaryMachine &StationaryMachine::operator=(const StationaryMachine &other)
{
    if (this != &other)
    {
        Computer::operator=(other);
        PCISlots = other.PCISlots;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, StationaryMachine &sm)
{
    Computer &comp = sm;
    os << comp;
    os << "Количество PCI слотов: " << sm.PCISlots << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, StationaryMachine &sm)
{
    Computer &comp = sm;
    is >> comp;
    std::cout << "Введите количество PCI слотов: ";
    is >> sm.PCISlots;
    return is;
}

void StationaryMachine::info()
{
    Computer::info();
    std::cout << "- Стационарная";
}

int StationaryMachine::getPCISlots() const {return PCISlots;};
void StationaryMachine::setPCISlots(int PCISlots) 
{
    this->PCISlots = PCISlots;
}