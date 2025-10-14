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
    Node(T value)
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
        Node<T>* curr = head;
        while(curr != nullptr)
        {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
    };

    void addToEnd(const T& value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
            head = tail = newNode;
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void addToFront(const T& value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    bool removeIndex(int index)
    {
        Node<T> *toDel = nullptr;
        if (head == nullptr || index == -1)
            return false;
        if (index == 0)
        {
            toDel = head;
            head = head->next;
            if (head == nullptr)
                tail = nullptr;
            else
                head->prev = nullptr;
        }
        else if (index == (size - 1))
        {
            toDel = tail;
            tail = tail->prev;
            if (tail == nullptr)
                head = nullptr;
            else
                tail->next = nullptr;
        }
        else
        {
            Node<T> *curr = head;
            for (int i = 0; i < index; i++)
                curr = curr->next;
            toDel = curr;
            toDel->prev->next = toDel->next;
            toDel->next->prev = toDel->prev;
        }
        delete toDel;
        size--;
        return true;
    }
    bool remove(const T &value)
    {
        int num;
        num = LinkedList::find(value);
        if (num == -1)
            return false;
        return removeIndex(num);
    }

    int find(const T& value)
    {
        if (head == nullptr)
            return -1;
        Node<T> *curr = head;
        int num = 0;
        while (curr != nullptr)
        {
            if (value == curr->data)
            {
                return num;
            }
            num++;
            curr = curr->next;
        }
        return -1;
    }
    T& operator[](int index)
    {
        Node<T> *curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;
        return curr->data;
    }
    Node<T> *getHead()
    {
        return head;
    }
    int getSize()
    {
        return size;
    }
    void setSize(int size)
    {
        this->size = size;
    }
};

#endif