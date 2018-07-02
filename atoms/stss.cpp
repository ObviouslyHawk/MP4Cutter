#include "stss.h"

STSS::STSS():Atom()
{
    setAtomTextName(STSS_NAME);
    setAtomDigitName(STSS_DIG_NAME);
}

STSS::~STSS()
{

}

void STSS::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV6);
    m_size = stream.readSizeAtom();
    uint32_t pos = startPos+OFFSET_TITLE;
    stream.setPos(pos);
    m_verFlag = stream.readUInt32();
    m_amountChunk = stream.readBigEndianUInt32();
    m_offsetIFrame.resize(m_amountChunk,0);
    for(auto i=0;i<m_amountChunk;i++){
        m_offsetIFrame[i]=stream.readBigEndianUInt32();
    }
    startPos +=m_size;
}

void STSS::prepareDataForWrite(uint32_t begTime, uint32_t endTime, TRAK_TYPE type)
{
    //uint32_t amountTime= endTime - begTime;
    if(type == TRAK_TYPE::VIDEO){
        uint32_t start = begTime*24; /// TODO: Передать delta
        uint32_t finish = endTime*24;
        uint32_t startPos, endPos;
        uint32_t countResize{0};
        for(uint32_t i=0;i<m_offsetIFrame.size();i++){
            if(start<m_offsetIFrame[i]){
                startPos = i-1;
                break;
            }
            if(start == m_offsetIFrame[i]){
                startPos = i;
                break;
            }
        }

        for(uint32_t i=startPos;i<m_offsetIFrame.size();i++){
            if(finish<m_offsetIFrame[i]){
                endPos = i;//-1;
                break;
            }
            if(finish == m_offsetIFrame[i]){
                endPos = i;
                break;
            }
        }

        m_startCutPos = m_offsetIFrame[startPos]-1;//-1;
        countResize = m_offsetIFrame.size() - endPos + startPos;
        if(endPos != (m_offsetIFrame.size()-1)){
            m_offsetIFrame.erase(m_offsetIFrame.begin()+(endPos-startPos),m_offsetIFrame.end());
        }

        uint32_t resizeAmount = countResize*BYTE32;
        m_size -=resizeAmount;
        resizeAtom(resizeAmount,DIRECT_RESIZE::DECREASED);

    }else{

    }
}

void STSS::resizeAtom(uint32_t size, DIRECT_RESIZE direction)
{
    callback()->resizeAtom(size,direction);
}

uint32_t STSS::startCutPos() const
{
    return m_startCutPos;
}

void STSS::writeAtom(StreamWriter &stream)
{
    stream.writeLitToBigEndian(m_size);
    stream.writeAtomName(STSS_NAME);
    stream.writeUInt32(m_verFlag);
    stream.writeLitToBigEndian(m_offsetIFrame.size());
    for(int i=0;i<m_offsetIFrame.size();i++){
        stream.writeLitToBigEndian( m_offsetIFrame[i]);
    }
}