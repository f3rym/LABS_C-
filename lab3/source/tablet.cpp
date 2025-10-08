#include "../header.h"
#include "../header/tablet.h"
// #include "../header/portableMachine.h"

Tablet::Tablet() : PortableMachine()
{
    char OS[MAX_STR];
}
Tablet::Tablet(char *name, char *processor, int ram, int butteryHealth, int sizeDisplay, char *OS) : PortableMachine(name, processor, ram, butteryHealth, sizeDisplay)
{
    std::strcpy(this->OS, OS);
}
Tablet::Tablet(const Tablet &other) : PortableMachine(other)
{
    std::strcpy(this->OS, other.OS);
}
void Tablet::print()
{
    PortableMachine::print();
    std::cout << "Операционная система: " << OS << std::endl;
}