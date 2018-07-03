#include "hdlr.h"

HDLR::HDLR():Atom(HDLR_NAME, HDLR_DIG_NAME)
{

}

HDLR::~HDLR()
{

}

void HDLR::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV4);
    uint32_t pos = startPos;
    m_size = stream.readSizeAtom();
    m_data.resize(m_size,0);
    stream.read(&(m_data[0]),m_data.size());
    char tempArray[4];
    std::copy((m_data.begin() + 16),(m_data.begin()+20),tempArray);
    isTypeTrak(std::string(tempArray,4));
    startPos += m_size;
}

TRAK_TYPE HDLR::getTrakType()
{
    return m_trakType;
}

void HDLR::writeAtom(StreamWriter &stream)
{
    stream.write(&( m_data[ 0 ]),m_size);
}

void HDLR::isTypeTrak(std::string type)
{
    if(type == VIDE){
        m_trakType = TRAK_TYPE::VIDEO;
    }else if(type == SOUN){
        m_trakType = TRAK_TYPE::AUDIO;
    }else{
        m_trakType = TRAK_TYPE::HINT;
    }
}
