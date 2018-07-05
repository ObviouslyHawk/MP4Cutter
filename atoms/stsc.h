#ifndef STSC_H
#define STSC_H

#include "atom.h"
class STSZ;
class STSC:public Atom
{
public:
    STSC();
    ~STSC();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void prepareDataForWrite(uint32_t begTime, uint32_t endTime, TRAK_TYPE type=TRAK_TYPE::VIDEO);
    void prepareDataForWriteAudio(const STSZ& stsz, uint32_t begTime, uint32_t endTime, uint32_t delta,TRAK_TYPE type=TRAK_TYPE::VIDEO);
    virtual void writeAtom(StreamWriter& stream);
protected:
    virtual void resizeAtom(uint32_t size, DIRECT_RESIZE direction);

private:
    uint32_t m_verFlag{0};
    uint32_t m_amount{0};
    std::vector<StscData> m_data;
};

#endif // STSC_H
