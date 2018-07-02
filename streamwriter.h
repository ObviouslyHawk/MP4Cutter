#ifndef STREAMWRITER_H
#define STREAMWRITER_H
#include <fstream>
#include <iostream>

class StreamWriter
{
public:
    StreamWriter(std::string fileName);
    ~StreamWriter();
    bool openStream();
    void closeStream();

    void writeAtomSize(uint32_t size);
    void writeAtomName(uint32_t name);
    void writeAtomName(std::string name);
    void writeUInt32(uint32_t data);
    void writeLitToBigEndian(uint32_t data);
    void write(uint8_t * buf, uint64_t length);


private:
    std::ofstream m_file;
    std::string m_filePath;
};

#endif // STREAMWRITER_H
