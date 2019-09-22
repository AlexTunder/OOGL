#define EVENTBUFFERSIZE 1
#include "EventCore.hpp"
#include <iostream>
using namespace std;
static Event16 newEvent("Strartx event", 0);
void doOnHandler(void){
    cout << EventBuffer16[0];
}
static Handler16 newHandler(1,newEvent,doOnHandler);
int main(){
    return 0;
}