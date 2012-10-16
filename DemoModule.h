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
  virtual void draw ( glm::mat4 modelview, 
		      glm::mat4 projection ) {
  };
 private:
};

 


#endif
