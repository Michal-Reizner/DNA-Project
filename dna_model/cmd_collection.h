#ifndef __CMD_COLLECTION_H__
#define __CMD_COLLECTION_H__

#include <map>
#include "commands/commands.h"
#include "dna_sequence/exceptions.h"

class CMDCollection
{
public:
    CMDCollection();
    ~CMDCollection();
    ICMD* GetCMD(std::string);
    std::map<const std::string, ICMD*> GetCMDMap();
private:
    std::map<const std::string, ICMD*> m_cmd_map;
};


inline ICMD* CMDCollection::GetCMD(std::string cmd)
{
    if ((m_cmd_map.find(cmd)) == (m_cmd_map.end()))
    {
        throw std::invalid_argument("Invalid Input");
    }

    return m_cmd_map[cmd];
}

inline std::map<const std::string, ICMD*> CMDCollection::GetCMDMap()
{
    return m_cmd_map;
}


#endif