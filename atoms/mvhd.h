#ifndef MVHD_H
#define MVHD_H
#include "atom.h"

class MVHD:public Atom
{
public:
    MVHD();
    ~MVHD();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void setNewDuration(uint32_t time);
    void setNextTrakID(uint32_t id);
    virtual void writeAtom(StreamWriter& stream);
private:
    std::vector<uint8_t> m_data;
    uint32_t m_timeScale;
    uint32_t m_duration;
    uint32_t m_verFlag;
    uint32_t m_creationTime;
    uint32_t m_modificationTime;
    uint32_t m_nextTrackID;
};

#endif // MVHD_H
