#ifndef MDHD_H
#define MDHD_H
#include "atom.h"

class MDHD : public Atom
{
public:
    MDHD();
    ~MDHD();

    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void setNewDuration(uint32_t time);
    virtual void writeAtom(StreamWriter& stream);
private:
    uint32_t m_timeScale;
    uint32_t m_duration;
    uint32_t m_verFlag;
    uint32_t m_language;
    uint32_t m_creationTime;
    uint32_t m_modificationTime;
};

#endif // MDHD_H
