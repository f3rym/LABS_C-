#include "../header.h"
#include "../header/interface.h"
#include "../header/ExpInput.h"
#include "../header/file/fileTxt.h"
#include "../header/file/fileBin.h"

template <class T>
void Interface<T>::menu()
{
    int choice;
    int var;
    do
    {
        ExpInput exp;
        Interface<MonoBlock> monoObj;
        Interface<Laptop> laptopObj;
        Interface<Tablet> tabletObj;
        std::cout << "=========================================" << std::endl;
        std::cout << "1. Работа с моноблоками" << std::endl;
        std::cout << "2. Работа с ноутбуками" << std::endl;
        std::cout << "3. Работа с планшетами" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "=========================================" << std::endl;
        choice = exp.isNumber(std::cin);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            // Interface<MonoBlock> obj1;
            std::cout << "Работа с контейнером stl vector?";
            var = exp.isBool(std::cin);
            if (var)
                monoObj.fun1();
            else
                monoObj.fun();
            waitForAnyKey();
            break;
        case 2:
            // Interface<Laptop> obj2;
            
            std::cout << "Работа с контейнером stl vector?";
            var = exp.isBool(std::cin);
            if (var)
                laptopObj.fun1();
            else
                laptopObj.fun();
            waitForAnyKey();
            break;
        case 3:
            // Interface<Tablet> obj3;
            std::cout << "Работа с контейнером stl vector?";
            var = exp.isBool(std::cin);
            if (var)
                tabletObj.fun1();
            else
                tabletObj.fun();
            waitForAnyKey();
            break;
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 0);
}

// template <class T>
// void Interface<T>::sortByParam()
// {
//     LinkedList<ComputingMachine *> ptrList;
//     for (int i = 0; i < computer.getSize(); ++i)
//     {
//         ptrList.addToEnd(&computer[i]);
//     }
//     computer[0].sortList(ptrList);
//     LinkedList<T> sortedList;
//     for (int i = 0; i < ptrList.getSize(); ++i)
//         sortedList.addToEnd(*dynamic_cast<T *>(ptrList[i]));
//     computer = sortedList;
//     std::cout << "Машины отсортированы!" << std::endl;
// }

template <class T>
void Interface<T>::sortByParam1()
{
    Algorithm<decltype(computerSTL.begin()), T>::sortByParam1(
        computerSTL.begin(),
        computerSTL.end());
}

template <class T>
void Interface<T>::editComputingMachine(T &device)
{
    device.setMenu();
}

template <class T>
void Interface<T>::fun()
{
    ExpInput exp;
    system("cls");
    int choice;
    do
    {
        std::cout << "1. Добавить машину" << std::endl;
        std::cout << "2. Показать все машины" << std::endl;
        std::cout << "3. Редактирование параметров" << std::endl;
        std::cout << "4. Удалить машину" << std::endl;
        std::cout << "5. Сортировка" << std::endl;
        std::cout << "6. Сохранить в текстовый файл" << std::endl;
        std::cout << "7. Загрузить из текстового файла" << std::endl;
        std::cout << "8. Сохранить в бинарный файл" << std::endl;
        std::cout << "9. Загрузить из бинарного файла" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        choice = exp.isNumber(std::cin);
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
                std::cout << "Машина удалена!" << std::endl;
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
            waitForAnyKey();
            break;
        }
        case 6:
        {
            const char *files[] = {"files/monoblocks.txt", "files/laptops.txt", "files/tablets.txt"};
            std::string filename;
            if (std::is_same<T, MonoBlock>::value)
                filename = files[0];
            else if (std::is_same<T, Laptop>::value)
                filename = files[1];
            else if (std::is_same<T, Tablet>::value)
                filename = files[2];

            FileTxt<T> file(filename);
            file.writeLinkedList(computer);

            waitForAnyKey();
            break;
        }
        case 7:
        {
            const char *files[] = {"files/monoblocks.txt", "files/laptops.txt", "files/tablets.txt"};
            std::string defaultFilename;
            if (std::is_same<T, MonoBlock>::value)
                defaultFilename = files[0];
            else if (std::is_same<T, Laptop>::value)
                defaultFilename = files[1];
            else if (std::is_same<T, Tablet>::value)
                defaultFilename = files[2];
            FileTxt<T> file(defaultFilename);
            file.readLinkedList(computer);

            waitForAnyKey();
            break;
        }
        case 8:
        {
            const char *files[] = {"files/monoblocks", "files/laptops", "files/tablets"};
            std::string filename;
            if (std::is_same<T, MonoBlock>::value)
                filename = files[0];
            else if (std::is_same<T, Laptop>::value)
                filename = files[1];
            else if (std::is_same<T, Tablet>::value)
                filename = files[2];

            FileBin<T> file(filename);
            file.writeLinkedList(computer);

            waitForAnyKey();
            break;
        }
        case 9:
        {
            const char *files[] = {"files/monoblocks", "files/laptops", "files/tablets"};
            std::string defaultFilename;
            if (std::is_same<T, MonoBlock>::value)
                defaultFilename = files[0];
            else if (std::is_same<T, Laptop>::value)
                defaultFilename = files[1];
            else if (std::is_same<T, Tablet>::value)
                defaultFilename = files[2];
            FileBin<T> file(defaultFilename);
            file.readLinkedList(computer);

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

template <class T>
void Interface<T>::fun1()
{
    ExpInput exp;
    system("cls");
    int choice;
    do
    {
        std::cout << "1. Добавить машину" << std::endl;
        std::cout << "2. Показать все машины" << std::endl;
        std::cout << "3. Редактирование параметров" << std::endl;
        std::cout << "4. Удалить машину" << std::endl;
        std::cout << "5. Сортировка" << std::endl;
        std::cout << "6. Сохранить в текстовый файл" << std::endl;
        std::cout << "7. Загрузить из текстового файла" << std::endl;
        std::cout << "8. Сохранить в бинарный файл" << std::endl;
        std::cout << "9. Загрузить из бинарного файла" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "=========================================" << std::endl;
        choice = exp.isNumber(std::cin);
        switch (choice)
        {
        case 1:
        {
            T cm;
            std::cin >> cm;
            computerSTL.push_back(cm);
            std::cout << "Компьютер добавлен!" << std::endl;
            waitForAnyKey();
            break;
        }
        case 2:
        {
            if (computerSTL.empty())
            {
                std::cout << "Нет машин в системе!" << std::endl;
                waitForAnyKey();
                break;
            }
            computerSTL[0].info();
            std::cout << std::endl
                      << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
            for (const auto &item : computerSTL)
            {
                std::cout << item << std::endl;
            }
            waitForAnyKey();
            break;
        }
        case 3:
        {
            if (computerSTL.empty())
            {
                std::cout << "Нет машин для редактирования!" << std::endl;
                waitForAnyKey();
                break;
            }

            int index;
            std::cout << "Введите номер моноблока для редактирования (1-" << computerSTL.size() << "): ";
            std::cin >> index;

            if (index >= 1 && index <= computerSTL.size())
            {
                editComputingMachine(computerSTL[index - 1]);
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
            std::cout << "Введите номер машины для удаления (1-" << computerSTL.size() << "): ";
            std::cin >> index;
            if (index >= 1 && index <= computerSTL.size())
            {
                computerSTL.erase(computerSTL.begin() + (index - 1));
                std::cout << "Машина удалена!" << std::endl;
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
            sortByParam1();
            waitForAnyKey();
            break;
        }
        case 6:
        {
            const char *files[] = {"files/monoblocks.txt", "files/laptops.txt", "files/tablets.txt"};
            std::string filename;
            if (std::is_same<T, MonoBlock>::value)
                filename = files[0];
            else if (std::is_same<T, Laptop>::value)
                filename = files[1];
            else if (std::is_same<T, Tablet>::value)
                filename = files[2];

            FileTxt<T> file(filename);
            file.writeToSTLcontainer(computerSTL);
            waitForAnyKey();
            break;
        }
        case 7:
        {
            const char *files[] = {"files/monoblocks.txt", "files/laptops.txt", "files/tablets.txt"};
            std::string defaultFilename;
            if (std::is_same<T, MonoBlock>::value)
                defaultFilename = files[0];
            else if (std::is_same<T, Laptop>::value)
                defaultFilename = files[1];
            else if (std::is_same<T, Tablet>::value)
                defaultFilename = files[2];
            FileTxt<T> file(defaultFilename);
            file.readFromSTLcontainer(computerSTL);
            waitForAnyKey();
            break;
        }
        case 8:
        {
            const char *files[] = {"files/monoblocks", "files/laptops", "files/tablets"};
            std::string filename;
            if (std::is_same<T, MonoBlock>::value)
                filename = files[0];
            else if (std::is_same<T, Laptop>::value)
                filename = files[1];
            else if (std::is_same<T, Tablet>::value)
                filename = files[2];

            FileBin<T> file(filename);
            file.writeToSTLcontainer(computerSTL);

            waitForAnyKey();
            break;
        }
        case 9:
        {
            const char *files[] = {"files/monoblocks", "files/laptops", "files/tablets"};
            std::string defaultFilename;
            if (std::is_same<T, MonoBlock>::value)
                defaultFilename = files[0];
            else if (std::is_same<T, Laptop>::value)
                defaultFilename = files[1];
            else if (std::is_same<T, Tablet>::value)
                defaultFilename = files[2];
            FileBin<T> file(defaultFilename);
            file.readFromSTLcontainer(computerSTL);

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
