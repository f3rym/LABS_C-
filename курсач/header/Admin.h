#include "../header.h"
#include "User.h"

class Admin : public User
{
    char Log[MAX_STR][MAX_STR];
public:
    Admin();
    Admin(int id, char *name, char *password);
    Admin(const Admin& other);
    virtual ~Admin(){};
    bool deleteUser(int userId, char *mesg);
    bool deleteProperty(int propertyId, char *mesg);
    /// @brief ///
    void printLog();
};