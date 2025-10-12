#include "../header.h"
#include "../header/portableMachine.h"
#include "../header/laptop.h"

Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        PortableMachine::operator=(other);
        hasBacklitKeyboard = other.hasBacklitKeyboard;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Laptop &lap)
{
    PortableMachine &pm = lap;
    os << pm;
    os << "Клавиатура " << (lap.hasBacklitKeyboard ? "имеет подсветку." : "НЕ имеет подсветку.");
    return os;
}
std::istream &operator>>(std::istream &is, Laptop &lap)
{
    PortableMachine &pm = lap;
    is >> pm;
    std::cout << "Есть подсветка клавиатуры? (1-да, 0-нет): ";
    is >> lap.hasBacklitKeyboard;
    return is;
}

void Laptop::info()
{
    PortableMachine::info();
    std::cout << "- Ноутбук";
}

bool Laptop::getHasBacklitKeyboard() const { return hasBacklitKeyboard; }
void Laptop::setHasBacklitKeyboard(bool hasBacklitKeyboard)
{
    this->hasBacklitKeyboard = hasBacklitKeyboard;
}
