#ifndef __CONSOLE_READER_H__
#define __CONSOLE_READER_H__

#include "Ireader.h"


class ConsoleReader:public IReader
{
public:
    /*virtual*/ std::string Read();
    /*virtual*/ ~ConsoleReader(){};
};

inline std::string ConsoleReader::Read()
{
    std::string cmd;
    getline(std::cin, cmd);

    return cmd;
}
#endif