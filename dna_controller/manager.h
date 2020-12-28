#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>
#include "../dna_view/cli.h"
#include "../dna_model/dna_collection.h"


class Manager
{
public:
    Manager(IReader*, IWriter*);
    ~Manager();
    void Init();
    void ShutDown();
    void Run();
private:
    CLI m_cli;
    DNACollection m_dnaCollection;
    static CMDCollection m_cmdCollection;
};






#endif