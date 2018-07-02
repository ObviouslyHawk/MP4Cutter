#ifndef SMHD_H
#define SMHD_H

#include "atom.h"

class SMHD:public Atom
{
public:
    SMHD();
    ~SMHD();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    virtual void writeAtom(StreamWriter& stream);
private:
    std::vector<uint8_t> m_data;
};

#endif // SMHD_H
