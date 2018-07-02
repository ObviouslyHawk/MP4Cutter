#include "streamwriter.h"
#include "endians.h"

using namespace std;
StreamWriter::StreamWriter(std::string fileName):m_filePath(fileName)
{

}

StreamWriter::~StreamWriter()
{
    closeStream();
}

bool StreamWriter::openStream()
{
    if(m_filePath.empty())
        return false;
    m_file.open(m_filePath, ios_base::out | ios_base::binary);
    return m_file.is_open();
}

void StreamWriter::closeStream()
{
    if(m_file.is_open())
        m_file.close();
}

void StreamWriter::writeAtomSize(uint32_t size)
{
    write(reinterpret_cast< uint8_t * >(&(size)),sizeof(size));
}

void StreamWriter::writeAtomName(uint32_t name)
{
    write(reinterpret_cast< uint8_t * >(&(name)),sizeof(name));
}

void StreamWriter::writeAtomName(string name)
{
    write(reinterpret_cast< uint8_t * >(const_cast<char*>(name.c_str())),4);
}

void StreamWriter::writeUInt32(uint32_t data)
{
    write(reinterpret_cast< uint8_t * >(&(data)),sizeof(data));
}

void StreamWriter::writeLitToBigEndian(uint32_t data)
{
    data = swapEndian(data);
    write(reinterpret_cast< uint8_t * >(&(data)),sizeof(data));
}

void StreamWriter::write(uint8_t *buf, uint64_t length)
{
    m_file.write(reinterpret_cast< char * >( buf ), static_cast< std::streamsize >( length ));
}
