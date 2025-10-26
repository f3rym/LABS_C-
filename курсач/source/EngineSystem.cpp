#include "../header.h"
#include "../header/EngineSystem.h"
#include "../header/listNode.h"
#include "../header/Users/User.h"
int Property::nextPropertyId = 1;
int User::nextId = 1;

void EngineSystem::load()
{
    users = loadUsersFromFile();
    property = loadPropertyFromFile();
}

bool EngineSystem::addUser()
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
        RegUser *regUs = new RegUser();
        std::cin >> *regUs;
        users.push_back(regUs);
        saveUserToFile("user ", regUs);
        break;
    }
    case 2:
    {
        Admin *admin = new Admin();
        std::cin >> *admin;
        users.push_back(admin);
        saveUserToFile("admin", admin);
        break;
    }
    default:
        std::cout << "Неверный выбор!\n";
        return false;
    }
    return true;
}

User *EngineSystem::login()
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
            if (strcmp(user->getName(), name) == 0)
            {
                find = true;
                if (user->checkPassword(password))
                {
                    std::cout << "Успешный вход! Привет, " << user->getName() << "!" << std::endl;
                    return user;
                }
                else
                    std::cout << "Неверный пароль." << std::endl;
            }
        }
        if (!find)
            std::cout << "⚠ Пользователь не найден." << std::endl;
        return nullptr;
    }
    break;
    case 2:
        addUser();
        return users.back();
    default : break;
    }
}

bool EngineSystem::addProperty(User &user)
{
    std::cout << "Выберите тип недвижимости:\n";
    std::cout << "1 - Квартира\n";
    std::cout << "2 - Частный дом\n";
    std::cout << "3 - Земельный участок\n";
    std::cout << "4 - Офис\n";
    std::cout << "5 - Склад\n";
    std::cout << "6 - Гараж\n";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
    {
        Apartment *apt = new Apartment();
        std::cin >> *apt;
        apt->setOwnerId(user.getId());
        property.addToEnd(apt);
        savePropertyToFile("apartment", apt);
        break;
    }
    case 2:
    {
        House *house = new House();
        std::cin >> *house;
        house->setOwnerId(user.getId());
        property.addToEnd(house);
        savePropertyToFile("house", house);
        break;
    }
    case 3:
    {
        Land *land = new Land;
        std::cin >> *land;
        land->setOwnerId(user.getId());
        property.addToEnd(land);
        savePropertyToFile("land", land);

        break;
    }
    case 4:
    {
        Office *office = new Office();
        std::cin >> *office;
        office->setOwnerId(user.getId());
        property.addToEnd(office);
        savePropertyToFile("office", office);

        break;
    }
    case 5:
    {
        Storage *storage = new Storage;
        std::cin >> *storage;
        storage->setOwnerId(user.getId());
        property.addToEnd(storage);
        savePropertyToFile("storage", storage);

        break;
    }
    case 6:
    {
        Garage *garage = new Garage;
        std::cin >> *garage;
        garage->setOwnerId(user.getId());
        property.addToEnd(garage);
        savePropertyToFile("garage", garage);

        break;
    }
    default:
        std::cout << "Неверный выбор!\n";
        return false;
    }
    return true;
}

void EngineSystem::findByParam(int numType)
{
    // numType: 0 - all, 1 - Apartment, 2 - Commercial, 3 - Garage, 4 - House, 5 - Land, 6 - Storage, 7 - Office

    std::cout << std::string(60, '=') << "\n";
    std::cout << " Поиск объектов недвижимости\n";
    std::cout << std::string(60, '=') << "\n\n";

    std::cout << "Выберите режим поиска (1 - обычный, 2 - расширенный). Ввод: ";
    int mode = 1;
    if (!(std::cin >> mode))
    {
        std::cin.clear();
        mode = 1;
    }
    if (mode != 2)
        mode = 1;

    std::cout << "\n(Для числовых фильтров: введи -1 чтобы пропустить фильтр)\n\n";

    std::cout << std::setw(30) << std::left << "Минимальная цена: ";
    int minPrice;
    std::cin >> minPrice;
    std::cout << std::setw(30) << std::left << "Максимальная цена: ";
    int maxPrice;
    std::cin >> maxPrice;

    std::cout << std::setw(30) << std::left << "Минимальная площадь: ";
    double minArea;
    std::cin >> minArea;
    std::cout << std::setw(30) << std::left << "Максимальная площадь: ";
    double maxArea;
    std::cin >> maxArea;

    int minRooms = -1, maxRooms = -1, minFloor = -1, maxFloor = -1;
    if (mode == 2)
    {
        std::cout << std::setw(30) << std::left << "Минимум комнат: ";
        std::cin >> minRooms;
        std::cout << std::setw(30) << std::left << "Максимум комнат: ";
        std::cin >> maxRooms;

        std::cout << std::setw(30) << std::left << "Минимальный этаж: ";
        std::cin >> minFloor;
        std::cout << std::setw(30) << std::left << "Максимальный этаж: ";
        std::cin >> maxFloor;
    }
    rewind(stdin);
    std::string city, region, street, metro, condition;
    std::string repairS, parkingS, secureS;

    std::cout << std::setw(30) << std::left << "Город: ";
    std::getline(std::cin, city);
    std::cout << std::setw(30) << std::left << "Регион: ";
    std::getline(std::cin, region);
    std::cout << std::setw(30) << std::left << "Улица: ";
    std::getline(std::cin, street);

    if (mode == 2)
    {
        std::cout << std::setw(30) << std::left << "Метро: ";
        std::getline(std::cin, metro);
        std::cout << std::setw(30) << std::left << "Состояние (condition) (Commercial) (Enter чтобы пропустить): ";
        std::getline(std::cin, condition);

        std::cout << std::setw(30) << std::left << "Ремонт? (y/n/Enter): ";
        std::getline(std::cin, repairS);
        std::cout << std::setw(30) << std::left << "Парковка? (y/n/Enter): ";
        std::getline(std::cin, parkingS);
        std::cout << std::setw(30) << std::left << "Охрана? (y/n/Enter): ";
        std::getline(std::cin, secureS);
    }

    // --- Поиск по списку ---
    Node<Property *> *curr = property.getHead();
    if (property.isEmpty())
    {
        std::cout << "Список объектов пуст.\n";
        return;
    }

    std::vector<Property *> results;
    while (curr)
    {
        Property *p = curr->data;
        curr = curr->next;
        if (!p)
            continue;

        if (numType != 0)
        {
            bool okType = false;
            switch (numType)
            {
            case 1:
                okType = (dynamic_cast<Apartment *>(p) != nullptr);
                break;
            case 2:
                okType = (dynamic_cast<Commercial *>(p) != nullptr);
                break;
            case 3:
                okType = (dynamic_cast<Garage *>(p) != nullptr);
                break;
            case 4:
                okType = (dynamic_cast<House *>(p) != nullptr);
                break;
            case 5:
                okType = (dynamic_cast<Land *>(p) != nullptr);
                break;
            case 6:
                okType = (dynamic_cast<Storage *>(p) != nullptr);
                break;
            case 7:
                okType = (dynamic_cast<Office *>(p) != nullptr);
                break;
            default:
                okType = true;
                break;
            }
            if (!okType)
                continue;
        }
        if (minPrice != -1 && p->getPrice() < minPrice)
            continue;
        if (maxPrice != -1 && p->getPrice() > maxPrice)
            continue;
        if (minArea >= 0.0 && p->getTotalArea() < minArea)
            continue;
        if (maxArea >= 0.0 && p->getTotalArea() > maxArea)
            continue;
        //////////////////////////////
        /////////////////
        /////////////
        /////////
        //////
        ///
        //  ПЕРЕПИШИ .................

        if (!city.empty())
        {
            std::string hay = p->getCity();
            if (hay.find(city) == std::string::npos)
                continue;
        }
        if (!region.empty())
        {
            std::string hay = p->getRegion();
            if (hay.find(region) == std::string::npos)
                continue;
        }
        if (!street.empty())
        {
            std::string hay = p->getStreet();
            if (hay.find(street) == std::string::npos)
                continue;
        }

        if (mode == 2)
        {
            if (Apartment *ap = dynamic_cast<Apartment *>(p))
            {
                if (minRooms != -1 && ap->getCountRoom() < minRooms)
                    continue;
                if (maxRooms != -1 && ap->getCountRoom() > maxRooms)
                    continue;
                if (minFloor != -1 && ap->getNumFloor() < minFloor)
                    continue;
                if (maxFloor != -1 && ap->getNumFloor() > maxFloor)
                    continue;
                if (!metro.empty())
                {
                    std::string hay = ap->getMetro();
                    if (hay.find(metro) == std::string::npos)
                        continue;
                }
                if (!repairS.empty())
                {
                    char c = repairS[0];
                    if (c == 'y' || c == 'Y')
                    {
                        if (!ap->getRepair())
                            continue;
                    }
                    else if (c == 'n' || c == 'N')
                    {
                        if (ap->getRepair())
                            continue;
                    }
                }
            }

            if (Commercial *com = dynamic_cast<Commercial *>(p))
            {
                if (!condition.empty())
                {
                    std::string hay = com->getCondition();
                    if (hay.find(condition) == std::string::npos)
                        continue;
                }
                if (!metro.empty())
                {
                    std::string hay = com->getMetro();
                    if (hay.find(metro) == std::string::npos)
                        continue;
                }
                if (!parkingS.empty())
                {
                    char c = parkingS[0];
                    if (c == 'y' || c == 'Y')
                    {
                        if (!com->getHasParking())
                            continue;
                    }
                    else if (c == 'n' || c == 'N')
                    {
                        if (com->getHasParking())
                            continue;
                    }
                }
                if (!secureS.empty())
                {
                    char c = secureS[0];
                    if (c == 'y' || c == 'Y')
                    {
                        if (!com->getSecureSystem())
                            continue;
                    }
                    else if (c == 'n' || c == 'N')
                    {
                        if (com->getSecureSystem())
                            continue;
                    }
                }
            }
        }
        results.push_back(p);
    }

    std::cout << "\n"
              << std::string(60, '=') << "\n";
    if (results.empty())
    {
        std::cout << "По заданным критериям ничего не найдено.\n";
        std::cout << std::string(60, '=') << "\n";
        return;
    }

    std::cout << "Найдено объектов: " << results.size() << "\n\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        Property *pp = results[i];
        std::cout << std::setw(4) << (i + 1) << " | ";

        if (Apartment *apartment = dynamic_cast<Apartment *>(pp))
        {
            std::cout << "[Apartment]\n-----------------------------\n";
            std::cout << *apartment << std::endl;
        }
        else if (Commercial *commercial = dynamic_cast<Commercial *>(pp))
        {
            std::cout << "[Commercial]\n-----------------------------\n";
            std::cout << *commercial << std::endl;
        }
        else if (Garage *garage = dynamic_cast<Garage *>(pp))
        {
            std::cout << "[Garage]\n-----------------------------\n";
            std::cout << *garage << std::endl;
        }
        else if (House *house = dynamic_cast<House *>(pp))
        {
            std::cout << "[House]\n-----------------------------\n";
            std::cout << *house << std::endl;
        }
        else if (Land *land = dynamic_cast<Land *>(pp))
        {
            std::cout << "[Land]\n-----------------------------\n";
            std::cout << *land << std::endl;
        }
        else if (Storage *storage = dynamic_cast<Storage *>(pp))
        {
            std::cout << "[Storage]\n-----------------------------\n";
            std::cout << *storage << std::endl;
        }
        else if (Office *office = dynamic_cast<Office *>(pp))
        {
            std::cout << "[Office]\n-----------------------------\n";
            std::cout << *office << std::endl;
        }
        else
        {
            std::cout << "[Unknown]\n-----------------------------\n";
            std::cout << *pp << std::endl;
        }

        std::cout << std::string(60, '-') << "\n";
    }
    std::cout << std::string(60, '=') << "\n";
}

void EngineSystem::printAllProperties()
{
    if (property.isEmpty())
    {
        std::cout << "В системе нет объектов недвижимости." << std::endl;
        return;
    }

    std::cout << "\n=== ВСЕ ОБЪЕКТЫ НЕДВИЖИМОСТИ ===" << std::endl;
    std::cout << "Всего объектов: " << property.getSize() << std::endl;
    std::cout << "=================================" << std::endl;

    Node<Property *> *current = property.getHead();
    int index = 1;

    while (current != nullptr)
    {
        std::cout << "\n--- Объект " << index << " ---" << std::endl;

        Property *prop = current->data;

        // ДОБАВЬТЕ ПРОВЕРКУ НА NULL
        if (prop == nullptr)
        {
            std::cout << "NULL OBJECT - пропускаем" << std::endl;
            current = current->next;
            index++;
            continue;
        }

        // ДОБАВЬТЕ ПРОВЕРКУ ДАННЫХ
        if (prop->getTotalArea() <= 0 || prop->getPrice() <= 0)
        {
            std::cout << "НЕКОРРЕКТНЫЕ ДАННЫЕ - пропускаем" << std::endl;
            current = current->next;
            index++;
            continue;
        }

        try
        {
            if (Apartment *apartment = dynamic_cast<Apartment *>(prop))
            {
                std::cout << *apartment << std::endl;
            }
            else if (auto *office = dynamic_cast<Office *>(prop))
            {
                std::cout << *office << std::endl;
            }
            else if (auto *house = dynamic_cast<House *>(prop))
            {
                std::cout << *house << std::endl;
            }
            else if (auto *garage = dynamic_cast<Garage *>(prop))
            {
                std::cout << *garage << std::endl;
            }
            else if (auto *land = dynamic_cast<Land *>(prop))
            {
                std::cout << *land << std::endl;
            }
            else if (auto *storage = dynamic_cast<Storage *>(prop))
            {
                std::cout << *storage << std::endl;
            }
            else
            {
                std::cout << *prop << std::endl;
            }
        }
        catch (...)
        {
            std::cout << "ОШИБКА ВЫВОДА - пропускаем" << std::endl;
        }

        std::cout << "------------------------" << std::endl;

        current = current->next;
        index++;
    }
}
