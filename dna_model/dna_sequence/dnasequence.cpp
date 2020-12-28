#include <fstream>
#include "dnasequence.h"
#include "exceptions.h"


void DNASequence::Nucleotides::is_valid(const char &let)
{
    if((let!='A') & (let!='C') & (let!='G') & (let!='T') & (let!='\0'))
    {
        std::cout<<"#############3"<<std::endl;
        throw ErrorInitDNASequence("Invalid character");
    }
}

DNASequence::Nucleotides::Nucleotides(const char &let) {
    is_valid(let);
    m_let=let;
}

void DNASequence::Nucleotides::operator=(const char &let) {
    try {
        is_valid(let);
        m_let=let;
    }
    catch (ErrorInitDNASequence& e)
    {
        throw e;
    }
}

std::ostream& operator<<(std::ostream& os, const DNASequence::Nucleotides& let_to_print)
{
    os<<let_to_print.m_let;
    return os;
}

void DNASequence::my_strcpy(const char *seq)
{
    for (unsigned int i=0;i<strlen(seq);i++)
    {
        try {
            m_DNA_sequence[i]=seq[i];
        }
        catch(ErrorInitDNASequence& e)
        {
            std::cout<<"catch"<<std::endl;
            //delete[] m_DNA_sequence;
            throw e;
        }
    }
    m_DNA_sequence[length()]='\0';
}

DNASequence::DNASequence(const char *DNA_seq)
{
    if(DNA_seq==NULL)
        throw ErrorInitDNASequence("cannot be initialize with NULL");
    m_DNA_sequence=new Nucleotides[strlen(DNA_seq)+1];
    my_strcpy(DNA_seq);
}

DNASequence::DNASequence(const std::string& DNA_seq)
{
    m_DNA_sequence=new Nucleotides[DNA_seq.length()+1];
    my_strcpy(DNA_seq.c_str());
}

DNASequence::DNASequence(const DNASequence& DNA_to_insert)
{
    m_DNA_sequence=new Nucleotides[DNA_to_insert.length()+1];
    my_strcpy(DNA_to_insert.get_DNAseq());
}

DNASequence::~DNASequence()
{
    if(m_DNA_sequence!= NULL)
        delete[] m_DNA_sequence;
}

DNASequence& DNASequence::operator=(const DNASequence &DNA_to_insert)
{
    *this=DNA_to_insert.get_DNAseq();
    return *this;
}

DNASequence& DNASequence::operator=(const char* DNA_to_insert)
{
    if(strcmp(DNA_to_insert,get_DNAseq()))
    {
        if(DNA_to_insert==NULL)
            throw ErrorInitDNASequence("cannot be initialize with NULL");
        Nucleotides* tmp=new Nucleotides[strlen(DNA_to_insert)+1];
        delete[] m_DNA_sequence;
        m_DNA_sequence=tmp;
        my_strcpy(DNA_to_insert);
    }
    return *this;
}

DNASequence& DNASequence::operator=(const std::string& DNA_to_insert)
{
    *this=DNA_to_insert.c_str();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const DNASequence& DNA_to_print)
{
    os<<DNA_to_print.get_DNAseq();
    return os;
}

DNASequence::Nucleotides& DNASequence::operator[](const unsigned int index)
{
    if (index>=length())
        throw ErrorInitDNASequence("Invalid index");
    return m_DNA_sequence[index];
}

unsigned int DNASequence::length()const {
    int length = 0;
    int i = 0;
    while (m_DNA_sequence[i].get_let() != '\0') {
        length++;
        i++;
    }
    return length;
}

const char *DNASequence::get_DNAseq()const
{
    char *seq= new char[length()+1];
    unsigned int i=0;
    while (m_DNA_sequence[i].get_let()!='\0')
    {
        *(seq+i)=(m_DNA_sequence+i)->get_let();
        i++;
    }
    seq[i]='\0';
    return (const char *)seq;
}

void DNASequence::read_from_file(const char* filename)
{
    std::string dna_seq;
    std::ifstream dna_file(filename);
    if (dna_file.is_open())
    {
        getline(dna_file, dna_seq);
        dna_file.close();
        *this = dna_seq;
    }
    else
    {
        std::cout<<"Unable to open file";
    }
}

void DNASequence::write_to_file(const char *filename)
{
    std::ofstream thefile(filename);
    if(thefile.is_open())
    {
        thefile<<get_DNAseq();
        thefile.close();
        return;
    }
    throw ErrorOpeningFile("Cannot open file");
}

DNASequence DNASequence::slicing(unsigned int start, unsigned int end)
{
    char seq[end-start+1];
    for(unsigned int i=start;i<end;i++)
    {
        seq[i-start]=m_DNA_sequence[i];
    }
    seq[end-start]='\0';
    DNASequence dna(seq);
    return dna;
}

char change_let(char& c)
{
    switch(c)
    {
        case 'A':{c='T';break;}
        case 'T':{c='A';break;}
        case 'C':{c='G';break;}
        default:{c='C';break;}
    }
    return c;
}

char* DNASequence::pairing()
{
    char *seq=new char[length()+1];
    unsigned int j=0;
    for(unsigned int i=length()-1;i>=0;i--)
    {
        seq[j++]=change_let(m_DNA_sequence[i].get_let());
    }
    seq[j]='\0';
    return seq;
}



long int DNASequence::find(const char* sub_seq)
{
    unsigned int index=-1,flag=0;
    const char* dna_seq=get_DNAseq();
    for (unsigned int i=0;i<length();i++) {
        if (dna_seq[i] == sub_seq[0]) {
            flag = 1;
            index = i;
            for (unsigned int j = i + 1; j < i + strlen(sub_seq); j++) {
                if (dna_seq[j] != sub_seq[j - i]) {
                    index = -1;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                return index;
            }
        }
    }
    return -1;
}

std::vector<unsigned int> DNASequence::find_all(const char* sub_seq) {
    DNASequence tmp(*this);
    std::vector<unsigned int> index_vec;

    long int size = strlen(sub_seq);
    long int this_index =0, found_index;

    while (this_index < length()) {
        found_index = tmp.find(sub_seq);
        if (found_index == -1)
            return index_vec;
        index_vec.push_back((unsigned int)(found_index + this_index));
        tmp = tmp.slicing((unsigned int)(found_index+size), length());
        this_index += found_index+size ;
    }
    return index_vec;
}

std::vector<const char *> DNASequence::find_consensus_seq()
{
    std::vector<unsigned int> start_seq=find_all("ATG");
    std::vector<unsigned int> end_seqs=find_all("TAG");
    std::vector<unsigned int> TAA_seqs=find_all("TAA");
    std::vector<unsigned int> TGA_seqs=find_all("TGA");
    end_seqs.insert(end_seqs.end(),TAA_seqs.begin(),TAA_seqs.end());
    end_seqs.insert(end_seqs.end(),TGA_seqs.begin(),TGA_seqs.end());
    std::vector<const char *> res;
    for(std::vector<unsigned int>::iterator s_it=start_seq.begin();s_it!=start_seq.end(); s_it++)
    {
        for(std::vector<unsigned int>::iterator e_it=end_seqs.begin();e_it!=end_seqs.end();e_it++)
        {
            if((*e_it>*s_it) & (((*e_it-*s_it)%3)==0))
                res.push_back(slicing(*s_it,(*e_it)+3).get_DNAseq());
        }
    }
    return res;
}

long unsigned int DNASequence::count(const char* sub_seq)
{
    return find_all(sub_seq).size();
}












