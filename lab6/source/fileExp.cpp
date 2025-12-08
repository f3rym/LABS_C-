#include "FileExp.h"
#include <fstream>
#include <iostream>

template <typename Stream>
bool FileExcept::isOpenFile(Stream &f)
{
    try
    {
        if (!f.is_open())
        {
            throw FileExcept(30, ", файл не открыт");
        }

        if (f.fail() || f.bad())
        {
            throw FileExcept(31, ", поток файла в состоянии ошибки");
        }
        std::cout << "Файл открыт и доступен для операций" << std::endl;
        return true;
    }
    catch (const FileExcept &e)
    {
        std::cout << e.message << e.error << " [ code: " << e.code << " ]" << std::endl;
        return false;
    }
}

template <typename Stream>
bool FileExcept::isWriteFile(Stream &f)
{
    try
    {
        if (!f.is_open())
        {
            throw FileExcept(40, ", файл не открыт");
        }
        if (f.fail() || f.bad())
        {
            throw FileExcept(41, ", поток файла в состоянии ошибки");
        }
        return true;
    }
    catch (const FileExcept &e)
    {
        std::cout << e.message << e.error << " [ code: " << e.code << " ]" << std::endl;
        return false;
    }
}
template bool FileExcept::isOpenFile<std::ifstream>(std::ifstream &f);
template bool FileExcept::isOpenFile<std::ofstream>(std::ofstream &f);
template bool FileExcept::isOpenFile<std::fstream>(std::fstream &f);

template bool FileExcept::isWriteFile<std::ifstream>(std::ifstream &f);
template bool FileExcept::isWriteFile<std::ofstream>(std::ofstream &f);
template bool FileExcept::isWriteFile<std::fstream>(std::fstream &f);
