#ifndef STRAMREADER_H
#define STRAMREADER_H

#include <fstream>
#include <iostream>
#include <vector>

class StreamReader
{
public:
    StreamReader(std::string filePath);
    ~StreamReader();
    bool openStream();
    void closeStream();

    uint8_t readUInt8( void );
    std::string getTitleAtom();
    std::string getDataInAtom();
    uint32_t readUInt32( void );
    uint32_t readBigEndianUInt32( void );
    uint32_t readSizeAtom( void );
    void getBlock( uint8_t * buf, uint64_t pos, uint64_t length );
    std::streamsize getPose();
    void setPos(std::streamsize pos);
    std::streamsize getFileSize();
    void read( uint8_t * buf, uint64_t length );


private:

    std::ifstream m_file;
    std::streamsize m_beginpos{0};
    std::streamsize m_currentpos{0};
    std::streamsize m_endnpos{0};
    std::string m_filePath;
};

#endif // STRAMREADER_H
