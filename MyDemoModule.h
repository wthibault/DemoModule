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
  float  angle;

  GLuint buffer;
  GLuint vao;
  GLuint program;
  GLuint vPosition;
  GLuint vColor;
  GLuint modelviewMatrixUniformLocation;
  GLuint projectionMatrixUniformLocation;
  GLuint numVertices;
  glm::vec4 points[3];
  glm::vec4 colors[3];

 public:
  MyDemoModule() {
    angle = 0.0;
    numVertices = 3;

    points[0] = glm::vec4 ( 0,-1,0,1 );
    points[1] = glm::vec4 ( 1,1,0,1 );
    points[2] = glm::vec4 ( -1,1,0,1 );

    colors[0] = glm::vec4 ( 1,0,0,1 );
    colors[1] = glm::vec4 ( 0,1,0,1 );
    colors[2] = glm::vec4 ( 0,0,1,1 );

    // Create a vertex array object
#ifdef USE_APPLE_VERTEXARRAYS
    glGenVertexArraysAPPLE( 1, &vao );
    glBindVertexArrayAPPLE( vao );
#else
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );
#endif

    // Create and initialize a buffer object
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors),
		  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors );

    // Load shaders and use the resulting shader program
    program = Angel::InitShader( "MyDemoModule.vert", "MyDemoModule.frag" );
    glUseProgram( program );

    // set up vertex arrays
    vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
			   (GLvoid *)(0));

    vColor = glGetAttribLocation( program, "vColor" ); 
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
			   (GLvoid *)(sizeof(points)) );

    modelviewMatrixUniformLocation = glGetUniformLocation ( program, "modelviewMatrix" );
    projectionMatrixUniformLocation = glGetUniformLocation ( program, "projectionMatrix" );

    glBindVertexArray ( 0 );
  };
  virtual ~MyDemoModule() {};

  virtual void update ( float dt ) {
    angle += dt * 50.0;
  };

  virtual void draw ( glm::mat4 modelview, 
		      glm::mat4 projection ) {
    glUseProgram ( program );
    glBindVertexArray ( vao );
    glUniformMatrix4fv( modelviewMatrixUniformLocation, 1, GL_FALSE, glm::value_ptr(modelview) );
    glUniformMatrix4fv( projectionMatrixUniformLocation, 1, GL_TRUE, glm::value_ptr(projection) );
    glDrawArrays( GL_TRIANGLES, 0, numVertices );
    glBindVertexArray ( 0 );
  };
};

 


