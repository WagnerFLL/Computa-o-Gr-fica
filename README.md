# Computer graphics | UFAL
Computer graphics with OpenGL 2.0

How to compile:
* Windows:
  * g++ name.cpp -o test.o -c
  * g++ test.o -o test.exe -lglu32 -lopengl32 -lfreeglut
* Linux:
  * g++ name.cpp -o test -lGL -lGLU -lglut
