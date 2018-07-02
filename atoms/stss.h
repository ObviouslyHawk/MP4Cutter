#ifndef STSS_H
#define STSS_H
#include "atom.h"
#include <vector>

class STSS:public Atom
{
public:
    STSS();
    ~STSS();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void prepareDataForWrite(uint32_t begTime, uint32_t endTime, TRAK_TYPE type=TRAK_TYPE::VIDEO);
    uint32_t startCutPos() const;
    virtual void writeAtom(StreamWriter& stream);
protected:
    virtual void resizeAtom(uint32_t size, DIRECT_RESIZE direction);


private:
    std::vector<uint32_t> m_offsetIFrame;
    uint32_t m_verFlag{0};
    uint32_t m_amountChunk{0};
    uint32_t m_startCutPos{0};
};

#endif // STSS_H
