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

class EngineSystem
{
    std::vector<User *> users;
    LinkedList<Property *> property;

public:
    EngineSystem()
    {
        users.clear();
    }
    EngineSystem(User &user, Property &prop)
    {
        users.push_back(&user);
        property.addToEnd(&prop);
    }
    EngineSystem(const EngineSystem &other)
    {
        for (auto user : other.users)
        {
            users.push_back(new User(*user));
        }
        property = other.property;
    }
    ~EngineSystem()
    {
        // for (auto user : users)
        // {
        //     delete user;
        // }
        // users.clear();
        // property.free();
    }
    bool addUser();
    bool addProperty(User &user);
    void findByParam(int numType);
    void printAllProperties();

    std::vector<User *> &getUsers() { return users; }
    void setUsers(const std::vector<User *> &newUsers) { users = newUsers; }
    void load();

    LinkedList<Property *> &getProperties()
    {
        return property;
    }
    const LinkedList<Property *> &getProperties() const { return property; }

    User* login();
};
