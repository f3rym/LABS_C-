#pragma once

#include "../header.h"
#include "Property.h"
#include "Users/Admin.h"
#include "Users/RegUser.h"
#include "Users/User.h"
#include "Apartment.h"
#include "Garage.h"
#include "House.h"
#include "Land.h"
#include "Storage.h"
#include "Office.h"
#include "listNode.h"

class EngineSystemBase
{
    std::vector<User> users;

public:
    EngineSystemBase() {};
    virtual ~EngineSystemBase() = default;

    void load();
    bool addUser();
    User login();
    void menuUser(User &us);
    void menu(User &us);
    void showMyProperties(User &us);
};

template <class T>
class EngineSystem
{
    LinkedList<T> property;

public:
    EngineSystem() {};
    ~EngineSystem() = default;
    int showPropertiesByOwnerId(const char *filename, const char *typeName, int ownerId);
    void fun(User &us, char *filename);
    void load(const char *filename);
    LinkedList<T> getProperty()
    {
        return property;
    }
};
#include "../source/EngineSystem.tpp"