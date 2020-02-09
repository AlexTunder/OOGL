#include <GL/glut.h>
#include <fstream>
#include "defines.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define FONT_STD_MONOSPACE_SYS
namespace glClass{
    class Font{
        public: int standart;
        char *fontDrawableXML_locate;
    };
    class InterfaceItem{
        public:
        float pos[2];
        Clickable onClick;
        Drawable drawManual;
        unsigned int id;
    };
    class Clickable{
        public:
        void (*onClickListen)(int button, char position[2]);
    };
    class Drawable{
        public:
        void (*drawFunc)(char indent);
        char Color[3];
    };
    class TextBox : public InterfaceItem{
        public:
            char *text;
            char settingsbyte;
    };
    void drawTextBox(char indent){
        
    }
}