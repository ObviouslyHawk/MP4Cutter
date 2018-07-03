#include "ftyp.h"

using namespace std;

FTYP::FTYP():Atom(FTYP_NAME, FTYP_DIG_NAME)
{

}

FTYP::~FTYP()
{

}

void FTYP::parse(StreamReader &stream, uint32_t &startPos)
{
    printAtomName(LV1);
    m_size = stream.readSizeAtom();
    m_data.resize(m_size,0);
    stream.read(&( m_data[ 0 ]),m_size);
    startPos +=m_size;
}

void FTYP::writeAtom(StreamWriter &stream)
{
    //stream.writeLitToBigEndian(m_size);
    //stream.writeAtomName(atomTextName());
    stream.write(&( m_data[ 0 ]),m_size);
}
