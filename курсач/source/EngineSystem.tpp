#include "../header.h"
#include "../header/EngineSystem.h"
#include "../header/listNode.h"
#include "../header/Users/User.h"

inline void waitForAnyKey()
{
    std::cout << "\nНажмите Enter для продолжения...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

template <class T>
void EngineSystem<T>::fun(User &us, char *filename)
{
    int choice = 0;
    do
    {
        system("cls");
        std::cout << "------------------------" << std::endl;
        std::cout << "1. Добавить "<< std::endl;
        std::cout << "2. Показать все "<< std::endl;
        std::cout << "4. Найти по параметрам"<< std::endl;
        std::cout << "0. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            T ap;
            std::cin >> ap;
            property.addToEnd(ap);
            ap.setOwnerId(us.getId());
            ap.writeToFile(filename);
            std::cout << "Недвижимость успешно добавлена!" << std::endl;
            waitForAnyKey();
            break;
        }

        case 2:
        {
            if (property.isEmpty())
            {
                std::cout << "⚠️  Список  пуст.\n";
            }
            else
            {
                property.begin()->data.info();
                for (auto node = property.begin(); node != nullptr; node = node->next)
                {
                    std::cout << node->data << "\n";
                }
            }
            waitForAnyKey();
            break;
        }
        case 0:
            std::cout << "👋 Выход из меню недвижимости.\n";
            waitForAnyKey();
            break;

        default:
            std::cout << "❌ Неверный пункт меню.\n";
        }

    } while (choice != 0);
}

template <class T>
void EngineSystem<T>::load(const char *filename)
{
    T value;
    property = value.readFromFile(filename);
}

template <class T>
int EngineSystem<T>::showPropertiesByOwnerId(const char *filename, const char *typeName, int ownerId)
{
    EngineSystem<T> obj;
    obj.load(filename);
    property = obj.getProperty();

    int count = 0;

    if (!property.isEmpty())
    {
        bool found = false;

        for (auto node = property.begin(); node != nullptr; node = node->next)
        {
            if (node->data.getOwnerId() == ownerId)
            {
                if (!found)
                {
                    std::cout << "\n--- " << typeName << " ---" << std::endl;
                    if (property.begin() != nullptr)
                    {
                        property.begin()->data.info();
                    }
                    found = true;
                }
                std::cout << node->data << std::endl;
                count++;
            }
        }

        if (count > 0)
        {
            std::cout << "Всего: " << count << " объектов" << std::endl;
        }
    }

    return count;
}
