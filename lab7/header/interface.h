#ifndef INTERFACE_H
#define INTERFACE_H

#include "../header.h"
#include "laptop.h"
#include "mono.h"
#include "tablet.h"


template<class T>
class Interface
{
private:
    LinkedList<T> computer;
    std::vector<T> computerSTL;
public:
    Interface(){};
    ~Interface() = default;

    void menu();
    void fun();
    void fun1(); 
    void editComputingMachine(T &device);
    void sortByParam1();
};
#include "../source/interface.tpp"

#endif