#ifndef LISTNODE_H
#define LISTNODE_H

#include "../header.h"
#include "Algorithm.h"

template <typename T>
class LinkedList;
template <typename T>
class LinkedListIterator;

template <typename T>
class Node
{
    friend class LinkedList<T>;
    friend class LinkedListIterator<T>;
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

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
class LinkedListIterator
{
private:
    Node<T> *current;

public:
    LinkedListIterator(Node<T> *start = nullptr) : current(start) {}
    LinkedListIterator(const LinkedListIterator &other) : current(other.current) {}

    T &operator*();
    T *operator->();
    const T *operator->() const;
    LinkedListIterator &operator++();

    LinkedListIterator &operator--();

    LinkedListIterator operator++(int);
    LinkedListIterator operator--(int);

    bool operator==(const LinkedListIterator &other) const;

    bool operator!=(const LinkedListIterator &other) const;

    Node<T> *getNode() const;
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

    int getSize() const;
    const T &operator[](int index) const;
    void addToEnd(const T &value);
    void addToFront(const T &value);
    bool removeByIndex(int index);
    bool remove(const T &value);
    int find(const T &value);
    T &operator[](int index);

    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();

    LinkedList<T> finder(T example);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &list);

    template <typename U>
    friend std::istream &operator>>(std::istream &is, LinkedList<U> &list);
};



#include "../source/listNode.tpp"
#endif