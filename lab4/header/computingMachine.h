#ifndef ComputingMachine_H
#define ComputingMachine_H

#include "../header.h"

class ComputingMachine
{
    char name[MAX_STR];
    char processor[MAX_STR];
    int ram;

public:
    ComputingMachine()
    {
        ram = 0;
        name[0] = '\0';
        processor[0] = '\0';
    }
    ComputingMachine(char *name, char *processor, int ram)
    {
        strcpy_s(this->name, name);
        strcpy_s(this->processor, processor);
        this->ram = ram;
    };
    ComputingMachine &operator=(const ComputingMachine &other);
    friend std::ostream &operator<<(std::ostream &os, ComputingMachine &s);
    friend std::istream &operator>>(std::istream &is, ComputingMachine &s);
    const char *getName() const;
    const char *getProcessor() const;
    int getRam() const;
    void setName(char *name);
    void setProcessor(char *processor);
    void setRam(int ram);
    virtual void info();
    virtual void setMenu();
    virtual ~ComputingMachine() = default;
};

#endif