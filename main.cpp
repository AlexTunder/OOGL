#include <GL/freeglut.h>
#include <cstring.h>
#include <stdio.h>
#include <iostream>
#include "scenes.hpp"
glClass::model a;
int main(int arg, char **argv){
    a.main.getObjFromFile("resourses/untitled.obj");
    cout << a.main.RENDERDC[2].points[2].x;
    return 0;
}