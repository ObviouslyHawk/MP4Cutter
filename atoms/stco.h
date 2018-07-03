#ifndef STCO_H
#define STCO_H
#include "atom.h"

class STCO:public Atom
{
public:
    STCO();
    ~STCO();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void prepareDataForWrite(uint32_t begTime, uint32_t endTime, uint32_t delta,TRAK_TYPE type=TRAK_TYPE::VIDEO);
    std::pair<uint32_t,uint32_t> getOldOffset() const;
    virtual void writeAtom(StreamWriter& stream);
protected:
    virtual void resizeAtom(uint32_t size, DIRECT_RESIZE direction);

private:
    std::vector<uint32_t> m_chunkOffset;
    uint32_t m_verFlag{0};
    uint32_t m_amountChunk{0};

    uint32_t m_startCutOffset{0};
    uint32_t m_endCutOffset{0};
};

#endif // STCO_H
