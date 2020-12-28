#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__


class ErrorInitDNASequence:public std::runtime_error
{
public:
    ErrorInitDNASequence(const std::string& s):runtime_error(s){};
};

class ErrorOpeningFile:public std::runtime_error
{
public:
    ErrorOpeningFile(const std::string& s):runtime_error(s){};
};

#endif
