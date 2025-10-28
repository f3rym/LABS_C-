#include "../header.h"
#include "../header/interface.h"

void Interface::editComputingMachine(ComputingMachine &device)
{
    device.setMenu();
}

void Interface::sortMonoblocksByRAM()
{
    if (monoblocks.getSize() == 0)
    {
        std::cout << "Нет моноблоков для сортировки!" << std::endl;
        return;
    }

    for (int i = 0; i < monoblocks.getSize() - 1; i++)
    {
        for (int j = 0; j < monoblocks.getSize() - i - 1; j++)
        {
            if (monoblocks[j].getRam() < monoblocks[j + 1].getRam())
            {
                MonoBlock temp = monoblocks[j];
                monoblocks[j] = monoblocks[j + 1];
                monoblocks[j + 1] = temp;
            }
        }
    }
    std::cout << "Моноблоки отсортированы по RAM (по убыванию)!" << std::endl;
}

void Interface::mn_menu()
{
    system("cls");
    int choice;
    do
    {
        std::cout << "Работа с моноблоками" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Добавить моноблок" << std::endl;
        std::cout << "2. Показать все моноблоки" << std::endl;
        std::cout << "3. Редактирование параметров" << std::endl;
        std::cout << "4. Удалить моноблок" << std::endl;
        std::cout << "5. Сортировка" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;
        

        switch (choice)
        {
        case 1:
        {
            if (monoblocks.getSize() < MAX_CMP)
            {
                MonoBlock mn;
                std::cin >> mn;
                monoblocks.addToEnd(mn);
                std::cout << "Моноблок добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит моноблоков!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 2:
        {
            if (monoblocks.getSize() == 0)
            {
                std::cout << "Нет моноблоков в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            monoblocks[0].info();
            std::cout << std::endl
                      << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << monoblocks;
            waitForAnyKey();
            break;
        }
        case 3:
        {
            if (monoblocks.getSize() == 0)
            {
                std::cout << "Нет моноблоков для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер моноблока для редактирования (1-" << monoblocks.getSize() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= monoblocks.getSize())
            {
                editComputingMachine(monoblocks[index - 1]);
                std::cout << "Моноблок отредактирован!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Введите номер моноблока для удаления (1-" << monoblocks.getSize() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= monoblocks.getSize())
            {
                monoblocks.removeByIndex(index - 1);
                std::cout << "Моноблок удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 5:
        {
            sortMonoblocksByRAM();
            waitForAnyKey();
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            waitForAnyKey();
        }
    } while (choice != 0);
}

void Interface::laptops_menu()
{
    system("cls");
    int choice;
    do
    {
        std::cout << "Работа с ноутбуками" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Добавить ноутбук" << std::endl;
        std::cout << "2. Показать все ноутбуки" << std::endl;
        std::cout << "3. Удалить ноутбук" << std::endl;
        std::cout << "4. Редактирование параметров" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (laptops.getSize() < MAX_CMP)
            {
                Laptop lp;
                std::cin >> lp;
                laptops.addToEnd(lp);
                std::cout << "Ноутбук добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит ноутбуков!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 2:
        {
            if (laptops.getSize() == 0)
            {
                std::cout << "Нет ноутбуков в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            laptops[0].info();
            std::cout << std::endl;
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << laptops;
            waitForAnyKey();
            break;
        }
        case 3:
        {
            int index;
            std::cout << "Введите номер ноутбука для удаления (1-" << laptops.getSize() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= laptops.getSize())
            {
                laptops.removeByIndex(index - 1);
                std::cout << "Ноутбук удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 4:
        {
            if (laptops.getSize() == 0)
            {
                std::cout << "Нет ноутбуков для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер ноутбука для редактирования (1-" << laptops.getSize() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= laptops.getSize())
            {
                editComputingMachine(laptops[index - 1]);
                std::cout << "Ноутбук отредактирован!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            waitForAnyKey();
        }
    } while (choice != 0);
}

void Interface::tablets_menu()
{
    system("cls");
    int choice;
    do
    {
        std::cout << "Работа с планшетами" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Добавить планшет" << std::endl;
        std::cout << "2. Показать все планшеты" << std::endl;
        std::cout << "3. Редактирование параметров" << std::endl;
        std::cout << "4. Удалить планшет" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (tablets.getSize() < MAX_CMP)
            {
                Tablet tempTablet;
                std::cin >> tempTablet;
                tablets.addToEnd(tempTablet);
                std::cout << "Планшет добавлен!" << std::endl;
            }
            else
            {
                std::cout << "Достигнут лимит планшетов!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 2:
        {
            if (tablets.getSize() == 0)
            {
                std::cout << "Нет планшетов в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            tablets[0].info();
            std::cout << std::endl;
            std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << tablets;
            waitForAnyKey();
            break;
        }
        case 3:
        {
            if (tablets.getSize() == 0)
            {
                std::cout << "Нет планшетов для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер планшета для редактирования (1-" << tablets.getSize() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= tablets.getSize())
            {
                editComputingMachine(tablets[index - 1]);
                std::cout << "Планшет отредактирован!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 4:
        {
            int index;
            std::cout << "Введите номер планшета для удаления (1-" << tablets.getSize() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= tablets.getSize())
            {
                tablets.removeByIndex(index - 1);
                std::cout << "Планшет удален!" << std::endl;
            }
            else
            {
                std::cout << "Неверный номер!" << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            waitForAnyKey();
        }
    } while (choice != 0);
}
