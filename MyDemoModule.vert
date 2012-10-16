attribute  vec4 vPosition;
attribute  vec4 vColor;
varying vec4 color;

uniform mat4 modelviewMatrix;
uniform mat4 projectionMatrix;

void main() 
{
    gl_Position = projectionMatrix*modelviewMatrix*vPosition;
    color = vColor;
} 
