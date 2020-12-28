#ifndef __CONSOLE_WRITER_H__
#define __CONSOLE_WRITER_H__

#include "Iwriter.h"

class ConsoleWriter:public IWriter
{
public:
    /*virtual*/void Write(std::string);
    /*virtual*/~ConsoleWriter(){};
};

inline void ConsoleWriter::Write(std::string cmd)
{
    if (!cmd.empty())
    {
        std::cout<< cmd<<std::endl;
    }
}
#endif
