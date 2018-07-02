#ifndef FTYP_H
#define FTYP_H

#include "atom.h"
class FTYP:public Atom
{
public:
    FTYP();
    ~FTYP();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void writeAtom(StreamWriter& stream);
private:
    std::vector<uint8_t> m_data;

};

#endif // FTYP_H
