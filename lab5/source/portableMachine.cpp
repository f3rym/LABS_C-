#include "../header.h"
#include "../header/portableMachine.h"
#include "../header/ExpInput.h"
portableMachine &portableMachine::operator=(const portableMachine &other)
{
    if (this != &other)
    {
        ComputingMachine::operator=(other);
        batteryHealth = other.batteryHealth;
        sizeDisplay = other.sizeDisplay;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, portableMachine &pm)
{
    ComputingMachine &com = pm;
    os << com;
    os << std::setw(20) << pm.batteryHealth;
    os << std::setw(20) << pm.sizeDisplay;
    return os;
}

std::istream &operator>>(std::istream &is, portableMachine &pm)
{
    ExpInput exp;
    ComputingMachine &com = pm;
    is >> com;
    std::cout << "Введите ёмкость батареи(mAh): ";
    pm.batteryHealth = exp.isNumber(std::cin, 0, INT_MAX);
    std::cout << "Введите размер дисплея(дюйм): ";
    pm.sizeDisplay = exp.isNumber(std::cin, 0, INT_MAX);

    return is;
}

void portableMachine::info()
{
    ComputingMachine::info();
    std::cout << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display";
}

void portableMachine::setMenu()
{
    ComputingMachine::setMenu();
    ExpInput exp;
    int choice;
    int intValue;

    do
    {
        std::cout << "\n=== Редактирование параметров портативного устройства ===" << std::endl;
        std::cout << "1. Изменить емкость батареи (" << batteryHealth << " mAh)" << std::endl;
        std::cout << "2. Изменить размер дисплея (" << sizeDisplay << "\")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новую емкость батареи (mAh): ";
            intValue = exp.isNumber(std::cin, 0, INT_MAX);
            setBatteryHealth(intValue);
            std::cout << "Емкость батареи изменена!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            intValue = exp.isNumber(std::cin, 0, INT_MAX);
            setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

int portableMachine::getBatteryHealth() const
{
    return batteryHealth;
}
int portableMachine::getSizeDisplay() const { return sizeDisplay; }
void portableMachine::setBatteryHealth(int batteryHealth)
{
    this->batteryHealth = batteryHealth;
}
void portableMachine::setSizeDisplay(int sizeDisplay)
{
    this->sizeDisplay = sizeDisplay;
}