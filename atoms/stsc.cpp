#include "stsc.h"

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

}

