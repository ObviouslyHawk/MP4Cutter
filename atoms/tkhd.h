#ifndef TKHD_H
#define TKHD_H

#include "atom.h"

class TKHD:public Atom
{
public:
    TKHD();
    ~TKHD();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void setNewDuration(uint32_t time);
    void writeAtom(StreamWriter& stream);
private:
    std::vector<uint8_t> m_data;
    uint32_t m_duration;
    uint32_t m_verFlag;
    uint32_t m_reserved{0}; // не трогать
    uint32_t m_creationTime;
    uint32_t m_modificationTime;
    uint32_t m_trackID;
};

#endif // TKHD_H
