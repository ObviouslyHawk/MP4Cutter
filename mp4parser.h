#ifndef MP4PARSER_H
#define MP4PARSER_H
#include "atoms/moov.h"
#include "atoms/ftyp.h"
#include <memory>

class MP4Parser
{
public:
    MP4Parser();
    ~MP4Parser();
    void parse(StreamReader& stream);
    void prepareData(uint32_t begTime, uint32_t endTime);

    void writeOnlyVideo(StreamReader& inStream, StreamWriter& outStream);
private:
    std::unique_ptr<MOOV> m_moov;
    std::unique_ptr<FTYP> m_ftyp;
    std::pair<uint32_t, uint32_t> m_mdatInfo;
};

#endif // MP4PARSER_H
