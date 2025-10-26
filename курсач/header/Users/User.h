#pragma once

#include "../../header.h"

class User
{
    int static nextId;
    int id;
    char name[MAX_STR];
    char password[MAX_STR];
    bool isActive;

public:
    User()
    {
        id = nextId++;
        name[0] = '\0';
        password[0] = '\0';
        isActive = true;
    }
    User(int id, char *name, char *password)
    {
        id = nextId++;
        strcpy_s(this->name, name);
        strcpy_s(this->password, password);
    }
    User(const User &other)
    {
        id = other.id;
        strcpy_s(name, other.name);
        strcpy_s(password, other.password);
    }
    virtual ~User() = default;

    int getId() const;
    char *getName();
    char *getPassword();
    bool getIsActive();

    void setId(int newId);
    void setName(char *newName);
    void setPassword(char *newPassword);
    void setIsActive(bool active);

    static void setNextId(int newNext)
{
    if (newNext > 0)
        User::nextId = newNext;
}

    friend std::ostream &operator<<(std::ostream &os, User &user);
    friend std::istream &operator>>(std::istream &is, User &user);
    virtual bool checkPassword(const char *inputPassword) const;
};

void saveUserToFile(const char *filename, User *user);

std::vector<User *> loadUsersFromFile();
