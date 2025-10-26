#pragma once

#include "../../header.h"
#include "User.h"

class Admin : public User
{
    char Log[MAX_STR][MAX_STR];
    int logCount;

public:
    Admin() : User(), logCount(0)
    {
        for (int i = 0; i < MAX_STR; i++)
        {
            strcpy(Log[i], "");
        }
    }
    Admin(int id, char *name, char *password)
        : User(id, name, password), logCount(0)
    {
        for (int i = 0; i < MAX_STR; i++)
        {
            strcpy(Log[i], "");
        }
    }
    Admin(const Admin &other)
        : User(other), logCount(other.logCount)
    {
        for (int i = 0; i < logCount; i++)
        {
            strcpy(Log[i], other.Log[i]);
        }
    }

    void addLog(const char *action)
    {
        if (logCount < MAX_STR)
        {
            strcpy(Log[logCount], action);
            logCount++;
        }
    }

    void printLog()
    {
        std::cout << "Логи администратора " << getName() << ":\n";
        for (int i = 0; i < logCount; i++)
        {
            std::cout << i + 1 << ". " << Log[i] << std::endl;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, Admin &admin)
    {
        User &user = admin;
        os << user;
        os << " | Логи: " << admin.logCount << " записей";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Admin &admin)
    {
        User &user = admin;
        is >> user;
        return is;
    }
};