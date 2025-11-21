#include "../header.h"

class Exp
{
protected:
    int code;
    char message[MAX_STR];

public:
    Exp()
    {
        code = 0;
        message[0] = '\0';
    }
    Exp(int code, const char *message)
    {
        this->code = code;
        strcpy_s(this->message, message);
    }
    Exp(const Exp &other)
    {
        code = other.code;
        strcpy_s(message, other.message);
    }
    ~Exp() = default;
};