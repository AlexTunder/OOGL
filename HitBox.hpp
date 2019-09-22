#include "basic3d.hpp"
#include "EventCore.hpp"
int** hitregister = new int*;
namespace glClass{
    Event hitEvent("hitEvent", 12);
    void mkregist(int *property){
        hitregister[0] = property;
    }
    class phesbox{
        int id = 0b0 | settings_haveNormales | settings_universalSupport | settings_enableMoving;
        float cord[6];
        phesbox(int property = settings_haveNormales | settings_universalSupport | settings_enableMoving){
            id = property;
            hitregister[*hitregister[0]++]= &id;
        }
    };
    // phesbox findPhesById(int id){
    //     if(id < *hitregister[0])
    //         return 0;
        
    // }
}