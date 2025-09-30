#include "computer.h"
#include "portableMachine.h"
#include "stationaryMachine.h"
#include "monoblock.h"

Computer::Computer()
{
    ram = 0;
    name[0] = '\0';
    processor[0] = '\0';
}
Computer::Computer(char *name, char *processor, int ram)
{
    std::strcpy(this->name, name);
    std::strcpy(this->processor, processor);
    this->ram = ram;
}
Computer::Computer(const Computer &other)
{
    std::strcpy(this->name, other.name);
    std::strcpy(this->processor, other.processor);
    this->ram = other.ram;
}
void Computer::print()
{
    std::cout << "Модель: " << name << std::endl;
    std::cout << "Процессор: " << processor << std::endl;
    std::cout << "Оперативная память: " << ram << " GB" << std::endl;
}

std::istream &operator>>(std::istream &is, Computer &s)
{
    std::cout << "Введите модель: ";
    is.getline(s.name, MAX_STR);
    std::cout << "Введите процессор: ";
    is.getline(s.processor, MAX_STR);
    std::cout << "Введите кол-во ОЗУ: ";
    is >> s.ram;

    return is;
}

std::ostream &operator<<(std::ostream &os, Computer &s)
{
    os << "Модель: " << s.name << std::endl;
    os << "Процессор: " << s.processor << std::endl;
    os << "Оперативная память: " << s.ram << " GB" << std::endl;
    return os;
}

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

MonoBLock::MonoBLock() : StationaryMachine()
{
    sizeDisplay = 0;
    touchScreen = 0;
}
MonoBLock::MonoBLock(char *name, char *processor, int ram, int PCISlots, int sizeDisplay, bool touchScreen) : StationaryMachine(name, processor, ram, PCISlots)
{
    this->sizeDisplay = sizeDisplay;
    this->touchScreen = touchScreen;
}
MonoBLock::MonoBLock(const MonoBLock &other) : StationaryMachine(other)
{
    this->sizeDisplay = other.sizeDisplay;
    this->touchScreen = other.touchScreen;
}
void MonoBLock::print()
{
    StationaryMachine::print();
    std::cout << "Размер дисплея: " << sizeDisplay << " дюймов" << std::endl;
    if (touchScreen == true)
        std::cout << "Имеется Сенсорный экран." << std::endl;
}
/// @brief //
PortableMachine::PortableMachine() : Computer()
{
    sizeDisplay = 0;
    butteryHealth = 0;
}
PortableMachine::PortableMachine(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay) : Computer(name, processor, ram)
{
    this->butteryHealth = butteryHealth;
    this->sizeDisplay = sizeDisplay;
}
PortableMachine::PortableMachine(const PortableMachine &other) : Computer(other)
{
    this->butteryHealth = other.butteryHealth;
    this->sizeDisplay = other.sizeDisplay;
}
void PortableMachine::print()
{
    Computer::print();
    std::cout << "Объем батареи: " << butteryHealth << std::endl;
    std::cout << "Размер дисплея: " << sizeDisplay << " дюймов." << std::endl;
}

///////////////

Laptop::Laptop() : PortableMachine()
{
    bool hasBacklitKeyboard;
}
Laptop::Laptop(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, bool hasBacklitKeyboard) : PortableMachine(name, processor, ram, butteryHealth, sizeDisplay)
{
    this->hasBacklitKeyboard = hasBacklitKeyboard;
}
Laptop::Laptop(const Laptop &other) : PortableMachine(other)
{
    this->hasBacklitKeyboard = other.hasBacklitKeyboard;
}
void Laptop::print()
{
    PortableMachine::print();
    std::cout << "Клавиатура ";

    if (hasBacklitKeyboard == true)
        std::cout << "имеет подсветку." << std::endl;
    else
        std::cout << "НЕ имеет подсветку." << std::endl;
}
////////////
Tablet::Tablet() : PortableMachine()
{
    char OS[MAX_STR];
}
Tablet::Tablet(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, char *OS) : PortableMachine(name, processor, ram, butteryHealth, sizeDisplay)
{
    std::strcpy(this->OS, OS);
}
Tablet::Tablet(const Tablet &other) : PortableMachine(other)
{
    std::strcpy(this->OS, other.OS);
}
void Tablet::print()
{
    PortableMachine::print();
    std::cout << "Операционная система: " << OS << std::endl;
}

void showMenu()
{
    std::cout << "\n=== МЕНЮ КОМПЬЮТЕРНОЙ ТЕХНИКИ ===" << std::endl;
    std::cout << "1. Создать обычный компьютер" << std::endl;
    std::cout << "2. Создать стационарную машину" << std::endl;
    std::cout << "3. Создать моноблок" << std::endl;
    std::cout << "4. Создать портативную машину" << std::endl;
    std::cout << "5. Создать ноутбук" << std::endl;
    std::cout << "6. Создать планшет" << std::endl;
    std::cout << "7. Показать все устройства" << std::endl;
    std::cout << "8. Тест полиморфизма" << std::endl;
    std::cout << "9. Выйти" << std::endl;
    std::cout << "Выберите опцию: ";
}

void menu()
{
    const int MAX_DEVICES = 10;
    Computer *devices[MAX_DEVICES];
    int deviceCount = 0;
    int choice;

    // Буферы для ввода
    char name[MAX_STR], processor[MAX_STR], os[MAX_STR];
    int ram, pciSlots, battery, displaySize;
    bool touch, backlit;

    do
    {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера

        switch (choice)
        {
        case 1:
        {
            // Создать обычный компьютер
            if (deviceCount < MAX_DEVICES)
            {
                std::cin >> devices[deviceCount];

                devices[deviceCount] = new Computer(name, processor, ram);
                deviceCount++;
                std::cout << "Компьютер создан!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит устройств!" << std::endl;
            }
            break;
        }

        case 2:
        {
            // Создать стационарную машину
            if (deviceCount < MAX_DEVICES)
            {
                std::cout << "Введите название: ";
                std::cin.getline(name, MAX_STR);
                std::cout << "Введите процессор: ";
                std::cin.getline(processor, MAX_STR);
                std::cout << "Введите объем RAM (GB): ";
                std::cin >> ram;
                std::cout << "Введите количество PCI слотов: ";
                std::cin >> pciSlots;

                devices[deviceCount] = new StationaryMachine(name, processor, ram, pciSlots);
                deviceCount++;
                std::cout << "Стационарная машина создана!" << std::endl;
            }
            break;
        }

        case 3:
        {
            // Создать моноблок
            if (deviceCount < MAX_DEVICES)
            {
                std::cout << "Введите название: ";
                std::cin.getline(name, MAX_STR);
                std::cout << "Введите процессор: ";
                std::cin.getline(processor, MAX_STR);
                std::cout << "Введите объем RAM (GB): ";
                std::cin >> ram;
                std::cout << "Введите количество PCI слотов: ";
                std::cin >> pciSlots;
                std::cout << "Введите размер дисплея (дюймы): ";
                std::cin >> displaySize;
                std::cout << "Есть сенсорный экран? (1-да, 0-нет): ";
                std::cin >> touch;

                devices[deviceCount] = new MonoBLock(name, processor, ram, pciSlots, displaySize, touch);
                deviceCount++;
                std::cout << "Моноблок создан!" << std::endl;
            }
            break;
        }

        case 4:
        {
            // Создать портативную машину
            if (deviceCount < MAX_DEVICES)
            {
                std::cout << "Введите название: ";
                std::cin.getline(name, MAX_STR);
                std::cout << "Введите процессор: ";
                std::cin.getline(processor, MAX_STR);
                std::cout << "Введите объем RAM (GB): ";
                std::cin >> ram;
                std::cout << "Введите емкость батареи (mAh): ";
                std::cin >> battery;
                std::cout << "Введите размер дисплея (дюймы): ";
                std::cin >> displaySize;

                devices[deviceCount] = new PortableMachine(name, processor, ram, battery, displaySize);
                deviceCount++;
                std::cout << "Портативная машина создана!" << std::endl;
            }
            break;
        }

        case 5:
        {
            // Создать ноутбук
            if (deviceCount < MAX_DEVICES)
            {
                std::cout << "Введите название: ";
                std::cin.getline(name, MAX_STR);
                std::cout << "Введите процессор: ";
                std::cin.getline(processor, MAX_STR);
                std::cout << "Введите объем RAM (GB): ";
                std::cin >> ram;
                std::cout << "Введите емкость батареи (mAh): ";
                std::cin >> battery;
                std::cout << "Введите размер дисплея (дюймы): ";
                std::cin >> displaySize;
                std::cout << "Есть подсветка клавиатуры? (1-да, 0-нет): ";
                std::cin >> backlit;

                devices[deviceCount] = new Laptop(name, processor, ram, battery, displaySize, backlit);
                deviceCount++;
                std::cout << "Ноутбук создан!" << std::endl;
            }
            break;
        }

        case 6:
        {
            // Создать планшет
            if (deviceCount < MAX_DEVICES)
            {
                std::cout << "Введите название: ";
                std::cin.getline(name, MAX_STR);
                std::cout << "Введите процессор: ";
                std::cin.getline(processor, MAX_STR);
                std::cout << "Введите объем RAM (GB): ";
                std::cin >> ram;
                std::cout << "Введите емкость батареи (mAh): ";
                std::cin >> battery;
                std::cout << "Введите размер дисплея (дюймы): ";
                std::cin >> displaySize;
                std::cout << "Введите ОС: ";
                std::cin.ignore();
                std::cin.getline(os, MAX_STR);

                devices[deviceCount] = new Tablet(name, processor, ram, battery, displaySize, os);
                deviceCount++;
                std::cout << "Планшет создан!" << std::endl;
            }
            break;
        }

        case 7:
        {
            // Показать все устройства
            if (deviceCount == 0)
            {
                std::cout << "Нет созданных устройств!" << std::endl;
            }
            else
            {
                std::cout << "\n=== ВСЕ УСТРОЙСТВА ===" << std::endl;
                for (int i = 0; i < deviceCount; i++)
                {
                    std::cout << "\n--- Устройство " << (i + 1) << " ---" << std::endl;
                    std::cout << devices[i];
                }
            }
            break;
        }

        case 8:
        {
            // Тест полиморфизма
            std::cout << "\n=== ТЕСТ ПОЛИМОРФИЗМА ===" << std::endl;
            Computer *testDevices[] = {
                new Computer("Basic PC", "Intel Celeron", 4),
                new StationaryMachine("Gaming PC", "Intel i7", 16, 4),
                new MonoBLock("iMac", "Apple M1", 8, 0, 24, false),
                new PortableMachine("Surface", "Intel i5", 8, 4000, 13),
                new Laptop("MacBook", "Apple M2", 16, 5000, 14, true),
                new Tablet("iPad", "Apple A15", 4, 6000, 11, "iPadOS")};

            for (int i = 0; i < 6; i++)
            {
                std::cout << "\n--- Тип " << (i + 1) << " ---" << std::endl;
                testDevices[i]->print(); // Полиморфный вызов!
                delete testDevices[i];
            }
            break;
        }

        case 9:
        {
            std::cout << "Выход из программы..." << std::endl;
            break;
        }

        default:
        {
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }
        }

    } while (choice != 9);

    // Очистка памяти
    for (int i = 0; i < deviceCount; i++)
    {
        delete devices[i];
    }
}
int againProg()
{
    int again;
    std::cout << "\nСнова? \033[32mДа - 1\033[0m. \033[31mНет - 0 \033[0m:\t";
    while (1)
    {
        std::cin >> again;
        if ((again != 0 && again != 1))
        {
            std::cout << "\033[31mОшибка. Переход к завершению...\033[0m";
            rewind(stdin);
            again = 0;
            return again;
        }
        else
            break;
    }
    return again;
}