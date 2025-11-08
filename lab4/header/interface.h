#ifndef INTERFACE_H
#define INTERFACE_H

#include "../header.h"
#include "laptop.h"
#include "mono.h"
#include "tablet.h"

template <class T>
class Interface
{
    LinkedList<T> computer;

public:
    Interface() {};
    ~Interface() = default;

    void menu();
    void fun();
    void editComputingMachine(T &device);
    void sortByParam();
};
#include "../source/interface.tpp"

#endif