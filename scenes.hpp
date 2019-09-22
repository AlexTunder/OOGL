#include "basic3d.hpp"
#include "HitBox.hpp"
namespace Scene
{
    class Scene{
        public:
        int *ortho[6];
        char *sceneName = new char;
        glClass::model *base;
        glClass::phesbox phes;
        glClass::phesbox Phese;
        glClass::Point *PheseCenter;
        int setting;
        void enable(int setting){
            this->setting = this->setting | setting;
        }
        void disable(int setting){
            this->setting = this->setting ^ setting;
        }
        void drawScene(){
            base->draw();
        }
    };
}
