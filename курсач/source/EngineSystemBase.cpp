#include "../header.h"
#include "../header/EngineSystem.h"
#include "../header/listNode.h"
#include "../header/Users/User.h"

int User::nextId = 1;


void EngineSystemBase::load()
{
    users = loadUsersFromFile();
}
bool EngineSystemBase::addUser()
{
    std::cout << "Выберите тип пользователя:\n";
    std::cout << "1 - Зарегистрированный пользователь\n";
    std::cout << "2 - Администратор\n";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
    {
        RegUser regUs;
        std::cin >> regUs;

        users.push_back(regUs);
        saveUserToFile("user ", &regUs);
        break;
    }
    case 2:
    {
        Admin admin;
        std::cin >> admin;
        users.push_back(admin);
        saveUserToFile("admin", &admin);
        break;
    }
    default:
        std::cout << "Неверный выбор!\n";
        return false;
    }
    return true;
}

User EngineSystemBase::login()
{
    while (true)
    {
        std::cout << "1 - Войти" << std::endl;
        std::cout << "2 - Зарегистрироваться" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {

            char name[MAX_STR], password[MAX_STR];
            bool find = false;
            std::cout << "Введите ваше имя: ";
            std::cin >> name;
            std::cout << "Введите пароль: ";
            std::cin >> password;
            for (auto user : users)
            {
                if (strcmp(user.getName(), name) == 0)
                {
                    find = true;
                    if (user.checkPassword(password))
                    {
                        std::cout << "Успешный вход! Привет, " << user.getName() << "!" << std::endl;
                        return user;
                    }
                    else
                        std::cout << "Неверный пароль." << std::endl;
                }
            }
            if (!find)
                std::cout << "⚠ Пользователь не найден." << std::endl;
        }
        break;
        case 2:
            addUser();
            return users.back();
        default:
            break;
        }
    }
}

void EngineSystemBase::menuUser(User &us)
{
    int choice = 0;
    do
    {
        system("cls");
        std::cout << "=== МЕНЮ ===================" << std::endl;
        std::cout << "1. 📋 Мой аккаунт" << std::endl;
        std::cout << "2. 🔍 Поиск недвижимости" << std::endl;
        std::cout << "3. 📊 Моя недвижимость" << std::endl;
        std::cout << "4. 🏢 Управление недвижимостью" << std::endl;
        std::cout << "0. 🚪 Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "\n=== ИНФОРМАЦИЯ ОБ АККАУНТЕ ===" << std::endl;
            std::cout << "Имя: " << us.getName() << std::endl;
            std::cout << "ID: " << us.getId() << std::endl;
            std::cout << "Тип: " << (dynamic_cast<Admin *>(&us) ? "Администратор" : "Пользователь") << std::endl;
            waitForAnyKey();
            break;
        }
        case 2:
            break;
        case 3:
            showMyProperties(us);
            waitForAnyKey();
            break;
        case 4:
            menu(us); 
            break;
        case 0:
            std::cout << "Выход из панели пользователя..." << std::endl;
            waitForAnyKey();
            break;
        default:
            std::cout << "❌ Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
}

void EngineSystemBase::showMyProperties(User &us)
{
    std::cout << "\n=== МОЯ НЕДВИЖИМОСТЬ ===" << std::endl;
    std::cout << "Владелец: " << us.getName() << " (ID: " << us.getId() << ")" << std::endl;

    int totalProperties = 0;

    totalProperties += EngineSystem<Apartment>().showPropertiesByOwnerId("files/apartments.txt", "Квартиры", us.getId());
    totalProperties += EngineSystem<House>().showPropertiesByOwnerId("files/houses.txt", "Дома", us.getId());
    totalProperties += EngineSystem<Land>().showPropertiesByOwnerId("files/lands.txt", "Земельные участки", us.getId());
    totalProperties += EngineSystem<Office>().showPropertiesByOwnerId("files/offices.txt", "Офисы", us.getId());
    totalProperties += EngineSystem<Storage>().showPropertiesByOwnerId("files/storages.txt", "Склады", us.getId());
    totalProperties += EngineSystem<Garage>().showPropertiesByOwnerId("files/garages.txt", "Гаражи", us.getId());

    if (totalProperties > 0)
    {
        std::cout << "\n=================================" << std::endl;
        std::cout << "ИТОГО: " << totalProperties << " объектов недвижимости" << std::endl;
        std::cout << "=================================" << std::endl;
    }
    else
    {
        std::cout << "\n🚫 У вас пока нет недвижимости." << std::endl;
        std::cout << "💡 Вы можете добавить недвижимость через меню 'Добавить недвижимость'" << std::endl;
    }
}

void EngineSystemBase::menu(User &us)
{
    char filename[MAX_STR];
    int choice = 0;
    do
    {
        system("cls");
        std::cout << "--------------------------------" << std::endl;
        std::cout << "1. Работа с апартаментами" << std::endl;
        std::cout << "2. Работа с домами" << std::endl;
        std::cout << "3. Работа с земельными участками" << std::endl;
        std::cout << "4. Работа с офисами" << std::endl;
        std::cout << "5. Работа со складами" << std::endl;
        std::cout << "6. Работа с гаражами" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            strcpy_s(filename,"files/apartments.txt");
            EngineSystem<Apartment> obj;
            obj.load(filename);
            obj.fun(us, filename);
            break;
        }
        case 2:
        {
            strcpy_s(filename, "files/houses.txt");
            EngineSystem<House> obj;
            obj.load(filename);
            obj.fun(us, filename);
            break;
        }
        case 3:
        {
            strcpy_s(filename, "files/lands.txt");
            EngineSystem<Land> obj;
            obj.load(filename);
            obj.fun(us, filename);
            break;
        }
        case 4:
        {
            strcpy_s(filename, "files/offices.txt");
            EngineSystem<Office> obj;
            obj.load(filename);
            obj.fun(us, filename);
            break;
        }
        case 5:
        {
            strcpy_s(filename, "files/storages.txt");
            EngineSystem<Storage> obj;
            obj.load(filename);
            obj.fun(us, filename);
            break;
        }
        case 6:
        {
            strcpy_s(filename, "files/garages.txt");
            EngineSystem<Garage> obj;
            obj.load(filename);
            obj.fun(us, filename);
            break;
        }
        default:
            break;
        }
    } while (choice != 0);
}

