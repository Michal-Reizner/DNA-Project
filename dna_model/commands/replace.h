#ifndef __REPLACE_H__
#define __REPLACE_H__

#include "ICMD.h"

struct ReplaceParams
{

}ReplaceParams;

class Replace : ICMD
{
public:
    void Execute();
private:
    ReplaceParams m_params;
};

#endif