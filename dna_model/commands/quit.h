#ifndef __QUIT_H__
#define __QUIT_H__

#include "Icmd.h"

class Quit : public ICMD
{
public:
    Quit();
    /*virtual*/std::string Execute(std::vector<std::string>);
    /*virtual*/~Quit(){};
private:
};

#endif