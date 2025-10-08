#include "../header.h"
#include "../header/portableMachine.h"

PortableMachine::PortableMachine() : Computer()
{
    sizeDisplay = 0;
    butteryHealth = 0;
}
PortableMachine::PortableMachine(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay) : Computer(name, processor, ram)
{
    this->butteryHealth = butteryHealth;
    this->sizeDisplay = sizeDisplay;
}
PortableMachine::PortableMachine(const PortableMachine &other) : Computer(other)
{
    this->butteryHealth = other.butteryHealth;
    this->sizeDisplay = other.sizeDisplay;
}
void PortableMachine::print()
{
    Computer::print();
    std::cout << "Объем батареи: " << butteryHealth << std::endl;
    std::cout << "Размер дисплея: " << sizeDisplay << " дюймов." << std::endl;
}
