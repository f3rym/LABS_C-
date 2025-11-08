#include "../header/listNode.h"
#include "../header.h"

template <typename T>
void LinkedList<T>::free()
{
    Node<T> *curr = head;
    while (curr)
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
bool LinkedList<T>::removeByIndex(int index)
{
    if (index < 0 || index >= size)
        return false;
    Node<T>* curr = head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return remove(curr->data);
}

template <typename T>
bool LinkedList<T>::remove(const T &value)
{
    Node<T>* curr = head;
    while(curr)
    {
        if(curr->data == value)
        {
            if(curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            else
                tail = curr->prev;
            delete curr;
            --size;
            return true;
        }
    }
    return false;
}

// template <typename T>
// void LinkedList<T>::swapNodes(Node<T> *a, Node<T> *b)
// {
//     if (a == b)
//         return;
//     if (a->next == b)
//     {
//         Node<T> *aPrev = a->prev;
//         Node<T> *bNext = b->next;

//         if (aPrev)
//             aPrev->next = b;
//         b->prev = aPrev;

//         b->next = a;
//         a->prev = b;

//         a->next = bNext;
//         if (bNext)
//             bNext->prev = a;
//     }
//     else if (b->next == a)
//     {
//         swapNodes(b, a);
//     }
//     else
//     {
//         Node<T> *aPrev = a->prev;
//         Node<T> *aNext = a->next;
//         Node<T> *bPrev = b->prev;
//         Node<T> *bNext = b->next;

//         if (aPrev)
//             aPrev->next = b;
//         if (aNext)
//             aNext->prev = b;
//         if (bPrev)
//             bPrev->next = a;
//         if (bNext)
//             bNext->prev = a;

//         a->prev = bPrev;
//         a->next = bNext;
//         b->prev = aPrev;
//         b->next = aNext;
//     }
//     if (head == a)
//         head = b;
//     else if (head == b)
//         head = a;

//     if (tail == a)
//         tail = b;
//     else if (tail == b)
//         tail = a;
// }

template <typename T>
T &LinkedList<T>::operator[](int index)
{
    // if (index < 0 || index >= size)
    //     return;
    Node<T> *curr;
    if (index < size / 2)
    {
        curr = head;
        for (int i = 0; i < index; ++i)
            curr = curr->next;
    }
    else
    {
        curr = tail;
        for (int i = size - 1; i > index; --i)
            curr = curr->prev;
    }

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
int LinkedList<T>::getSize()
{
    return size;
}