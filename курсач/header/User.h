#include "../header.h"

class User
{
    int id;
    char name[MAX_STR];
    char password[MAX_STR];
    bool isActive;
public:
    User();
    User(int id, char *name, char*password);
    User(const User &other);
    virtual ~User(){};
    int getId() const;
    virtual bool checkPassword(const char inputPassword) const;
};