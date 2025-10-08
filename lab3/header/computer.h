#include "../header.h"


class Computer
{
    char name[MAX_STR];
    char processor[MAX_STR];
    int ram;

public:
    Computer();
    Computer(char *name, char *processor, int ram);
    Computer(const Computer &other);
    friend std::ostream &operator<<(std::ostream &os, Computer &s);
    friend std::istream &operator>>(std::istream &is, Computer &s);
    virtual ~Computer() {};
    virtual void print();
};






void menu();
int againProg();