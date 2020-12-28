#ifndef __FIND_H__
#define __FIND_H__

#include "ICMD.h"

struct FindParams
{

}FindParams;

class Find : ICMD
{
public:
    void Execute();
private:
    FindParams m_params;
};

#endif