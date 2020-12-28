#ifndef __DNACOLLECTION_H__
#define __DNACOLLECTION_H__

#include <map>
#include "dna_sequence/dna_data.h"


class DNACollection
{
public:
    static DNAData* GetDNA(size_t id);
    static DNAData* GetDNA(std::string name);
    static void AddDNA(DNAData* dna);
private:
    static std::map<size_t ,std::string > m_map_id_name;
    static std::map<std::string  , DNAData*> m_map_name_dna;
};

inline DNAData* DNACollection::GetDNA(std::string name)
{
    return m_map_name_dna[name];
}

inline DNAData* DNACollection::GetDNA(size_t id)
{
    return m_map_name_dna[m_map_id_name[id]];
}


#endif