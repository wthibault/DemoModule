OPTS = -g
# settings for turing
#GL_INCLUDES = -I/opt/viz/include
#GL_LIBS = -lGL -lGLU -lglut -L/opt/viz/lib -lGLEW
#for sn336s*
GL_INCLUDES = 
GL_LIBS = -lGL -lGLU -lglut -lGLEW

harness : harness.cpp DemoModule.h MyDemoModule.h InitShader.o
	g++ $(OPTS) -o harness $(GL_INCLUDES) harness.cpp InitShader.o $(GL_LIBS)

InitShader.o : InitShader.cpp
	g++ $(OPTS) -c $(GL_INCLUDES) InitShader.cpp


clean :
	rm -f *.o
	rm -f *~
	rm -f harness
