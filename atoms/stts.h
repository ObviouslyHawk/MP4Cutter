#ifndef STTS_H
#define STTS_H
#include "atom.h"
#include <vector>

class STTS: public Atom
{
public:
    STTS();
    ~STTS();
    virtual void parse(StreamReader& stream, uint32_t& startPos);
    void prepareDataForWrite(uint32_t begTime, uint32_t endTime, TRAK_TYPE type=TRAK_TYPE::VIDEO);
    uint32_t newAmountChunk() const;
    virtual void writeAtom(StreamWriter& stream);
protected:
    virtual void resizeAtom(uint32_t size, DIRECT_RESIZE direction);

private:
    uint32_t m_verFlag{0};
    uint32_t m_amount{0};
    std::vector<SttsData> m_data;

    uint32_t m_newAmountChunk{0}; // пока 1, потом переделать на вектор
};

#endif // STTS_H
