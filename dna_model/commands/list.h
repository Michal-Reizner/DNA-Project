#ifndef __LIST_H__
#define __LIST_H__

#include "ICMD.h"

struct ListParams
{

}ListParams;

class List : ICMD
{
public:
    void Execute();
private:
    ListParams
    m_params;
};

#endif