#include "../header.h"
#include "../header/interface.h"

template <class T>
void Interface<T>::menu()
{
    int choice;

    do
    {
        Interface<MonoBlock> monoObj;
        Interface<Laptop> laptopObj;
        Interface<Tablet> tabletObj;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Работа с моноблоками" << std::endl;
        std::cout << "2. Работа с ноутбуками" << std::endl;
        std::cout << "3. Работа с планшетами" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            // Interface<MonoBlock> obj1;
            monoObj.fun();
            waitForAnyKey();
            break;
        case 2:
            // Interface<Laptop> obj2;
            laptopObj.fun();
            waitForAnyKey();
            break;
        case 3:
            // Interface<Tablet> obj3;
            tabletObj.fun();
            waitForAnyKey();
            break;
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 0);
}

template <class T>
void Interface<T>::editComputingMachine(T &device)
{
    device.setMenu();
}

template <class T>
void Interface<T>::sortByParam()
{
    LinkedList<ComputingMachine *> ptrList;
    for (int i = 0; i < computer.getSize(); ++i)
    {
        ptrList.addToEnd(&computer[i]); 
    }
    computer[0].sortList(ptrList);
    LinkedList<T> sortedList;
    for (int i = 0; i < ptrList.getSize(); ++i)
        sortedList.addToEnd(*dynamic_cast<T *>(ptrList[i]));
    computer = sortedList;
    std::cout << "Машины отсортированы!" << std::endl;
}

template <class T>
void Interface<T>::fun()
{
    system("cls");
    int choice;
    do
    {
        std::cout << "1. Добавить машину" << std::endl;
        std::cout << "2. Показать все машины" << std::endl;
        std::cout << "3. Редактирование параметров" << std::endl;
        std::cout << "4. Удалить машину" << std::endl;
        std::cout << "5. Сортировка" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            T cm;
            std::cin >> cm;
            computer.addToEnd(cm);
            std::cout << "Компьютер добавлен!" << std::endl;
            waitForAnyKey();
            break;
        }
        case 2:
        {
            if (computer.getSize() == 0)
            {
                std::cout << "Нет машин в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            computer[0].info();
            std::cout << std::endl
                      << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << computer;
            waitForAnyKey();
            break;
        }
        case 3:
        {
            if (computer.getSize() == 0)
            {
                std::cout << "Нет машин для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер моноблока для редактирования (1-" << computer.getSize() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= computer.getSize())
            {
                editComputingMachine(computer[index - 1]);
                std::cout << "Машина отредактирован!" << std::endl;
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
            std::cout << "Введите номер машины для удаления (1-" << computer.getSize() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= computer.getSize())
            {
                computer.removeByIndex(index - 1);
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
            sortByParam();
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
