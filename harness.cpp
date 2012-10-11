//
// harness.cpp
//   test harness for DemoModule
//  Bill Thibault 10/2/2011

// This test harness uses GLUT, but the "compcore demo" doesn't.
// Be sure to limit your drawing code in DemoModule and subclasses
// to gl only.

#if 0
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif

#if 0
#include "Angel.h"
#endif

#if 1
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "MyDemoModule.h"

DemoModule *module;

void display ()
{
  glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  module->update(0.033); // assumes called at 30Hz
  module->draw();
  glutSwapBuffers();
}

void timer ( int delay )
{
  glutTimerFunc( delay, timer, delay );
  glutPostRedisplay();
}

void reshape (int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 50.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -4.0);
}

void keyboard (unsigned char key, int x, int y)
{
  switch (key) {
  case 27: /* ESC */
    exit(0);
    break;
  default:
    break;
  }
}

void init ()
{
  module = new MyDemoModule;
  glClearColor (0.0, 0.0, 0.0, 1.0);
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize (300, 300); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  
  glewInit();
  init();
  
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(30,timer,30); 
  glutMainLoop();
  return 0;
}


