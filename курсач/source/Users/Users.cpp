#include "../../header.h"
#include "../../header/Users/User.h"
#include "../../header/Users/RegUser.h"
#include "../../header/Users/Admin.h"

int User::getId() const { return id; }

char *User::getName() { return name; }

char *User::getPassword() { return password; }

bool User::getIsActive() { return isActive; }

void User::setId(int newId) { id = newId; }

void User::setName(char *newName) { strcpy_s(name, newName); }

void User::setPassword(char *newPassword) { strcpy_s(password, newPassword); }

void User::setIsActive(bool active) { isActive = active; }

bool User::checkPassword(const char *inputPassword) const
{
    return strcmp(password, inputPassword) == 0;
}

std::ostream &operator<<(std::ostream &os, User &user)
{
    os << std::setw(10) << user.id;
    os << std::setw(20) << user.name;
    os << std::setw(20) << user.password;
    os << std::setw(10) << (user.isActive ? "Active" : "Inactive");
    return os;
}

std::istream &operator>>(std::istream &is, User &user)
{
    char name[MAX_STR];
    char password[MAX_STR];
    bool isActive;

    std::cout << "Введите имя: ";
    is.getline(name, MAX_STR);
    std::cout << "Введите пароль: ";
    is.getline(password, MAX_STR);
    std::cout << "Активен (1-да/0-нет): ";
    is >> isActive;

    user.setName(name);
    user.setPassword(password);
    user.setIsActive(isActive);

    return is;
}

void saveUserToFile(const char *type, User *user)
{
    std::ofstream file("files/users.txt", std::ios::app);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла users.txt для записи\n";
        return;
    }

    file << type << ' '
         << user->getId() << ' '
         << std::quoted(std::string(user->getName())) << ' '
         << std::quoted(std::string(user->getPassword())) << ' '
         << (user->getIsActive() ? 1 : 0);

    // Тип-специфичные поля
    if (RegUser *ru = dynamic_cast<RegUser *>(user))
    {
        file << ' ' << ru->getBalance();
    }
    // else if (Admin *ad = dynamic_cast<Admin *>(user))
    // {
    //     int lc = ad->getLogCount();
    //     file << ' ' << lc;
    //     for (int i = 0; i < lc; ++i)
    //     {
    //         file << ' ' << std::quoted(std::string(ad->getLog(i)));
    //     }
    // }

    file << '\n';
    file.close();
}

// loadUsersFromFile
std::vector<User *> loadUsersFromFile()
{
    std::vector<User *> users;
    std::ifstream file("files/users.txt");
    if (!file.is_open())
    {
        // если файла нет — возвращаем пустой вектор
        std::cerr << "Файл files/users.txt не найден — верну пустой список пользователей\n";
        return users;
    }

    std::string line;
    int maxId = 0;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::istringstream iss(line);

        std::string type;
        if (!(iss >> type))
            continue;

        int id = -1;
        if (!(iss >> id))
            continue;

        std::string name, password;
        int isActiveInt = 1;
        if (!(iss >> std::quoted(name) >> std::quoted(password) >> isActiveInt))
            continue;

        User *u = nullptr;
        if (type == "admin")
        {
            Admin *ad = new Admin();
            // читаем logCount
            int logCount = 0;
            if (!(iss >> logCount))
                logCount = 0;
            // читаем logCount строк
            for (int i = 0; i < logCount; ++i)
            {
                std::string logEntry;
                if (iss >> std::quoted(logEntry))
                {
                    ad->addLog(logEntry.c_str());
                }
                else
                {
                    // недочитан лог — прекращаем
                    break;
                }
            }
            u = ad;
        }
        else if (type == "user" || type == "reguser")
        {
            RegUser *ru = new RegUser();
            int bal = 0;
            if (!(iss >> bal))
                bal = ru->getBalance(); 
            ru->setBalance(bal);
            u = ru;
        }
        else
        {
            User *uu = new User();
            u = uu;
        }

        if (!u)
            continue;

        u->setId(id);
        u->setName(const_cast<char *>(name.c_str()));
        u->setPassword(const_cast<char *>(password.c_str()));
        u->setIsActive(isActiveInt != 0);

        users.push_back(u);
        if (id > maxId)
            maxId = id;


    }

    file.close();

    User::setNextId(maxId + 1);

    return users;
}