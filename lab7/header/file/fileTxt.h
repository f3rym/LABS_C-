#pragma once

#include "../../header.h"
#include "file.h"
#include "../listNode.h"
#include "FileExp.h"

template <class T>
class FileTxt : public File
{
public:
    FileTxt(const std::string &name) : File(name) {};

    void writeLinkedList(const LinkedList<T> &list);
    void readLinkedList(LinkedList<T> &list);
    void readFromSTLcontainer(std::vector<T> &list);
    void writeToSTLcontainer(const std::vector<T> &list);
    FileTxt<T> &operator<<(const LinkedList<T> &list);
    FileTxt<T> &operator>>(LinkedList<T> &list);
};

#include "../../source/file/fileTxt.tpp"