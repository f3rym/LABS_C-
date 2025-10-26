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
    Node()
    {
        data = NULL;
        next = nullptr;
        prev = nullptr;
    }
    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    Node(Node &other)
    {
        data = other.data;
        next = other.next;
        prev = other.prev;
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
        free();
    };
    bool isEmpty()
    {
        if(head == nullptr)
            return true;
        return false;
    }
    void free()
    {
        Node<T> *curr = head;
        while (curr != nullptr)
        {
            Node<T> *next = curr->next;
            delete curr;
            curr = next;
        }
    }
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
    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            Node<T> *curr = head;
            while (curr != nullptr)
            {
                Node<T> *next = curr->next;
                delete curr;
                curr = next;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
            Node<T> *other_curr = other.head;
            while (other_curr != nullptr)
            {
                addToEnd(other_curr->data);
                other_curr = other_curr->next;
            }
        }
        return *this;
    }
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
        if (index < 0 || index >= size)
        {
            return false;
        }
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
    friend std::ostream &operator<<(std:: ostream &os, LinkedList<T> &list)
    {
        Node<T> *curr = list.head;
        for (int i = 0; i < list.size; i++)
        {
            os << std::setw(8) << i + 1;
            os << curr->data << std::endl;
            curr = curr->next;
        }
        return os;
    }
    int getSize()
    {
        return size;
    }
};

#endif