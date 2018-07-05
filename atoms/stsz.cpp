#include "stsz.h"
#include <math.h>

STSZ::STSZ():Atom(STSZ_NAME, STSZ_DIG_NAME)
{

}

STSZ::~STSZ()
{

}

void STSZ::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV6);
    m_size = stream.readSizeAtom();
    uint32_t pos = startPos+OFFSET_TITLE;
    stream.setPos(pos);
    m_verFlag = stream.readUInt32();
    m_sempleSize = stream.readBigEndianUInt32();
    m_amountChunk = stream.readBigEndianUInt32();
    m_chunkSize.resize(m_amountChunk,0);
    for(auto i=0;i<m_amountChunk;i++){
        m_chunkSize[i]=stream.readBigEndianUInt32();
    }
    startPos +=m_size;
}

void STSZ::writeAtom(StreamWriter &stream)
{
    stream.writeLitToBigEndian(m_size);
    stream.writeAtomName(STSZ_NAME);
    stream.writeUInt32(m_verFlag);
    stream.writeLitToBigEndian(m_sempleSize);
    stream.writeLitToBigEndian(m_chunkSize.size());
    for(int i=0;i<m_chunkSize.size();i++){
        stream.writeLitToBigEndian(m_chunkSize[i]);
    }
}

void STSZ::prepareDataForWrite(uint32_t begTime, uint32_t endTime, uint32_t delta, TRAK_TYPE type)
{
    //uint32_t amountTime= endTime - begTime;
    if(type == TRAK_TYPE::VIDEO){
        uint32_t endPos = endTime*delta; /// TODO: Передать delta
        uint32_t countResize = m_chunkSize.size() - endPos + begTime; ///?????
        if(endPos != (m_chunkSize.size()-1)){
            m_chunkSize.erase(m_chunkSize.begin()+endPos,m_chunkSize.end());
        }
        if(begTime != 0){
            m_chunkSize.erase(m_chunkSize.begin(),m_chunkSize.begin()+begTime);
        }
        uint32_t resizeAmount =countResize*BYTE32;
        m_size -=resizeAmount;
        resizeAtom(resizeAmount,DIRECT_RESIZE::DECREASED);
    }else{
        /// TODO: Debug
        float endIntPart;
        float startIntPart;

        float fractStartPos = modf(((begTime * 16000.0)/delta)/4.0f,&startIntPart);
        float fractEndPos = modf(((endTime * 16000.0)/delta)/4.0f,&endIntPart);
        m_offsetStartPos = getOffsetAudioChunk(fractStartPos);
        m_offsetEndPos = getOffsetAudioChunk(fractEndPos);
        modf(((begTime * 16000.0)/delta),&startIntPart);
        modf(((endTime * 16000.0)/delta),&endIntPart);
        uint32_t startPos = static_cast<uint32_t>(startIntPart); // - m_offsetStartPos;
        uint32_t endPos = static_cast<uint32_t>(endIntPart); // - m_offsetEndPos;

        if(m_offsetStartPos != 0){
            for(int i = startPos-m_offsetStartPos; i<startPos;i++){
                m_offsetStartSize += m_chunkSize[i];
            }
        }

        if(m_offsetEndPos != 0){
            for(int i = endPos- m_offsetEndPos; i<endPos;i++){
                m_offsetEndSize += m_chunkSize[i];
            }
        }

        uint32_t countResize = m_chunkSize.size();// - endPos + startPos; ///????? endPos +-1
        if(endPos != (m_chunkSize.size()-1)){
            m_chunkSize.erase(m_chunkSize.begin()+endPos,m_chunkSize.end());
        }
        if(begTime != 0){
            m_chunkSize.erase(m_chunkSize.begin(),m_chunkSize.begin()+startPos-1); ///????? startPos +-1
        }
        uint32_t resizeAmount = (countResize-m_chunkSize.size())*BYTE32;
        m_size -=resizeAmount;
        resizeAtom(resizeAmount,DIRECT_RESIZE::DECREASED);
    }
}

uint32_t STSZ::getAmountChunks() const
{
    return m_chunkSize.size();
}

uint32_t STSZ::getEndChunkSize() const
{
    return m_chunkSize[m_chunkSize.size()-1];
}

std::pair<uint32_t,uint32_t> STSZ::getOffsetsStartPos() const
{
    return std::pair<uint32_t, uint32_t>(m_offsetStartPos,m_offsetStartSize);
}

std::pair<uint32_t,uint32_t> STSZ::getOffsetsEndPos() const
{
    return std::pair<uint32_t,uint32_t>(m_offsetEndPos,m_offsetEndSize);
}

void STSZ::resizeAtom(uint32_t size, DIRECT_RESIZE direction)
{
    callback()->resizeAtom(size,direction);
}

uint32_t STSZ::getOffsetAudioChunk(float fractPos)
{
    if((fractPos>=0)&&(fractPos<0.25f)){
        return 0;
    }
    else if((fractPos>=0.25f)&&(fractPos<0.5f)){
        return 1;
    }else if((fractPos>=0.5f)&&(fractPos<0.75f)){
        return 2;
    }else{
        return 3;
    }
}
