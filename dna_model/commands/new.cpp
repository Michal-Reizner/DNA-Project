#include <sstream>
#include "new.h"
#include "../dna_collection.h"

//######################### Auxiliary functions ####################################

inline static std::string ConvertSize_tToString(size_t num)
{
    std::stringstream str;
    str << num;
    return str.str();
}

static std::string GetDefaultName(std::vector<std::string> params)
{
    static size_t counter = 0;
    std::string default_name = "seq" + ConvertSize_tToString(++counter);

    return default_name;
}

std::string CreateOutput(DNAData* dna)
{
    return "[" + ConvertSize_tToString(dna->GetId()) + "] " + dna->GetName() + ": " + dna->GetDNASeq();
}

//##################################################################################

New::New():ICMD()
{}

std::string New::Execute(std::vector<std::string> params_vec)
{
    if (params_vec.size() < 3)
    {
        params_vec.push_back(GetDefaultName(params_vec));
    }
    //std::cout<<"seq:   "<<params_vec[1]<<std::endl;
    DNAData* dna = new DNAData(GetID(),params_vec[2],params_vec[1]);
    //std::cout<<"seq:   "<<dna->GetDNASeq()<<std::endl;
    DNACollection::AddDNA(dna);

    return CreateOutput(dna);
}

