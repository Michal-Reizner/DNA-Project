#include "cmd_collection.h"


CMDCollection::CMDCollection()
{
    m_cmd_map["new"] = new New;
    m_cmd_map["load"] = new Load;
    m_cmd_map["quit"] = new Quit;
    m_cmd_map["save"] = new Save;
}

CMDCollection::~CMDCollection()
{
    for(std::map<const std::string, ICMD*>::iterator it = m_cmd_map.begin(); it != m_cmd_map.end();it++)
    {
        delete (*it).second;
    }

}





