#ifndef __SHOW_H__
#define __SHOW_H__

#include "ICMD.h"

struct ShowParams
{

}ShowParams;

class Show : ICMD
{
public:
    void Execute();
private:
    ShowParams m_params;
};

#endif