#include "../header/listNode.h"
#include "../header.h"

template <typename T>
void LinkedList<T>::free()
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        Node<T> *next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (this != &other)
    {
        free();
        Node<T> *other_curr = other.head;
        while (other_curr != nullptr)
        {
            addToEnd(other_curr->data);
            other_curr = other_curr->next;
        }
    }
    return *this;
}

template <typename T>
void LinkedList<T>::addToEnd(const T &value)
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
bool LinkedList<T>::removeByIndex(int index)
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

template <typename T>
bool LinkedList<T>::remove(const T &value)
{
    int num;
    num = find(value);
    if (num == -1)
        return false;
    return removeByIndex(num);
}

template <typename T>
int LinkedList<T>::find(const T &value)
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

template <typename T>
T &LinkedList<T>::operator[](int index)
{
    Node<T> *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->data;
}

template <typename T>
const T &LinkedList<T>::operator[](int index) const
{
    Node<T> *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->data;
}

template <typename T>
Node<T> *LinkedList<T>::begin()
{
    return head;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
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

template <typename T>
std::istream &operator>>(std::istream &is, LinkedList<T> &list)
{
    T value;
    if (is >> value)
        list.addToEnd(value);
    return is;
}

template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}