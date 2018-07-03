#include "minf.h"
#include "../interfaces/callbackinterface.h"

using namespace std;

MINF::MINF():Atom(MINF_NAME, MINF_DIG_NAME)
{
    m_dinf = make_unique<DINF>();
    m_stbl = make_unique<STBL>();
    m_stbl->setCallback(this);
    m_trakType = TRAK_TYPE::VIDEO;
}

MINF::~MINF()
{

}

void MINF::setTrakType(TRAK_TYPE type)
{
    m_trakType = type;
}

void MINF::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV4);
    uint32_t pos = startPos;
    m_size = stream.readSizeAtom();
    pos = startPos+OFFSET_TITLE;
    stream.setPos(pos);
    if(m_trakType == TRAK_TYPE::VIDEO){
        m_vmhd = make_unique<VMHD>();
        m_vmhd->parse(stream,pos);
    } else if(m_trakType == TRAK_TYPE::AUDIO){
        m_smhd = make_unique<SMHD>();
        m_smhd->parse(stream,pos);
    }else{
        exit(100);
    }
    m_stbl->setTrakType(m_trakType);
    m_dinf->parse(stream,pos);
    m_stbl->parse(stream,pos);
    startPos += m_size;
}

std::pair<uint32_t, uint32_t> MINF::prepareData(uint32_t begTime, uint32_t endTime)
{
    return m_stbl->prepareData(begTime,endTime);
}

void MINF::writeAtom(StreamWriter &stream)
{
    stream.writeLitToBigEndian(m_size);
    stream.writeAtomName(MINF_NAME);
    if(m_trakType == TRAK_TYPE::VIDEO){
        m_vmhd->writeAtom(stream);
    } else if(m_trakType == TRAK_TYPE::AUDIO){
        m_smhd->writeAtom(stream);
    }
    m_dinf->writeAtom(stream);
    m_stbl->writeAtom(stream); /// TODO
}

void MINF::resizeAtom(uint32_t size, DIRECT_RESIZE direction)
{
    if(direction == DIRECT_RESIZE::INCREASED){
        this->m_size +=size;
    }else{
        this->m_size -=size;
    }
    m_callback->resizeAtom(size,direction);
}
