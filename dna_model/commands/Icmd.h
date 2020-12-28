#ifndef __ICMD_H__
#define __ICMD_H__

#include <vector>
#include <iostream>
#include "../dna_sequence/dna_data.h"

class ICMD
{
public:
    ICMD(){};
    virtual std::string Execute(std::vector<std::string>) = 0;
    virtual ~ICMD(){};

    static size_t GetID();
    static void SetId(size_t);

private:
    static size_t m_serial_id;
};

inline size_t ICMD::GetID()
{
    return ++m_serial_id;
}

inline void ICMD::SetId(size_t id)
{
    m_serial_id = id;
}
#endif





