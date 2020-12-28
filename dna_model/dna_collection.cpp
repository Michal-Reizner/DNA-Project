#include "dna_collection.h"


std::map<size_t ,std::string > DNACollection::m_map_id_name;
std::map<std::string , DNAData*> DNACollection::m_map_name_dna;

void DNACollection::AddDNA(DNAData* dna)
{
    m_map_id_name[dna->GetId()]= dna->GetName();
    m_map_name_dna[dna->GetName()] = dna;
}








