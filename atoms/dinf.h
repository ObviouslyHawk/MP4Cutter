#ifndef DINF_H
#define DINF_H
#include "atom.h"

class DINF:public Atom
{
public:
    DINF();
    ~DINF();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    virtual void writeAtom(StreamWriter& stream);
private:
    std::vector<uint8_t> m_data;
};

#endif // DINF_H
