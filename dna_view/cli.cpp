#include "cli.h"


//######################### Auxiliary functions ####################################

static std::vector<std::string> Split(std::string input)
{
    std::vector<std::string> params;
    std::string delimiter = " ";
    size_t pos = 0;
    std::string word;

    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        word = input.substr(0, pos);
        params.push_back(word);
        input.erase(0, pos + delimiter.length());
    }
    params.push_back(input);

    return params;
}

//##################################################################################

CLI::CLI(IReader* reader, IWriter* writer):m_reader(reader),m_writer(writer)
{
}

void CLI::Run()//TODO: check why after "save" command "new" command has undefined behavior
{
    std::vector<std::string> params_vec;
    ICMD* cmd;

    while (true)
    {
        std::cout<<"cmd >>> ";
        std::string I_O_string = m_reader->Read();

        if (I_O_string == "quit")
        {
            break;
        }
        params_vec = Split(I_O_string);

        try
        {
            cmd = m_cmdCollection.GetCMD(params_vec[0]);
            I_O_string = cmd->Execute(params_vec);
        }
        catch (std::invalid_argument& e)
        {
            I_O_string = e.what();
        }

        m_writer->Write(I_O_string);
    }

    cmd = m_cmdCollection.GetCMD("quit");
    m_writer->Write(cmd->Execute(params_vec));
}

