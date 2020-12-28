#ifndef __SLICE_H__
#define __SLICE_H__

#include "ICMD.h"

struct SliceParams
{

}SliceParams;

class Slice: ICMD
{
public:
    void Execute();
private:
    SliceParams m_params;
};

#endif