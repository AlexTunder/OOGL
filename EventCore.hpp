// #include "defines.hpp"
// #include "basic3d.hpp"
#include <thread>
#include <cstring>
#ifndef EVENTBUFFERSIZE
#define EVENTBUFFERSIZE 1
#endif
class Event16;class Event32;class Handler16;class Handler32;
typedef char *EventType;
#ifdef DEFAULT_EVENT_32
typedef Event32 Event;
#else
typedef Event16 Event;
#endif
using std::thread;
    char *EventBuffer32[EVENTBUFFERSIZE];
    char *EventBuffer16[EVENTBUFFERSIZE];
class eventException{
    public:
        char *error_text = new char;
        char *bufferLink;
        int error_code;
        eventException(char *buffer, int code){
            bufferLink = buffer;
            error_code = code;
        }
        eventException(char *buffer, int code, char *comment){
            bufferLink = buffer;
            strcpy(error_text, comment);
        }
};
class Event16{
public:
    int staticindex;
    char eventdata[16];
    int call(char eventdata[16], int staticindex);
    int call(char eventdata[16]);
    int call();
    Event16();
    ~Event16();
};
class Event32:Event16{
public:
    char eventdata[32];
    int call(char eventdata[32], int staticindex);
    int call(char eventdata[32]);
    int call();
    Event32();
    ~Event32();
};
bool checkEventBuffer(bool isEvent16){
    if (isEvent16)
        return EventBuffer16 == nullptr;
    else return EventBuffer32 == nullptr;
}
int callEvent16(char *eventdataPointer16, int indexOfBuffer){
    if(checkEventBuffer(1))
        EventBuffer16[indexOfBuffer] = eventdataPointer16;
    else throw eventException(EventBuffer16[indexOfBuffer],116,"Throw Event to full x16 buffer. Code 116");
}
int callEvent32(char *eventdataPointer32, int indexOfBuffer){
    if(checkEventBuffer(0))
        EventBuffer32[indexOfBuffer] = eventdataPointer32;
    else throw eventException(EventBuffer32[indexOfBuffer],132,"Throw Event to full x32 buffer. Code 132");
}
int callEvent16(char *eventdataPointer16, int indexOfBuffer,bool){
    EventBuffer16[indexOfBuffer] = eventdataPointer16;
    return checkEventBuffer(1);
}
int callEvent32(char *eventdataPointer32, int indexOfBuffer,bool){
    EventBuffer32[indexOfBuffer] = eventdataPointer32;
    return checkEventBuffer(0);
}
class Handler16{
private:
    int datacrash(char *eventdata);
    thread HandlerMainLoop;
public:
char *targethost, eventdata[16];
void evetFunc(char eventdata[16]){
    // if()
}
void (*doAtEvent)(char eventdata[16]);
Handler16(void (*doAtEvent)(char eventdata[16]), char eventdata[16]);
int start();
};
Handler16::Handler16(void (*doAtEvent)(char eventdata[16]), char eventdata[16]){
    this->doAtEvent = doAtEvent;
    strcpy(this->eventdata, eventdata);
    HandlerMainLoop = thread(doAtEvent ,this, eventdata);
    HandlerMainLoop.detach();
}