#include "User.h"

class RegUser : public User
{
    int balance;

public:
    RegUser();
    RegUser(int id, char* name, char* password, int balance);
    RegUser(const RegUser& other);
    virtual ~RegUser(){};
};