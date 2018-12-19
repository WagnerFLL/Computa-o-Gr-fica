#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


const float frameTime = 1000.0f / 60.0f, v = 12;

struct sequence {
   float x, y, edgeSize, R, G, B;
   int direction = 1;
   bool canMove = false;
};

vector<sequence> points;

void drawsequence(float x, float y) {

	 glColor3ub(255,255,255);
   glBegin(GL_POINTS);
      glVertex2f(x,  y);
   glEnd();

}

sequence createsequence() {
   sequence newBlock = sequence();
   newBlock.x = 2 + points.size() * 10;
   newBlock.y = 0;
   return newBlock;
}

void scheduleUpdate(int useless) {
   glutTimerFunc((unsigned int) frameTime, scheduleUpdate, 1);

   for (int i = 0; i < (int) points.size(); i++) {
       if ((points[i].canMove && (i == 0 || points[i - 1].y >= 30)) || points[i].y != 0) {
           points[i].y += v * points[i].direction;

           if (points[i].y >= 600 - points[i].edgeSize) {
               points[i].direction = -1;
               points[i].y = 600 - points[i].edgeSize;
               points[i].canMove = i == 0 ? false : points[i - 1].canMove;

           } else if (points[i].y <= 0) {
               points[i].direction = 1;
               points[i].y = 0;
           }

       }
   }

   glutPostRedisplay();
}

void keyboardHandler(unsigned char key, int x, int y) {
    if(key == ' '){
            for (int i = 0; i < points.size(); i++) {
                points[i].canMove = true;
            }
    }
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   for (int j = 0; j < 420 ; j++) {
     for (int i = 0; i < (int) points.size(); i++) {
        drawsequence(points[i].x, points[i].y + j);
     }
   }

   glFlush();
}

void init() {
  gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {

    for (int i = 0; i < 200; i++) {
        points.push_back(createsequence());
    }

   glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(800, 600);
      glutInitWindowPosition(50, 50);
      glutCreateWindow("Olha onda, olha onda");
      init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboardHandler);
   glutTimerFunc((unsigned int) frameTime, scheduleUpdate, 1);
   glutMainLoop();
   return 0;
}
