#include "stsc.h"
#include "stsz.h"
#include <math.h>

STSC::STSC():Atom(STSC_NAME, STSC_DIG_NAME)
{
	
}

STSC::~STSC()
{

}

void STSC::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV6);
    m_size = stream.readSizeAtom();
    uint32_t pos = startPos+OFFSET_TITLE;
    stream.setPos(pos);
    m_verFlag = stream.readUInt32();
    m_amount = stream.readBigEndianUInt32();
    m_data.resize(m_amount);
    for(int i=0;i<m_amount;i++){
        m_data[i].m_firstChunk=stream.readBigEndianUInt32();
        m_data[i].m_samplesPerChunk=stream.readBigEndianUInt32();
        m_data[i].m_samplesIndex=stream.readBigEndianUInt32();
    }
    startPos +=m_size;
}

void STSC::prepareDataForWrite(uint32_t begTime, uint32_t endTime, TRAK_TYPE type)
{
    uint32_t amountTime= endTime - begTime;
    if(type == TRAK_TYPE::VIDEO){
    }else{

    }
}

void STSC::prepareDataForWriteAudio(const STSZ &stsz, uint32_t begTime, uint32_t endTime, uint32_t delta, TRAK_TYPE type)
{
    std::pair<uint32_t,uint32_t> startPos = stsz.getOffsetsStartPos();
    std::pair<uint32_t,uint32_t> endPos = stsz.getOffsetsEndPos();
    int32_t size = m_data.size();
    if(startPos.first!=0){
        StscData oldData = m_data[0];
        m_data[0].m_firstChunk=1;
        m_data[0].m_samplesPerChunk= 4 - startPos.first;
        m_data[0].m_samplesIndex=1;
        oldData.m_firstChunk = 1;
        oldData.m_samplesPerChunk = 4;
        oldData.m_samplesIndex = 1;
        m_data.push_back(oldData);
    }
    if(endPos.first!=3){
        StscData data;
        data.m_firstChunk = 1;
        data.m_samplesPerChunk = startPos.first+1;
        data.m_samplesIndex = 1;
        m_data.push_back(data);
    }
    int32_t resize = size - m_data.size();
    if(resize == 0)
        return;
    uint32_t atomResize = (abs(size)*3*4);
    if(resize<0){
        m_size += atomResize;
        resizeAtom(atomResize,DIRECT_RESIZE::INCREASED);
    }else{
        m_size -=atomResize;
        resizeAtom(atomResize,DIRECT_RESIZE::DECREASED);
    }

}

void STSC::writeAtom(StreamWriter &stream)
{
    stream.writeLitToBigEndian(m_size);
    stream.writeAtomName(STSC_NAME);
    stream.writeUInt32(m_verFlag);
    stream.writeLitToBigEndian(m_amount);
    for(int i=0;i<m_amount;i++){
        stream.writeLitToBigEndian( m_data[i].m_firstChunk);
        stream.writeLitToBigEndian( m_data[i].m_samplesPerChunk);
        stream.writeLitToBigEndian(m_data[i].m_samplesIndex);
    }
}

void STSC::resizeAtom(uint32_t size, DIRECT_RESIZE direction)
{
    callback()->resizeAtom(size,direction);
}

