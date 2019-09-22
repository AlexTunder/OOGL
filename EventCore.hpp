// #include "defines.hpp"
// #include "basic3d.hpp"
#include <thread>
#include <cstring>
#ifndef EVENTBUFFERSIZE
#define EVENTBUFFERSIZE 1
#endif
class Event16;class Event32;class Handler16;class Handler32;class RawEvent;
typedef char *EventType;
#ifdef DEFAULT_EVENT_32
typedef Event32 Event;
#else
typedef Event16 Event;
#endif
using std::thread;
    char EventBuffer32[32][EVENTBUFFERSIZE];
    char *EventBuffer16[EVENTBUFFERSIZE];


    // int callEvent(Event *newEvent){
        
    // }
    // int addEvent(Event *newEvent){
        
    // }
    // int deleteEvent(Event *newEvent){
        
    // }

class RawEvent{
public:
    // EventType eventType;
    static char event[16];
};
class Event16 : public RawEvent{
public:
    // Event16();
    Event16(const char *name, int buf);
    char *getPointer(){
        return &event[0];
    }
};
Event16::Event16(const char name[16],int buf){
    strcpy(this->event, name);
    EventBuffer16[buf] = &this->event[0];

}
class Event32:public Event{
public:
    static char event[32];
};
class Handler16{
public:
    static int hellobytes;
    static void threadmm(){
        while (true)
            for(int i = 0; i < EVENTBUFFERSIZE; i++)
                if(std::string(eventTarget.event) == EventBuffer16[i])
                    startHandler();
    }
    static Event16 eventTarget;
    void static (*startHandler)(void);
    std::thread eventHandler;
    Handler16(int hellobytes, Event16 eventTarget, void (*startHandler)(void)){
        this->hellobytes = hellobytes;
        this->eventTarget = eventTarget;
        this->startHandler = startHandler;
        eventHandler = thread(threadmm);
        eventHandler.join();
    }
};
class Handler32{
public:
    static void threadmm(){
        while (true)
            for(int i = 0; i < EVENTBUFFERSIZE; i++)
                if(std::string(eventTarget.event) == EventBuffer32[i])
                    startHandler();
    }
    static int hellobytes;
    static Event32 eventTarget;
    void static (*startHandler)(void);
    static std::thread eventHandler;
    Handler32(int hellobytes, Event32 eventTarget, void (*startHandler)(void)){
        this->hellobytes = hellobytes;
        this->eventTarget = eventTarget;
        this->startHandler = startHandler;
        eventHandler = thread(threadmm);
        eventHandler.join();
    }
};
int Handler32::hellobytes = 0;
int Handler16::hellobytes = 0;
// void Handler32::threadmm(){
//     while (true)
//             for(int i = 0; i < EVENTBUFFERSIZE; i++)
//                 if(std::string(eventTarget.event) == EventBuffer32[i])
//                     startHandler();
// }
// void Handler16::threadmm(){
//     while (true)
//             for(int i = 0; i < EVENTBUFFERSIZE; i++)
//                 if(std::string(eventTarget.event) == EventBuffer32[i])
//                     startHandler();
// }

void nullvoid(void){

}
// void Handler16::startHandler = nullvoid;
// void Handler32::startHandler = 0;
char RawEvent::event[16] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
char Event32::event[32] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";