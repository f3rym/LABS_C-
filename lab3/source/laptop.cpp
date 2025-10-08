#include "../header.h"

//#include "../header/portableMachine.h"
#include "../header/laptop.h"

Laptop::Laptop() : PortableMachine()
{
    bool hasBacklitKeyboard;
}
Laptop::Laptop(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, bool hasBacklitKeyboard) : PortableMachine(name, processor, ram, butteryHealth, sizeDisplay)
{
    this->hasBacklitKeyboard = hasBacklitKeyboard;
}
Laptop::Laptop(const Laptop &other) : PortableMachine(other)
{
    this->hasBacklitKeyboard = other.hasBacklitKeyboard;
}
void Laptop::print()
{
    PortableMachine::print();
    std::cout << "Клавиатура ";

    if (hasBacklitKeyboard == true)
        std::cout << "имеет подсветку." << std::endl;
    else
        std::cout << "НЕ имеет подсветку." << std::endl;
}