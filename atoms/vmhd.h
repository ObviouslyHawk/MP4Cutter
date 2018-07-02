#ifndef VMHD_H
#define VMHD_H

#include "atom.h"

class VMHD: public Atom
{
public:
    VMHD();
    ~VMHD();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    virtual void writeAtom(StreamWriter& stream);
private:
    std::vector<uint8_t> m_data;
};

#endif // VMHD_H
