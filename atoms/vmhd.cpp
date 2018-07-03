#include "vmhd.h"

VMHD::VMHD():Atom(VMHD_NAME, VMHD_DIG_NAME)
{

}

VMHD::~VMHD()
{

}

void VMHD::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV5);
    m_size = stream.readSizeAtom();
    m_data.resize(m_size,0);
    stream.read(&( m_data[ 0 ]),m_size);
    startPos +=m_size;
}

void VMHD::writeAtom(StreamWriter &stream)
{
    stream.write(&( m_data[ 0 ]),m_size);
}
