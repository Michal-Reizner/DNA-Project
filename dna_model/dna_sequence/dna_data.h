#ifndef __DNADATA_H__
#define __DNADATA_H__

#include "dnasequence.h"


class DNAData
{
public:
    DNAData(size_t, const std::string&, const std::string&);

    size_t GetId() const;
    std::string GetName()const ;
    std::string GetDNASeq() const;
private:
    size_t m_id;
    std::string m_name;
    DNASequence m_dna_sequence;
};


inline size_t DNAData::GetId() const
{
    return m_id;
}

inline std::string DNAData::GetName()const
{
    return m_name;
}

inline std::string DNAData::GetDNASeq() const
{
    return std::string(m_dna_sequence.get_DNAseq());
}
#endif








