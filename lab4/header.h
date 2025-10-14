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
class PortableMachine;
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
void lap_menu();
void tab_menu();

int againProg();
#endif