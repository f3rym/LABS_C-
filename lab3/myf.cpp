#include "header.h"
#include "./header/computer.h"
#include "./header/laptop.h"
#include "./header/mono.h"
#include "./header/portableMachine.h"
#include "./header/stationaryMachine.h"
#include "./header/tablet.h"

void comp_menu()
{
    system("cls");
    int compCount = 0;
    Computer comps[MAX_CMP];
    int choice;
    do
    {
        std::cout << "=========================================" << std::endl;
        comps[0].info();
        std::cout << std::endl
                  << "=========================================" << std::endl;
        std::cout << "1. Добавить компьютер" << std::endl;
        std::cout << "2. Показать все компьютеры" << std::endl;
        std::cout << "3. Найти компьютер по модели" << std::endl;
        std::cout << "4. Удалить компьютер" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (compCount < MAX_CMP)
            {
                std::cin >> comps[compCount];
                compCount++;
                std::cout << "Компьютер добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит компьютеров!" << std::endl;
            }
            break;
        }
        case 2:
            if (compCount == 0)
            {
                std::cout << "Нет компьютеров в системе!" << std::endl;
                return;
            }
            comps[0].info();
            std::cout << std::endl
                      << "--------------------------------------------------------" << std::endl;
            std::cout << std::left;
            std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
                      << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)" << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;

            for (int i = 0; i < compCount; i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << comps[i] << std::endl;
            }
            break;
        case 3:
        {
            char searchName[MAX_STR];
            std::cout << "Введите имя для поиска: ";
            std::cin.ignore();
            std::cin.getline(searchName, MAX_STR);

            bool found = false;
            for (int i = 0; i < compCount; i++)
            {
                if (std::strcmp(comps[i].getName(), searchName) == 0)
                {
                    std::cout << "Найден компьютер:" << std::endl;
                    comps[i].info();
                    std::cout << comps[i] << std::endl;
                    found = true;
                }
            }
            if (!found)
            {
                std::cout << "Компьютер с именем '" << searchName << "' не найден!" << std::endl;
            }
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Введите номер компьютера для удаления (1-" << compCount << "): ";
            std::cin >> index;
            if (index >= 1 && index <= compCount)
            {
                for (int i = index - 1; i < compCount - 1; i++)
                {
                    comps[i] = comps[i + 1];
                }
                compCount--;
                std::cout << "Компьютер удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void pm_menu()
{
    system("cls");
    int portableCount = 0;
    PortableMachine portables[MAX_CMP];
    int choice;
    do
    {
        std::cout << "=========================================" << std::endl;
        portables[0].info();
        std::cout << std::endl
                  << "=========================================" << std::endl;
        std::cout << "1. Добавить портативную машину" << std::endl;
        std::cout << "2. Показать все портативные машины" << std::endl;
        std::cout << "3. Удалить портативную машину" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (portableCount < MAX_CMP)
            {
                std::cin >> portables[portableCount];
                portableCount++;
                std::cout << "Портативная машина добавлена!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит портативных машин!" << std::endl;
            }
            break;
        }
        case 2:
        {
            if (portableCount == 0)
            {
                std::cout << "Нет портативных машин в системе!" << std::endl;
                break;
            }
            portables[0].info();
            std::cout << std::endl
                      << "----------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << std::left;
            std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
                      << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)"
                      << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display" << std::endl;
            std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;

            for (int i = 0; i < portableCount; i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << portables[i] << std::endl;
            }
            break;
        }
        case 3:
        {
            int index;
            std::cout << "Введите номер портативной машины для удаления (1-" << portableCount << "): ";
            std::cin >> index;
            if (index >= 1 && index <= portableCount)
            {
                for (int i = index - 1; i < portableCount - 1; i++)
                {
                    portables[i] = portables[i + 1];
                }
                portableCount--;
                std::cout << "Портативная машина удалена!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void sm_menu()
{
    system("cls");
    int stationaryCount = 0;
    StationaryMachine stationarys[MAX_CMP];
    int choice;
    do
    {
        std::cout << "=========================================" << std::endl;
        stationarys[0].info();
        std::cout << std::endl
                  << "=========================================" << std::endl;
        std::cout << "1. Добавить стационарную машину" << std::endl;
        std::cout << "2. Показать все стационарные машины" << std::endl;
        std::cout << "3. Найти по количеству PCI слотов" << std::endl;
        std::cout << "4. Удалить стационарную машину" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (stationaryCount < MAX_CMP)
            {
                std::cin >> stationarys[stationaryCount];
                stationaryCount++;
                std::cout << "Стационарная машина добавлена!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит стационарных машин!" << std::endl;
            }
            break;
        }
        case 2:
        {
            if (stationaryCount == 0)
            {
                std::cout << "Нет стационарных машин в системе!" << std::endl;
                break;
            }
            stationarys[0].info();
            std::cout << std::endl
                      << "-----------------------------------------------------------------------------" << std::endl;
            std::cout << std::left;
            std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
                      << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)"
                      << std::setw(20) << "PCI Slots" << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < stationaryCount; i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << stationarys[i] << std::endl;
            }
            break;
        }
        case 3:
        {
            int minSlots;
            std::cout << "Введите минимальное количество PCI слотов: ";
            std::cin >> minSlots;
            bool found = false;
            for (int i = 0; i < stationaryCount; i++)
            {
                if (stationarys[i].getPCISlots() >= minSlots)
                {
                    if (!found)
                    {
                        std::cout << "Стационарные машины с PCI слотами >= " << minSlots << ":" << std::endl;
                        found = true;
                    }
                    stationarys[i].info();
                    std::cout << stationarys[i] << std::endl;
                }
            }
            if (!found)
            {
                std::cout << "Не найдено стационарных машин с PCI слотами >= " << minSlots << std::endl;
            }
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Введите номер стационарной машины для удаления (1-" << stationaryCount << "): ";
            std::cin >> index;
            if (index >= 1 && index <= stationaryCount)
            {
                for (int i = index - 1; i < stationaryCount - 1; i++)
                {
                    stationarys[i] = stationarys[i + 1];
                }
                stationaryCount--;
                std::cout << "Стационарная машина удалена!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void mn_menu()
{
    system("cls");
    int monoCount = 0;
    MonoBlock monoblocks[MAX_CMP];
    int choice;
    do
    {
        std::cout << "=========================================" << std::endl;
        monoblocks[0].info();
        std::cout << std::endl
                  << "=========================================" << std::endl;
        std::cout << "1. Добавить моноблок" << std::endl;
        std::cout << "2. Показать все моноблоки" << std::endl;
        std::cout << "3. Найти по размеру дисплея" << std::endl;
        std::cout << "4. Удалить моноблок" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (monoCount < MAX_CMP)
            {
                std::cin >> monoblocks[monoCount];
                monoCount++;
                std::cout << "Моноблок добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит моноблоков!" << std::endl;
            }
            break;
        }
        case 2:
        {
            if (monoCount == 0)
            {
                std::cout << "Нет моноблоков в системе!" << std::endl;
                break;
            }
            monoblocks[0].info();
            std::cout << std::endl
                      << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << std::left;
            std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
                      << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)"
                      << std::setw(20) << "PCI Slot" << std::setw(20) << "Size Display"
                      << std::setw(20) << "Touchscreen" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < monoCount; i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << monoblocks[i] << std::endl;
            }
            break;
        }
        case 3:
        {
            int minSize;
            std::cout << "Введите минимальный размер дисплея: ";
            std::cin >> minSize;
            bool found = false;
            for (int i = 0; i < monoCount; i++)
            {
                if (monoblocks[i].getSizeDisplay() >= minSize)
                {
                    if (!found)
                    {
                        std::cout << "Моноблоки с размером дисплея >= " << minSize << " дюймов:" << std::endl;
                        found = true;
                    }
                    monoblocks[i].info();
                    std::cout << monoblocks[i] << std::endl;
                }
            }
            if (!found)
            {
                std::cout << "Не найдено моноблоков с размером дисплея >= " << minSize << " дюймов" << std::endl;
            }
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Введите номер моноблока для удаления (1-" << monoCount << "): ";
            std::cin >> index;
            if (index >= 1 && index <= monoCount)
            {
                for (int i = index - 1; i < monoCount - 1; i++)
                {
                    monoblocks[i] = monoblocks[i + 1];
                }
                monoCount--;
                std::cout << "Моноблок удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void lap_menu()
{
    system("cls");
    int laptopCount = 0;
    Laptop laptops[MAX_CMP];
    int choice;
    do
    {
        std::cout << "=========================================" << std::endl;
        laptops[0].info();
        std::cout << std::endl
                  << "=========================================" << std::endl;
        std::cout << "1. Добавить ноутбук" << std::endl;
        std::cout << "2. Показать все ноутбуки" << std::endl;
        std::cout << "3. Удалить ноутбук" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (laptopCount < MAX_CMP)
            {
                std::cin >> laptops[laptopCount];
                laptopCount++;
                std::cout << "Ноутбук добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит ноутбуков!" << std::endl;
            }
            break;
        }
        case 2:
        {
            if (laptopCount == 0)
            {
                std::cout << "Нет ноутбуков в системе!" << std::endl;
                break;
            }
            laptops[0].info();
            std::cout << std::endl
                      << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

            std::cout << std::left;
            std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
                      << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)"
                      << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display"
                      << std::setw(20) << "Has Backlit" << std::endl;
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < laptopCount; i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << laptops[i] << std::endl;
            }
            break;
        }
        case 3:
        {
            int index;
            std::cout << "Введите номер ноутбука для удаления (1-" << laptopCount << "): ";
            std::cin >> index;
            if (index >= 1 && index <= laptopCount)
            {
                for (int i = index - 1; i < laptopCount - 1; i++)
                {
                    laptops[i] = laptops[i + 1];
                }
                laptopCount--;
                std::cout << "Ноутбук удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void tab_menu()
{
    system("cls");
    int tabletCount = 0;
    Tablet tablets[MAX_CMP];
    int choice;
    do
    {
        std::cout << "=========================================" << std::endl;
        tablets[0].info();
        std::cout << std::endl
                  << "=========================================" << std::endl;
        std::cout << "1. Добавить планшет" << std::endl;
        std::cout << "2. Показать все планшеты" << std::endl;
        std::cout << "3. Найти по операционной системе" << std::endl;
        std::cout << "4. Удалить планшет" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (tabletCount < MAX_CMP)
            {
                std::cin >> tablets[tabletCount];
                tabletCount++;
                std::cout << "Планшет добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит планшетов!" << std::endl;
            }
            break;
        }
        case 2:
        {
            if (tabletCount == 0)
            {
                std::cout << "Нет планшетов в системе!" << std::endl;
                break;
            }
            tablets[0].info();
            std::cout << std::endl
                      << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << std::left;
            std::cout << std::setw(8) << "N" << std::setw(20) << "Model"
                      << std::setw(20) << "Processor" << std::setw(20) << "RAM(Gb)"
                      << std::setw(20) << "Battery(mAh)" << std::setw(20) << "Size Display"
                      << std::setw(20) << "OS" << std::endl;
            std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < tabletCount; i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << tablets[i] << std::endl;
            }
            break;
        }
        case 3:
        {
            char searchOS[MAX_STR];
            std::cout << "Введите ОС для поиска: ";
            std::cin.ignore();
            std::cin.getline(searchOS, MAX_STR);
            bool found = false;
            for (int i = 0; i < tabletCount; i++)
            {
                if (std::strcmp(tablets[i].getOS(), searchOS) == 0)
                {
                    if (!found)
                    {
                        std::cout << "Планшеты с ОС '" << searchOS << "':" << std::endl;
                        found = true;
                    }
                    tablets[i].info();
                    std::cout << tablets[i] << std::endl;
                }
            }
            if (!found)
            {
                std::cout << "Не найдено планшетов с ОС '" << searchOS << "'" << std::endl;
            }
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Введите номер планшета для удаления (1-" << tabletCount << "): ";
            std::cin >> index;
            if (index >= 1 && index <= tabletCount)
            {
                for (int i = index - 1; i < tabletCount - 1; i++)
                {
                    tablets[i] = tablets[i + 1];
                }
                tabletCount--;
                std::cout << "Планшет удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
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