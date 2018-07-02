#include "streamreader.h"

using namespace std;

StreamReader::StreamReader(std::string filePath):m_filePath(filePath)
{
}

StreamReader::~StreamReader()
{
    closeStream();
}

bool StreamReader::openStream()
{
    if(m_filePath.empty())
        return false;
    m_file.open(m_filePath, ios_base::in | ios_base::binary);
    if(m_file.is_open()){
        m_file.seekg(0,ios_base::end);
        m_endnpos = m_file.tellg();
        m_file.seekg(0,ios_base::beg);
    }
    return m_file.is_open();
}

void StreamReader::closeStream()
{
    if(m_file.is_open())
        m_file.close();
}

void StreamReader::read(uint8_t *buf, uint64_t length)
{
    m_file.read( reinterpret_cast< char * >( buf ), static_cast< std::streamsize >( length ) );
}

uint8_t StreamReader::readUInt8()
{
    uint8_t n;
    n = 0;
    read( reinterpret_cast< uint8_t * >( &n ), 1 );
    return n;
}

string StreamReader::getTitleAtom()
{
    streamsize offset = m_file.tellg();// + 4;
    m_file.seekg( (offset+4), ios_base::beg );
    string rezult = getDataInAtom();
    m_file.seekg( offset, ios_base::beg );
    return rezult;
}

string StreamReader::getDataInAtom()
{
    std::ifstream::pos_type cur;
    cur = m_file.tellg();
    string title = std::string(4, ' ' );
    m_file.seekg( cur, ios_base::beg );
    read( reinterpret_cast< uint8_t * >( &( title[ 0 ] ) ), 4 );
    m_file.seekg( cur, ios_base::beg );
    return title;
}

uint32_t StreamReader::readUInt32()
{
    uint32_t n;
    n = 0;
    read( reinterpret_cast< uint8_t * >( &n ), 4 );
    return n;
}

uint32_t StreamReader::readBigEndianUInt32()
{
    uint8_t  c[ 4 ];
    uint32_t n;
    uint32_t n1;
    uint32_t n2;
    uint32_t n3;
    uint32_t n4;

    c[ 0 ] = 0;
    c[ 1 ] = 0;
    c[ 2 ] = 0;
    c[ 3 ] = 0;

    read( reinterpret_cast< uint8_t * >( c ), 4 );

    n1 = static_cast< uint32_t >( c[ 0 ] );
    n2 = static_cast< uint32_t >( c[ 1 ] );
    n3 = static_cast< uint32_t >( c[ 2 ] );
    n4 = static_cast< uint32_t >( c[ 3 ] );

    n  = static_cast< uint32_t >( n1 << 24 )
            | static_cast< uint32_t >( n2 << 16 )
            | static_cast< uint32_t >( n3 << 8 )
            | n4;

    return n;
}

uint32_t StreamReader::readSizeAtom()
{
    std::ifstream::pos_type cur;

    cur = m_file.tellg();
    uint32_t chunkSize = readBigEndianUInt32();
    m_file.seekg( cur, ios_base::beg );
    return chunkSize;
}

void StreamReader::getBlock(uint8_t *buf, uint64_t pos, uint64_t length)
{
    std::ifstream::pos_type cur;

    cur = m_file.tellg();

    m_file.seekg( static_cast< std::ifstream::off_type >( pos ), ios_base::beg );
    m_file.read( reinterpret_cast< char * >( buf ), static_cast< std::streamsize >( length ) );
    m_file.seekg( cur, ios_base::beg );
}

streamsize StreamReader::getPose()
{
    return m_file.tellg();
}

void StreamReader::setPos(streamsize pos)
{
    m_file.seekg(pos,ios_base::beg);
}

streamsize StreamReader::getFileSize()
{
    return m_endnpos;
}
