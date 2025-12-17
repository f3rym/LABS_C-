#include <fstream>
#include <iostream>

template <class T>
FileBin<T>::FileBin(const std::string &name) : File(name) {}

template <class T>
void FileBin<T>::writeLinkedList(const LinkedList<T> &list)
{
    FileExcept exp;

    std::ofstream file(filename, std::ios::binary);
    exp.isOpenFile(file);
    int count = list.getSize();
    for (int i = 0; i < count; i++)
    {
        const T &data = list[i];
        file.write(reinterpret_cast<const char *>(&data), sizeof(T));
    }
    file.close();
    std::cout << "Сохранено " << count << " объектов в (bin) " << filename << std::endl;
}

template <class T>
void FileBin<T>::readLinkedList(LinkedList<T> &list)
{
    FileExcept exp;

    std::ifstream file(filename, std::ios::binary); 
    exp.isOpenFile(file);
    list.free();
    int loaded = 0;
    while (file.peek() != EOF)
    {
        T obj;
        file.read(reinterpret_cast<char *>(&obj), sizeof(T));

            list.addToEnd(obj);
            loaded++;
    }
    file.close();
    std::cout << "Загружено " << loaded << " объектов (bin) из " << filename << std::endl;
}

template <class T>
FileBin<T> &FileBin<T>::operator<<(const LinkedList<T> &list)
{
    writeLinkedList(list);
    return *this;
}

template <class T>
FileBin<T> &FileBin<T>::operator>>(LinkedList<T> &list)
{
    readLinkedList(list);
    return *this;
}