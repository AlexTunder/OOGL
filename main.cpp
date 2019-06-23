#include <GL/freeglut.h>
#include <cstring.h>
#include <stdio.h>
#include <iostream>
#include "scenes.hpp"
glClass::model a;
int main(int arg, char **argv){
    std::cout << a.main.RENDERDC[0].points[0].id<<":"<< a.main.RENDERDC[0].points[0].x<<":"<< a.main.RENDERDC[0].points[0].y<<":"<< a.main.RENDERDC[0].points[0].z;
    cin.get();
    return 0;
}