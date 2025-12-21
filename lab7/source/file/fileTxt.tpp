#include <fstream>
#include <iostream>

template <class T>
void FileTxt<T>::writeLinkedList(const LinkedList<T> &list)
{
    FileExcept exp;

    std::ofstream file(filename);
    exp.isOpenFile(file);
    int count = list.getSize();
    for (int i = 0; i < count; i++)
    {
        list[i].writeToStream(file);
    }
    file.close();
    std::cout << "Сохранено " << count << " объектов в " << filename << std::endl;
}

template <class T>
void FileTxt<T>::readLinkedList(LinkedList<T> &list)
{
    FileExcept exp;
    std::ifstream file(filename);
    exp.isOpenFile(file);
    list.free();
    int loaded = 0;
    while (file.peek() != EOF)
    {
        T obj;
        obj.readFromStream(file);
        if (file.fail() || file.bad())
        {
            break;
        }
        list.addToEnd(obj);
        loaded++;
    }
    file.close();
    std::cout << "Загружено " << loaded << " объектов в LinkedList из " << filename << std::endl;
}
//STLllllllllllllllllllllllll

template <class T>
void FileTxt<T>::writeToSTLcontainer(const std::vector<T> &list)
{
    FileExcept exp;

    std::ofstream file(filename);
    exp.isOpenFile(file);
    int count = list.size();
    for (int i = 0; i < count; i++)
    {
        list[i].writeToStream(file);
    }
    file.close();
    std::cout << "Сохранено " << count << " объектов в " << filename << std::endl;
}

template <class T>
void FileTxt<T>::readFromSTLcontainer(std::vector<T> &list)
{
    FileExcept exp;
    std::ifstream file(filename);
    exp.isOpenFile(file);
    list.clear();
    int loaded = 0;
    while (file.peek() != EOF)
    {
        T obj;
        obj.readFromStream(file);
        if (file.fail() || file.bad())
        {
            break;
        }
        list.push_back(obj);
        loaded++;
    }
    file.close();
    std::cout << "Загружено " << loaded << " объектов в LinkedList из " << filename << std::endl;
}

template <class T>
FileTxt<T> &FileTxt<T>::operator<<(const LinkedList<T> &list)
{
    writeLinkedList(list);
    return *this;
}

template <class T>
FileTxt<T> &FileTxt<T>::operator>>(LinkedList<T> &list)
{
    readLinkedList(list);
    return *this;
}