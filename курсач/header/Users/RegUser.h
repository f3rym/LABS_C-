#pragma once

#include "../../header.h"
#include "User.h"

class RegUser : public User
{
    int balance;

public:
    RegUser() : User() 
    {
        balance = 1000;
    }
    RegUser(int id, char *name, char *password, int balance) : User(id, name, password)
    {
        this->balance = balance;
    }
    RegUser(const RegUser &other) : User(other)
    {
        balance = other.balance;
    }
    virtual ~RegUser() = default;
    friend std::ostream &operator<<(std::ostream &os, RegUser &user);
    friend std::istream &operator>>(std::istream &is, RegUser &user);
    int getBalance() const;
    void setBalance(int newBalance);
    void addBalance(int amount);
    void subtractBalance(int amount);
};

