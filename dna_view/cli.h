#ifndef __CLI_H__
#define __CLI_H__


#include <vector>
#include "read_write/Ireader.h"
#include "read_write/Iwriter.h"
#include "../dna_model/cmd_collection.h"


class CLI
{
public:
    CLI(IReader*, IWriter*);
    void Run();
    //static std::map<const std::string, ICMD*> GetCmdCollectionMap();
//    void SetReader(IReader* reader); params_vec = Split(cmd);
//    void SetWriter(IWriter*);
private:
    IReader* m_reader;
    IWriter* m_writer;
};

//inline std::map<const std::string, ICMD*> CLI::GetCmdCollectionMap()
//{
//    return m_cmdCollection.GetCMDMap();
//}

//////////////////////////////////////////////////////////////
/*#include "cli.h"

CMDCollection CLI::m_cmdCollection;

//######################### Auxiliary functions ####################################
static std::vector<std::string> Split(std::string str)
{
    std::vector<std::string> params;
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        params.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    params.push_back(str);
    return params;
}

inline static bool CheckIfValid(const std::vector<std::string>& params_vec)
{
    return CLI::GetCmdCollectionMap().GetCMDMap().find(params_vec[0]) != CLI::GetCmdCollectionMap().GetCMDMap().end();
}

inline std::string ExecuteCmd(const std::vector<std::string>& params_vec)
{
    ICMD* cmd = CLI::GetCmdCollectionMap().GetCMD(params_vec[0]);
    return cmd->Execute(params_vec);
}

//##################################################################################

CLI::CLI(IReader* reader, IWriter* writer):m_reader(reader),m_writer(writer)
{
}

void CLI::Run()
{
    std::vector<std::string> params_vec;
    std::string I_O_string;

    while (true)
    {
        std::cout<<"cmd >>> ";
        I_O_string = m_reader->Read();

        if (I_O_string == "quit")
        {
            break;
        }
        params_vec = Split(I_O_string);
        //I_O_string = CheckIfValid(params_vec) ? ExecuteCmd(params_vec) : "Invalid Input";
        ExecuteCmd(params_vec);
        m_writer->Write(I_O_string);
    }

//    I_O_string = ExecuteCmd("quit");
//    m_writer->Write(I_O_string);

    std::cout<<"cmd >>> ";
}
*/













#endif