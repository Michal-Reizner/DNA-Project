#ifndef __IWRITER_H__
#define __IWRITER_H__

#include <iostream>
class IWriter
{
public:
    virtual void Write(std::string) = 0;
    virtual ~IWriter(){};
};
#endif
