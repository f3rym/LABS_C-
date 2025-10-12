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
    Computer &operator=(const Computer &other);
    friend std::ostream &operator<<(std::ostream &os, Computer &s);
    friend std::istream &operator>>(std::istream &is, Computer &s);
    const char* getName() const;
    const char* getProcessor() const;
    int getRam() const;
    void setName(char* name);
    void setProcessor(char* processor);
    void setRam(int ram);
    virtual void info();

    virtual ~Computer() = default;
};