// 
// MyDemoModule.h - 
//  - example subclassing of "compcore demo" module
//  Bill Thibault 10/2/2011, created
//                10/10/2012 added Angel-ic shader support
//
// be careful not to use GLUT calls here
//

#define GL_GLEXT_PROTOTYPES 1

#include <iostream> 
#include "DemoModule.h"


class MyDemoModule : public DemoModule {
 private:
  float angle;
  GLuint buffer;
  GLuint vao;
  GLuint program;
  GLuint vPosition;
  GLuint vColor;
#if 0
  Angel::vec4 points[3];
  Angel::vec4 colors[3];
#else
  glm::vec4 points[3];
  glm::vec4 colors[3];
#endif
 public:
  MyDemoModule() {
    angle = 0.0;

    points[0] = glm::vec4 ( 0,-1,0,1 );
    points[1] = glm::vec4 ( 1,1,0,1 );
    points[2] = glm::vec4 ( -1,1,0,1 );

    colors[0] = glm::vec4 ( 1,0,0,1 );
    colors[1] = glm::vec4 ( 0,1,0,1 );
    colors[2] = glm::vec4 ( 0,0,1,1 );

    // Create a vertex array object
    glGenVertexArraysAPPLE( 1, &vao );
    glBindVertexArrayAPPLE( vao );

    // Create and initialize a buffer object
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors),
		  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors );

    // Load shaders and use the resulting shader program
    program = Angel::InitShader( "vshader41.glsl", "fshader41.glsl" );
    glUseProgram( program );

    // set up vertex arrays
    vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
			   (GLvoid *)(0));
			   //			   BUFFER_OFFSET(0) );

    vColor = glGetAttribLocation( program, "vColor" ); 
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
			   (GLvoid *)(sizeof(points)) );
			   //			   BUFFER_OFFSET(sizeof(points)) );


  };
  virtual ~MyDemoModule() {};

  virtual void update ( float dt ) {
    angle += dt * 50.0;
  };

  virtual void draw() {
    glPushMatrix();
    glRotatef ( angle, 0,1,0 );
    int n = 10;
    for ( int i = 0; i < n; i++ ) {
      glRotatef ( 10.0, 0,1,0 );
      float amt = (static_cast<float>(n)- i)/n;
      glColor4f ( 1.0,amt,amt,1.0 );
      glBegin(GL_TRIANGLES);
      glVertex3f(0,-1,0);
      glVertex3f(1,1,0);
      glVertex3f(-1,1,0);
      glEnd();
    }
    glPopMatrix();
  };

  virtual void draw ( glm::mat4 modelview, 
		      glm::mat4 projection ) {
  };
};

 


