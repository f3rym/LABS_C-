#ifndef LISTNODE_H
#define LISTNODE_H

#include "../header.h"

template <typename T>
class LinkedList;
template <typename T>
class Node
{
    friend class LinkedList<T>;
    T data;
    Node<T> *next;
    Node<T> *prev;
public:
    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    Node(const Node &other)
    {
        data = other.data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head;
    Node<T> *tail;
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
        free();
    };
    bool isEmpty();
    void free();
    LinkedList(const LinkedList &other)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node<T> *curr = other.head;
        while (curr != nullptr)
        {
            addToEnd(curr->data);
            curr = curr->next;
        }
    }
    LinkedList &operator=(const LinkedList &other);
    void addToEnd(const T &value);
    void addToFront(const T &value);
    bool removeByIndex(int index);
    bool remove(const T &value);
    int find(const T &value);
    T &operator[](int index);
    Node<T> *begin();
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list);
    friend std::istream &operator>>(std::istream &is, LinkedList<T> &list);
    int getSize();
};

#endif