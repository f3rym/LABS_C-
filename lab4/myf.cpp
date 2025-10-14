#include "header.h"
#include "./header/laptop.h"
#include "./header/mono.h"
#include "./header/tablet.h"
#include "./header/listNode.h"

void waitForAnyKey()
{
    std::cout << "\nНажмите любую клавишу для продолжения...";
    _getch();
    system("cls");
}

void editMonoBlock(MonoBlock &mono)
{
    int choice;
    char buffer[MAX_STR];
    int intValue;
    bool boolValue;

    do
    {
        std::cout << "\n=== Редактирование моноблока ===" << std::endl;
        std::cout << "1. Изменить название (" << mono.getName() << ")" << std::endl;
        std::cout << "2. Изменить процессор (" << mono.getProcessor() << ")" << std::endl;
        std::cout << "3. Изменить RAM (" << mono.getRam() << " GB)" << std::endl;
        std::cout << "4. Изменить PCI слоты (" << mono.getPCISlots() << ")" << std::endl;
        std::cout << "5. Изменить размер дисплея (" << mono.getSizeDisplay() << "\")" << std::endl;
        std::cout << "6. Изменить сенсорный экран (" << (mono.getTouchScreen() ? "Да" : "Нет") << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новое название: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            mono.setName(buffer);
            std::cout << "Название изменено!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый процессор: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            mono.setProcessor(buffer);
            std::cout << "Процессор изменен!" << std::endl;
            break;
        case 3:
            std::cout << "Введите новый объем RAM (GB): ";
            std::cin >> intValue;
            mono.setRam(intValue);
            std::cout << "RAM изменен!" << std::endl;
            break;
        case 4:
            std::cout << "Введите количество PCI слотов: ";
            std::cin >> intValue;
            mono.setPCISlots(intValue);
            std::cout << "PCI слоты изменены!" << std::endl;
            break;
        case 5:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            std::cin >> intValue;
            mono.setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 6:
            std::cout << "Сенсорный экран (1 - Да, 0 - Нет): ";
            std::cin >> boolValue;
            mono.setTouchScreen(boolValue);
            std::cout << "Параметр сенсорного экрана изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void editLaptop(Laptop &laptop)
{
    int choice;
    char buffer[MAX_STR];
    int intValue;
    bool boolValue;

    do
    {
        std::cout << "\n=== Редактирование ноутбука ===" << std::endl;
        std::cout << "1. Изменить название (" << laptop.getName() << ")" << std::endl;
        std::cout << "2. Изменить процессор (" << laptop.getProcessor() << ")" << std::endl;
        std::cout << "3. Изменить RAM (" << laptop.getRam() << " GB)" << std::endl;
        std::cout << "4. Изменить емкость батареи (" << laptop.getBatteryHealth() << " mAh)" << std::endl;
        std::cout << "5. Изменить размер дисплея (" << laptop.getSizeDisplay() << "\")" << std::endl;
        std::cout << "6. Изменить подсветку клавиатуры (" << (laptop.getHasBacklitKeyboard() ? "Да" : "Нет") << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новое название: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            laptop.setName(buffer);
            std::cout << "Название изменено!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый процессор: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            laptop.setProcessor(buffer);
            std::cout << "Процессор изменен!" << std::endl;
            break;
        case 3:
            std::cout << "Введите новый объем RAM (GB): ";
            std::cin >> intValue;
            laptop.setRam(intValue);
            std::cout << "RAM изменен!" << std::endl;
            break;
        case 4:
            std::cout << "Введите новую емкость батареи (mAh): ";
            std::cin >> intValue;
            laptop.setBatteryHealth(intValue);
            std::cout << "Емкость батареи изменена!" << std::endl;
            break;
        case 5:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            std::cin >> intValue;
            laptop.setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 6:
            std::cout << "Подсветка клавиатуры (1 - Да, 0 - Нет): ";
            std::cin >> boolValue;
            laptop.setHasBacklitKeyboard(boolValue);
            std::cout << "Параметр подсветки изменен!" << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void editTablet(Tablet &tablet)
{
    int choice;
    char buffer[MAX_STR];
    int intValue;

    do
    {
        std::cout << "\n=== Редактирование планшета ===" << std::endl;
        std::cout << "1. Изменить название (" << tablet.getName() << ")" << std::endl;
        std::cout << "2. Изменить процессор (" << tablet.getProcessor() << ")" << std::endl;
        std::cout << "3. Изменить RAM (" << tablet.getRam() << " GB)" << std::endl;
        std::cout << "4. Изменить емкость батареи (" << tablet.getBatteryHealth() << " mAh)" << std::endl;
        std::cout << "5. Изменить размер дисплея (" << tablet.getSizeDisplay() << "\")" << std::endl;
        std::cout << "6. Изменить операционную систему (" << tablet.getOS() << ")" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "Выберите параметр для редактирования: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Введите новое название: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            tablet.setName(buffer);
            std::cout << "Название изменено!" << std::endl;
            break;
        case 2:
            std::cout << "Введите новый процессор: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            tablet.setProcessor(buffer);
            std::cout << "Процессор изменен!" << std::endl;
            break;
        case 3:
            std::cout << "Введите новый объем RAM (GB): ";
            std::cin >> intValue;
            tablet.setRam(intValue);
            std::cout << "RAM изменен!" << std::endl;
            break;
        case 4:
            std::cout << "Введите новую емкость батареи (mAh): ";
            std::cin >> intValue;
            tablet.setBatteryHealth(intValue);
            std::cout << "Емкость батареи изменена!" << std::endl;
            break;
        case 5:
            std::cout << "Введите новый размер дисплея (дюймы): ";
            std::cin >> intValue;
            tablet.setSizeDisplay(intValue);
            std::cout << "Размер дисплея изменен!" << std::endl;
            break;
        case 6:
            std::cout << "Введите новую операционную систему: ";
            std::cin.ignore();
            std::cin.getline(buffer, MAX_STR);
            tablet.setOS(buffer);
            std::cout << "Операционная система изменена!" << std::endl;
            break;
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
    LinkedList<MonoBlock> monoblocks;
    int choice;
    do
    {
        std::cout << "Работа с моноблоками" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Добавить моноблок" << std::endl;
        std::cout << "2. Показать все моноблоки" << std::endl;
        std::cout << "3. Редактирование параметров" << std::endl;
        std::cout << "4. Удалить моноблок" << std::endl;
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
            monoblocks.getHead()->data.info();
            std::cout << std::endl
                      << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            Node<MonoBlock> *curr = monoblocks.getHead();
            for (int i = 0; i < monoblocks.getSize(); i++)
            {
                std::cout<< std::setw(8) << i + 1;
                std::cout << curr->data << std::endl;
                curr = curr->next;
            }
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
                editMonoBlock(monoblocks[index - 1]);
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
                monoblocks.removeIndex(index - 1);
                std::cout << "Моноблок удален!" << std::endl;
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

void lap_menu()
{
    system("cls");
    LinkedList<Laptop> lap;
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
            if (lap.getSize() < MAX_CMP)
            {
                Laptop lp;
                std::cin >> lp;
                lap.addToEnd(lp);
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
            if (lap.getSize() == 0)
            {
                std::cout << "Нет ноутбуков в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            lap.getHead()->data.info();
            std::cout << std::endl;
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            Node<Laptop>* cur = lap.getHead(); 
            for (int i = 0; i < lap.getSize(); i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << cur->data << std::endl;
                cur = cur->next;
            }
            waitForAnyKey();
            break;
        }
        case 3:
        {
            int index;
            std::cout << "Введите номер ноутбука для удаления (1-" << lap.getSize() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= lap.getSize())
            {
                lap.removeIndex(index - 1);
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
            if (lap.getSize() == 0)
            {
                std::cout << "Нет ноутбуков для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер ноутбука для редактирования (1-" << lap.getSize() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= lap.getSize())
            {
                editLaptop(lap[index - 1]);
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

void tab_menu()
{
    system("cls");
    LinkedList<Tablet> tab;    
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
            if (tab.getSize() < MAX_CMP)
            {
                Tablet tablet;
                std::cin >> tablet;
                tab.addToEnd(tablet);
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
            if (tab.getSize() == 0)
            {
                std::cout << "Нет планшетов в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            tab.getHead()->data.info();
            std::cout << std::endl;
            std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
            Node<Tablet>* curr  = tab.getHead();
            for (int i = 0; i < tab.getSize(); i++)
            {
                std::cout << std::setw(8) << i + 1;
                std::cout << curr->data << std::endl;
                curr = curr->next;
            }

            waitForAnyKey();
            break;
        }
        case 3:
        {
            if (tab.getSize() == 0)
            {
                std::cout << "Нет планшетов для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер планшета для редактирования (1-" << tab.getSize() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= tab.getSize())
            {
                editTablet(tab[index - 1]);
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
            std::cout << "Введите номер планшета для удаления (1-" << tab.getSize() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= tab.getSize())
            {
                tab.removeIndex(index - 1);
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