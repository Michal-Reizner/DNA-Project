#include "manager.h"


Manager::Manager(IReader* reader, IWriter* writer):m_cli(reader,writer), m_cmdCollection()
{
}

Manager::~Manager()
{
}

void Manager::Init()
{

}

void Manager::ShutDown()
{
    std::cout<<"Shut Down"<<std::endl;
}

void Manager::Run()
{
    Init();
    m_cli.Run();
    ShutDown();
}