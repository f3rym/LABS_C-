#pragma once

#include "file.h"
#include "../listNode.h"
#include "FileExp.h"

template <class T>
class FileBin : public File
{
public:
    FileBin(const std::string &name);

    void writeLinkedList(const LinkedList<T> &list);
    void readLinkedList(LinkedList<T> &list);

    FileBin<T> &operator<<(const LinkedList<T> &list);
    FileBin<T> &operator>>(LinkedList<T> &list);
};

#include "../../source/file/fileBin.tpp"