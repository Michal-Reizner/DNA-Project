#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include "Ireader.h"


class FileReader
{
public:
    /*virtual*/std::string Read();
};


inline std::string FileReader::Read()//TODO: how to read lines from the file, when to close the file...
{
//    std::string output;
//    if (file_name.is_open())
//    {
//        getline(dna_file, output);
//        dna_file.close();
//
//        DNAData* dna = new DNAData(GetID(),params_vec[2],dna_seq);
//        DNACollection::AddDNA(dna);
//        output = CreateInput(dna);
//    }
//    else
//    {
//        output = "Unable to open file";
//    }
}
#endif