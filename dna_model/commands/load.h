#ifndef __LOAD_H__
#define __LOAD_H__

#include "Icmd.h"

typedef struct LoadParams
{
}LoadParams;

class Load : public ICMD
{
public:
    Load();
    /*virtual*/std::string Execute(std::vector<std::string>);
    /*virtual*/~Load(){};
private:
    LoadParams m_params;
};



#endif




