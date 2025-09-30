#include <iostream>
#include <locale>

class intersectionArrays
{
    int *array;
    int size;
public:
    intersectionArrays();
    intersectionArrays(int size);
    intersectionArrays(const intersectionArrays &other);
    void enterElements();
    //  intersectionArrays findIntersection(intersectionArrays& m, intersectionArrays& n);
    intersectionArrays findIntersection(intersectionArrays &n);
    intersectionArrays operator+(const intersectionArrays &other);
    intersectionArrays operator=(const intersectionArrays &other);
    void printArray();
    ~intersectionArrays();
};
void menu();
int enterInfoAboutArray(int i);
int againProg();
