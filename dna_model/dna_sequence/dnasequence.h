#ifndef __DNA_SEQUENCE__H
#define __DNA_SEQUENCE__H

#include <vector>
#include <cstring>
#include <iostream>



class DNASequence
{
private:
    void my_strcpy(const char*);
    class Nucleotides
    {
    public:
        Nucleotides(){};
        Nucleotides(const char&);
        void operator=(const char&);
        operator char(){ return m_let;};
        char& get_let();
        friend std::ostream& operator<<(std::ostream& os, const Nucleotides& let_to_print);
    private:
        void is_valid(const char &let);

        char m_let;
    };

    Nucleotides *m_DNA_sequence;

public:
    explicit DNASequence(const char *);
    explicit DNASequence(const std::string&);
    DNASequence(const DNASequence&);
    ~DNASequence();
    DNASequence& operator=(const DNASequence&);
    DNASequence& operator=(const char*);
    DNASequence& operator=(const std::string&);
    unsigned int length()const;
    const char *get_DNAseq()const ;
    void read_from_file(const char*);
    void write_to_file(const char *);
    DNASequence slicing(unsigned int start,unsigned int end);
    long int find(const char* sub_seq);
    std::vector<unsigned int> find_all(const char* sub_seq);
    std::vector<const char *> find_consensus_seq();
    char* pairing();
    long unsigned int count(const char* sub_seq);
    Nucleotides& operator[](const unsigned int index);
    friend std::ostream& operator<<(std::ostream& os, const DNASequence& DNA_to_print);
    friend std::ostream& operator<<(std::ostream& os, const Nucleotides& let_to_print);
};


inline bool operator==(const DNASequence& DNA1,const DNASequence& DNA2)
{
    return !(strcmp(DNA1.get_DNAseq(),DNA2.get_DNAseq()));
}

inline bool operator!=(const DNASequence& DNA1,const DNASequence& DNA2)
{
    return strcmp(DNA1.get_DNAseq(),DNA2.get_DNAseq());
}

inline char& DNASequence::Nucleotides::get_let() {
    return m_let;
}


#endif