#ifndef __DUP_H__
#define __DUP_H__

#include "ICMD.h"

struct DupParams
{

}DupParams;

class Dup : ICMD
{
public:
    void Execute();
private:
    DupParams m_params;
};

#endif