#include "stsd.h"

STSD::STSD():Atom()
{
    setAtomTextName(STSD_NAME);
    setAtomDigitName(STSD_DIG_NAME);
}

STSD::~STSD()
{

}

void STSD::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV6);
    m_size = stream.readSizeAtom();
    m_data.resize(m_size,0);
    stream.read(&( m_data[ 0 ]),m_size);
    startPos +=m_size;
}

void STSD::writeAtom(StreamWriter &stream)
{
    stream.write(&( m_data[ 0 ]),m_size);
}
