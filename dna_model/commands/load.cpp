#include <sstream>
#include <fstream>
#include "load.h"
#include "../dna_collection.h"
#include "../dna_sequence/exceptions.h"


//######################### Auxiliary functions ####################################

inline static std::string ConvertSize_tToString(size_t num)
{
    std::stringstream str;
    str << num;

    return str.str();
}

inline static std::string GetBaseFileName(std::string file_name)
{
    size_t pos = file_name.find(".");

    return file_name.substr(0,pos);
}

static std::string GetDefaultFileName(std::vector<std::string> params)
{
    static size_t counter = 0;
    std::string default_file_name = GetBaseFileName(params[1]) + ConvertSize_tToString(++counter);

    return default_file_name;
}

static std::string LoadFromFile(std::string file_name)
{
    std::string dna_seq;
    std::ifstream dna_file(file_name);

    if (!dna_file.is_open())
    {
       throw ErrorOpeningFile("Unable to open file");

    }

    getline(dna_file, dna_seq);
    dna_file.close();

    return dna_seq;
}

inline static std::string GetShortDnaSeq(DNAData* dna)
{
    return dna->GetDNASeq().substr(0,32) + "..." + dna->GetDNASeq().substr(dna->GetDNASeq().size()-3,3);
}

inline static std::string CreateOutput(DNAData* dna)
{
    std::string dna_to_print = (dna->GetDNASeq().size() <= 40) ? dna->GetDNASeq() : GetShortDnaSeq(dna);

    return "[" + ConvertSize_tToString(dna->GetId()) + "] " + dna->GetName() + ": " + dna_to_print;
}
//##################################################################################

Load::Load():ICMD()
{}

std::string Load::Execute(std::vector<std::string> params_vec) {
    if (params_vec.size() < 3) {
        params_vec.push_back(GetDefaultFileName(params_vec));
    }
    std::string dna_seq = LoadFromFile(params_vec[1]);

    DNAData *dna = new DNAData(GetID(), params_vec[2], dna_seq);
    DNACollection::AddDNA(dna);

    return CreateOutput(dna);
}








