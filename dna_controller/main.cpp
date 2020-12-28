#include "manager.h"
#include "../dna_view/read_write/console_reader.h"
#include "../dna_view/read_write/console_writer.h"

int main()
{
    IReader* reader = new ConsoleReader;
    IWriter* writer = new ConsoleWriter;
    Manager manager(reader, writer);
    manager.Run();
//    DNASequence dnaSequence("AATCATAT");
//    const char *sub_seq = "AT";
//
//    std::cout<<dnaSequence.find_all(sub_seq)[2]<<std::endl;

    return 1;
}




