#ifndef HDLR_H
#define HDLR_H

#include "atom.h"

class HDLR: public Atom
{
public:
    HDLR();
    ~HDLR();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    TRAK_TYPE getTrakType();
    virtual void writeAtom(StreamWriter& stream);
private:
    void isTypeTrak(std::string type);
    std::vector<uint8_t> m_data;
    TRAK_TYPE m_trakType;
};

#endif // HDLR_H
