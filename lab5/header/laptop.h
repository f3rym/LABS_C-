#ifndef laptops_H
#define laptops_H

#include "../header.h"
#include "portableMachine.h"

class Laptop : public portableMachine
{
    bool hasBacklitKeyboard;

public:
    Laptop() : portableMachine()
    {
        hasBacklitKeyboard = false;
    };
    Laptop(char *name, char *processor, int ram, int batteryHealth, int sizeDisplay, bool hasBacklitKeyboard)
        : portableMachine(name, processor, ram, batteryHealth, sizeDisplay)
    {
        this->hasBacklitKeyboard = hasBacklitKeyboard;
    };
    Laptop(const Laptop &other) : portableMachine(other)
    {
        this->hasBacklitKeyboard = other.hasBacklitKeyboard;
    };
    Laptop &operator=(const Laptop &other);
    friend std::ostream &operator<<(std::ostream &os, Laptop &Laptop);
    friend std::istream &operator>>(std::istream &is, Laptop &Laptop);
    void info() override;
    void setMenu() override;
    virtual ~Laptop() = default;
    bool getHasBacklitKeyboard() const;
    void setHasBacklitKeyboard(bool hasBacklitKeyboard);
};

#endif