#define EVENTBUFFERSIZE 1
#include "EventCore.hpp"
#include <iostream>
using namespace std;
char *pointer = "aGlobalSpace";
void doAtEvent1(char eventdata[16]){
    cout << "hello!";
}
int main(){
    glClass::Handler16 new_handler1(doAtEvent1, pointer);
        glClass::callEvent16(pointer, 0);
        // cin.get();
        timespec time;
        clock_gettime(CLOCK_REALTIME, &time);
        // clock_nanosleep(CLOCK_REALTIME,)
        EventBuffer16[0] = pointer = nullptr;
        cin.get();
    return 0;
}