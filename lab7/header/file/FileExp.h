#pragma once
#include "../../header.h"
#include "../Exp.h"

class FileExcept : public Exp
{
protected:
    char error[60];

public:
    FileExcept() : Exp()
    {
        strcpy_s(error, 60, "");
    }

    FileExcept(int c, const char *err) : Exp(c, "File Error")
    {
        strcpy_s(error, 60, err);
    }

    FileExcept(const FileExcept &other) : Exp(other)
    {
        strcpy_s(error, 60, other.error);
    }


    template<typename Stream>
    bool isOpenFile(Stream &f);
    
    template<typename Stream>
    bool isWriteFile(Stream &f);

};
