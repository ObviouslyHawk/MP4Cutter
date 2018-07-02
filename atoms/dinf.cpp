#include "dinf.h"

DINF::DINF():Atom()
{
    setAtomTextName(DINF_NAME);
    setAtomDigitName(DINF_DIG_NAME);
}

DINF::~DINF()
{

}

void DINF::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV5);
    m_size = stream.readSizeAtom();
    m_data.resize(m_size,0);
    stream.read(&( m_data[ 0 ]),m_size);
    startPos +=m_size;
}

void DINF::writeAtom(StreamWriter &stream)
{
    stream.write(&(m_data[ 0 ]),m_size);
}
