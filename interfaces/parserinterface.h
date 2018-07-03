#ifndef PARSERINTERFACE_H
#define PARSERINTERFACE_H

#include "../streamreader.h"

class ParserInterface{
public:
    ParserInterface(){}
    virtual ~ParserInterface(){}
    virtual void parse(StreamReader& stream, uint32_t& startPos)=0;
};
#endif // PARSERINTERFACE_H
