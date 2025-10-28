#ifndef INTERFACE_H
#define INTERFACE_H

#include "../header.h"
#include "laptop.h"
#include "mono.h"
#include "tablet.h"

class Interface
{
private:
    LinkedList<MonoBlock> monoblocks;
    LinkedList<Laptop> laptops;
    LinkedList<Tablet> tablets;

public:
    Interface(): monoblocks(), laptops(), tablets(){};
    Interface(const Interface &other)
    {
        monoblocks = other.monoblocks;
        laptops = other.laptops;
        tablets = other.tablets;
    }
    ~Interface() = default;

    void mn_menu();
    void laptops_menu();
    void tablets_menu();

    void editComputingMachine(ComputingMachine &device);

    void sortMonoblocksByRAM();
};

#endif