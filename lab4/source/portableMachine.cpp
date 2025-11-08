#include "../header.h"
#include "../header/portableMachine.h"

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
    ComputingMachine &com = pm;
    is >> com;
    std::cout << "Введите ёмкость батареи(mAh): ";
    is >> pm.batteryHealth;
    std::cout << "Введите размер дисплея(дюйм): ";
    is >> pm.sizeDisplay;
    return is;
}

void portableMachine::info()
{
    ComputingMachine::info();
    std::cout << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display";
}
void portableMachine::sortList(LinkedList<ComputingMachine*> &list)
{
    ComputingMachine::sortList(list);

    int choice;

    if (choice != 0)
    {
        std::cout << "\n=== Сортировка параметров портативного устройства ===" << std::endl;
        std::cout << "1. Сортировка по емкости батареи" << std::endl;
        std::cout << "2. Сортировка по размеру дисплея" << std::endl;
        std::cout << "0. Пропустить" << std::endl;
        std::cout << "Выберите параметр: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < list.getSize() - 1; ++i)
            {
                for (int j = 0; j < list.getSize() - i - 1; ++j)
                {
                    portableMachine *a = dynamic_cast<portableMachine *>(list[j]);
                    portableMachine *b = dynamic_cast<portableMachine *>(list[j + 1]);
                    if (a->batteryHealth < b->batteryHealth)
                    {
                        portableMachine* temp = a;
                        a = b;
                        b = temp;
                    }
                }
            }
            std::cout << "Сортировка по батарее завершена!" << std::endl;
            break;

        case 2: 
            for (int i = 0; i < list.getSize() - 1; ++i)
            {
                for (int j = 0; j < list.getSize() - i - 1; ++j)
                {
                    portableMachine *a = dynamic_cast<portableMachine *>(list[j]);
                    portableMachine *b = dynamic_cast<portableMachine *>(list[j + 1]);
                    if (a->sizeDisplay < b->sizeDisplay)
                    {
                        std::swap(list[j], list[j + 1]);
                    }
                }
            }
            std::cout << "Сортировка по размеру дисплея завершена!" << std::endl;
            break;

        case 0:
            std::cout << "Сортировка пропущена!" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    }
}

void portableMachine::setMenu()
{
    ComputingMachine::setMenu();

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
            std::cin >> intValue;
            setBatteryHealth(intValue);
            std::cout << "Емкость батареи изменена!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            std::cin >> intValue;
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