#include <GL/glut.h>
#include <cstring.h>
#include <stdio.h>
#include <iostream>
#include "basic3d.hpp"
glClass::model a;
void display() {
//     cout << a.main.VERTEXES[5].x;
//     cout <<"\n"<< a.main.PolygobCount<<"\n";
//     // a.main.getObjFromFile("Pathologic/resourses/untitled.obj");
// //    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//     glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
//     // glBegin(GL_POLYGON);
//     glColor3f(1,1,0);
//     a.draw();
//     // glVertex3f(-1,-1,0);
//     // glVertex3f(1,1,0);
//     // glEnd();
//     // glColor3f(1,1,0);
//     // a.draw();
//     glutSwapBuffers();
}
int main(int arg, char **argv){
  cout << a.main.getObjFromFile("Pathologic/resourses/untitled.obj");
  // glutInit(&arg,argv);
  // glutInitWindowSize( 500, 750 );       /* A x A pixel screen window  */

  // glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
  // glutCreateWindow("My Rectangle"); /* window title                   */
  // glutDisplayFunc(display); 
  // glClearColor(0, 0, 0, 0); /* gray background */
 
  // glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  // glLoadIdentity();                 /* position the "clipping rectangle" */
  // glOrtho( -2,2, -2, 2,2,-2);/* at -B/2, its right edge at +B/2, its bottom */
  // glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */                      /* set attributes                 */

  // glutMainLoop();                   /* pass control to the main loop  */
    return 0;
}