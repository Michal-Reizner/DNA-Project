#ifndef __LEN_H__
#define __LEN_H__

#include "ICMD.h"

struct LenParams
{

}LenParams;

class Len : ICMD
{
public:
    void Execute();
private:
    LenParams m_params;
};

#endif