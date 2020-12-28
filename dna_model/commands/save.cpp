#include <fstream>
#include "save.h"
#include "../dna_collection.h"
#include "../dna_sequence/exceptions.h"


//######################### Auxiliary functions ####################################

static void SaveToFile(DNAData* dna, std::string file_name)
{
    std::ofstream dna_file;
    dna_file.open(file_name);

    if (!dna_file.is_open())
    {
        throw ErrorOpeningFile("Unable to open file");
    }

    dna_file << dna->GetDNASeq() + '\n';
    dna_file.close();
}

//##################################################################################

Save::Save():ICMD()
{}

std::string Save::Execute(std::vector<std::string> params_vec)
{
    if (params_vec.size() < 3)
    {
        params_vec.push_back(params_vec[1] + ".rawdna");
    }

    DNAData* dna = DNACollection::GetDNA(params_vec[1]);
    SaveToFile(dna, params_vec[2]);

    return  "";
}

