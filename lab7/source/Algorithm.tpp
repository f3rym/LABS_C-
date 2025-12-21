#include "../header.h"
#include <vector>


template <typename Iterator, typename T>
void Algorithm<Iterator, T>::sortByParam1(Iterator begin, Iterator end)
{
    std::vector<T> temp(begin, end);
    std::vector<ComputingMachine *> ptrVector;
    ptrVector.reserve(temp.size());

    for (int i = 0; i < temp.size(); ++i)
    {
        ptrVector.push_back(&temp[i]);
    }
    if (!temp.empty())
    {
        temp[0].sortList(ptrVector);
    }
    std::vector<T> sortedVector;
    sortedVector.reserve(ptrVector.size());
    for (auto *ptr : ptrVector)
    {
        T *typedPtr = dynamic_cast<T *>(ptr);
        if (typedPtr)
        {
            sortedVector.push_back(*typedPtr);
        }
    }
    std::copy(sortedVector.begin(), sortedVector.end(), begin);
    std::cout << "Машины отсортированы!" << std::endl;
}


template <typename Iterator, typename T>
std::vector<T> Algorithm<Iterator, T>::findAllWithParametersSTL(Iterator begin, Iterator end, T &example)
{
    std::vector<T> out;
    for (Iterator it = begin; it != end; ++it)
    {
        if (*it == example)
            out.push_back(*it);
    }
    return out;
}

template <typename Iterator, typename T>
LinkedList<T> Algorithm<Iterator, T>::findAllWithParameters(Iterator begin, Iterator end, T &example)
{
    LinkedList<T> out;
    for (Iterator it = begin; it != end; ++it)
    {
        if (*it == example)
            out.addToEnd(*it);
    }
    return out;
}