#include "smhd.h"

SMHD::SMHD():Atom(SMHD_NAME, SMHD_DIG_NAME)
{

}

SMHD::~SMHD()
{

}

void SMHD::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV5);
    m_size = stream.readSizeAtom();
    m_data.resize(m_size,0);
    stream.read(&( m_data[ 0 ]),m_size);
    startPos +=m_size;
}

void SMHD::writeAtom(StreamWriter &stream)
{
    stream.write(&( m_data[ 0 ]),m_size);
}
