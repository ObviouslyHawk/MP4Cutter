#include "mdia.h"
#include "../interfaces/callbackinterface.h"

using namespace std;

MDIA::MDIA():Atom(MDIA_NAME, MDIA_DIG_NAME)
{
    m_mdhd = make_unique<MDHD>();
    m_hdlr = make_unique<HDLR>();
    m_minf = make_unique<MINF>();
    m_minf->setCallback(this);
}

MDIA::~MDIA()
{

}

void MDIA::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV3);
    uint32_t pos = startPos;
    m_size = stream.readSizeAtom();
    pos = startPos+OFFSET_TITLE;
    stream.setPos(pos);
    m_mdhd->parse(stream,pos);
    m_hdlr->parse(stream,pos);
    m_minf->setTrakType(m_hdlr->getTrakType());
    m_minf->parse(stream,pos);
    startPos += m_size;
}

TRAK_TYPE MDIA::getTrakType()
{
    return m_hdlr->getTrakType();
}

std::pair<uint32_t, uint32_t> MDIA::prepareData(uint32_t begTime, uint32_t endTime)
{
    m_mdhd->setNewDuration(endTime-begTime);
    return m_minf->prepareData(begTime,endTime);
}

void MDIA::writeAtom(StreamWriter &stream)
{
    stream.writeLitToBigEndian(m_size);
    stream.writeAtomName(MDIA_NAME);
    m_mdhd->writeAtom(stream);
    m_hdlr->writeAtom(stream);
    m_minf->writeAtom(stream);
}

void MDIA::resizeAtom(uint32_t size, DIRECT_RESIZE direction)
{
    if(direction == DIRECT_RESIZE::INCREASED){
        this->m_size +=size;
    }else{
        this->m_size -=size;
    }
    m_callback->resizeAtom(size,direction);
}
