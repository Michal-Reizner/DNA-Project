#ifndef __IREADER_H__
#define __IREADER_H__

#include "iostream"


class IReader
{
public:
    virtual std::string Read() = 0;
    virtual ~IReader(){};
};
#endif








