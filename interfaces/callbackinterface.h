#ifndef CALLBACKINTERFACE_H
#define CALLBACKINTERFACE_H

#include <iostream>

enum class  DIRECT_RESIZE{
    INCREASED,
    DECREASED
};

class CallbackInterface{
public:
    CallbackInterface(){}
    virtual ~CallbackInterface(){}
    virtual void resizeAtom(uint32_t size, DIRECT_RESIZE direction)=0;
};
#endif // CALLBACKINTERFACE_H
