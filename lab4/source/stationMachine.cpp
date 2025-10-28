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

void StationaryMachine::setMenu()
{
    ComputingMachine::setMenu(); 
    int choice;
    int intValue;

    do
    {
        std::cout << "\n=== Редактирование параметров стационарной машины ===" << std::endl;
        std::cout << "1. Изменить количество PCI слотов (" << PCISlots << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите количество PCI слотов: ";
            std::cin >> intValue;
            setPCISlots(intValue);
            std::cout << "Количество PCI слотов изменено!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
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
    std::cout << std::setw(20) << "PCI Slots";
}

int StationaryMachine::getPCISlots() const { return PCISlots; };
void StationaryMachine::setPCISlots(int PCISlots)
{
    this->PCISlots = PCISlots;
}