#ifndef __SAVE_H__
#define __SAVE_H__

#include "Icmd.h"


class Save : public ICMD
{
public:
    Save();
    /*virtual*/std::string Execute(std::vector<std::string>);
    /*virtual*/~Save(){};
};
#endif