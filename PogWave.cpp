#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include <GL/freeglut.h>  

using namespace std;

const int width = 800, height = 500;
const float frameTime = 1000.0f / 60.0f, v = 12;

struct square {
   float x, y, edgeSize;
   int direction = 1;
   bool canMove = false;
};

vector<square> blocks;

void drawSquare(float x, float y, float edgeSize) {
  glBegin(GL_QUADS);
      glColor3f(133, 133, 133);
      glVertex2f(x, y + edgeSize);
      glVertex2f(x + edgeSize, y + edgeSize);
      glVertex2f(x + edgeSize,  y);
      glVertex2f(x,  y);
 glEnd();
}

square createSquare() {
   square newBlock = square();
   newBlock.edgeSize = 40;
   newBlock.x = 20 + blocks.size() * 50;
   newBlock.y = 0;
   return newBlock;
}

void scheduleUpdate(int useless) {
   glutTimerFunc((unsigned int) frameTime, scheduleUpdate, 1);

   for (int i = 0; i < (int) blocks.size(); i++) {
       if ((blocks[i].canMove && (i == 0 || blocks[i - 1].y >= 30)) || blocks[i].y != 0) {
           blocks[i].y += v * blocks[i].direction;

           if (blocks[i].y >= height - blocks[i].edgeSize) {
               blocks[i].direction = -1;
               blocks[i].y = height - blocks[i].edgeSize;
               blocks[i].canMove = i == 0 ? false : blocks[i - 1].canMove;
           } else if (blocks[i].y <= 0) {
               blocks[i].direction = 1;
               blocks[i].y = 0;
           }
       }
   }

   glutPostRedisplay();
}

void keyboardHandler(unsigned char key, int x, int y) {
  if(key == ' ')
    for (int i = 0; i < blocks.size(); i++) 
        blocks[i].canMove = true;
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   for (int j = 0 ; j< 5 ; j++)
      for (int i = 0; i < (int) blocks.size(); i++) 
         drawSquare(blocks[i].x, blocks[i].y + (j*45), blocks[i].edgeSize);

   glFlush();
}

void init() { gluOrtho2D(0, width, 0, height); }

int main(int argc, char** argv) {

   for (int i = 0; i < 18; i++) 
       blocks.push_back(createSquare());

   glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(width, height);
      glutInitWindowPosition(50, 50);
      glutCreateWindow("OpenGL Project - Wave");
      init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboardHandler);
   glutTimerFunc((unsigned int) frameTime, scheduleUpdate, 1);
   glutMainLoop();
   return 0;
}
