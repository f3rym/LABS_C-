#ifndef LISTNODE_H
#define LISTNODE_H

#include "../header.h"

template<typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const &T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template<typename T>
class LinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~LinkedList()
    {
        delete head;
        delete tail;
    };

    void addToAnd(const T& value);
    void addToFront(const T& value);
    bool remove(const T &value);
    int find(const T& value);
    void 

};

#endif