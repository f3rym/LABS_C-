#include "../header.h"


class Computer
{
    char name[MAX_STR];
    char processor[MAX_STR];
    int ram;

public:
    Computer()
    {
        ram = 0;
        name[0] = '\0';
        processor[0] = '\0';
    }
    Computer(char *name, char *processor, int ram)
    {
        std::strcpy(this->name, name);
        std::strcpy(this->processor, processor);
        this->ram = ram;
    };
    Computer(const Computer &other)
    {
        std::strcpy(this->name, other.name);
        std::strcpy(this->processor, other.processor);
        this->ram = other.ram;
    };
    friend std::ostream &operator<<(std::ostream &os, Computer &s);
    friend std::istream &operator>>(std::istream &is, Computer &s);
    virtual int getPowerConsumption();
    virtual void info();

    virtual ~Computer() = default;
};






void menu();
int againProg();