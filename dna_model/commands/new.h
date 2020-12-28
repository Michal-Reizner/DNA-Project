#ifndef __NEW_H__
#define __NEW_H__

#include "Icmd.h"


class New : public ICMD
{
public:
    New();
    /*virtual*/std::string Execute(std::vector<std::string>);
    /*virtual*/~New(){};
};


#endif