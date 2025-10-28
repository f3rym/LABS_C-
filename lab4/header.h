#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <conio.h>

#define MAX_STR 80
#define MAX_CMP 20

class ComputingMachine;
class portableMachine;
class StationaryMachine;
class Laptop;
class Tablet;
class MonoBlock;
template <typename T>
class LinkedList;
template <typename T>
class Node;

void waitForAnyKey();
void mn_menu();
void laptops_menu();
void tablets_menu();

int againProg();
#endif