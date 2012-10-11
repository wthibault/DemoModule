// 
// DemoModule.h - 
//  - "compcore demo" module
//  Bill Thibault 10/2/2011
//
// be careful not to use GLUT calls
#ifndef DEMOMODULE_H
#define DEMOMODULE_H

#include <GL/glew.h>
#include "InitShader.h"

class DemoModule {
 public:
  DemoModule() {
  };
  virtual ~DemoModule() {
  };

  virtual void update ( float dt ) {};
  virtual void draw() {
#if 0
    glBegin(GL_TRIANGLES);
    glVertex3f(0,-1,0);
    glVertex3f(1,1,0);
    glVertex3f(-1,1,0);
    glEnd();
#endif
  };
 private:
};

 


#endif
