#include "../header.h"
#include "../header/listNode.h"

template <typename T>
void LinkedList<T>::addToAnd(const T &value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head = nullptr)
        head = tail = newNode;
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::addToFront(const T &value)
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

template <typename T>
bool LinkedList<T>::remove(const T &value)
{
    int num;
    num = LinkedList::find(value);
    Node<T>* toDel;
    if (head == nullptr || num == -1) return false;
    if (num == 0)
    {
        toDel = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;
    }
    else if (num == (size - 1))
    {
        toDel = tail;
        tail = tail->next;
        if(tail = nullptr)
            head = nullptr;
        else
            tail->prev = nullptr;
    }
    else
    {
        for(int i = 0; i < num; num++)
            head = head->next;
        toDel = head;
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
    }
    delete toDel;
}

template <typename T>
int LinkedList<T>::find(const T &value)
{
    if (head == nullptr)
        return -1;
    Node<T> curr = head;
    int num = 0;
    while (curr != nullptr)
    {
        if (value == curr.data)
        {
            delete curr;
            return num;
        }
        num++;
        curr = curr->next;
    }
    delete curr;
}