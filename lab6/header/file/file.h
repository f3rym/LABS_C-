#pragma once

#include "../../header.h"

class File
{
protected:
    std::string filename;

public:
    File(const std::string &name) : filename(name) {}
    virtual ~File() {}
    
    std::st
    ring getFilename() const { return filename; }
    void setFilename(const std::string &name) { filename = name; }
};