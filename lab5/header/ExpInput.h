#include "../header.h"
#include "Exp.h"

class ExpInput : public Exp
{
    char err[MAX_STR];

public:
    ExpInput() : Exp()
    {
        err[0] = '\0';
    };
    ExpInput(const char *err, int code) : Exp(code, "Ошибка ввода")
    {
        strcpy_s(this->err, err);
    };
    ExpInput(const Exp &other) : Exp(other) {};
    ~ExpInput() = default;
    int isNumber(std::istream &input);
    int isNumber(std::istream &input, int minInt, int maxInt);
    bool isBool(std::istream &input);
    std::string isString(std::istream &input);
    std::string isStringWithNumbers(std::istream &input);
};