#ifndef ALGORITHM_H
#define ALGORITHM_H
template <typename Iterator, typename T>
class Algorithm;

template <typename Iterator, typename T>
class Algorithm
{
public:
    static std::vector<T> findAllWithParametersSTL(Iterator begin, Iterator end, T &example);
    static LinkedList<T> findAllWithParameters(Iterator begin, Iterator end, T &example);
    static void sortByParam1(Iterator begin, Iterator end);
};

#include "../source/Algorithm.tpp"
#endif 
