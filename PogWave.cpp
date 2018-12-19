#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

const int width = 720, height = 250;
const float frameTime = 1000.0f / 60.0f, v = 12;

struct square {
   float x, y, edgeSize, R, G, B;
   int direction = 1;
    bool canMove = false;
};

vector<square> blocks;

void drawSquare(float x, float y) {

	glColor3ub(255,255,255);
   glBegin(GL_POINTS);
      glVertex2f(x,  y);
   glEnd();
}

square createSquare() {
   square newBlock = square();
   newBlock.edgeSize = 40;
   newBlock.x = 2 + blocks.size() * 5;
   newBlock.y = 0;
   double color[3] = {};
   srand((unsigned int) time(NULL));
   newBlock.R = (float) color[0];
   newBlock.G = (float) color[1];
   newBlock.B = (float) color[2];

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

           cout << "   x: " << blocks[i].x << ", y: " << blocks[i].y << endl;
       }
   }

   glutPostRedisplay();
}

void keyboardHandler(unsigned char key, int x, int y) {
    switch (key) {
        case ' ':
            for (int i = 0; i < blocks.size(); i++) {
                blocks[i].canMove = true;
            }
            break;
        default:
            break;
    }
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

   for (int i = 0; i < (int) blocks.size(); i++) {
      drawSquare(blocks[i].x, blocks[i].y);
   }

   glFlush();  // Render now
}

void init() {
  gluOrtho2D(0, width, 0, height);
}

int main(int argc, char** argv) {

    for (int i = 0; i < 150; i++) {
        blocks.push_back(createSquare());
    }

   glutInit(&argc, argv);                 // Initialize GLUT
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(width, height);   // Set the window's initial width & height
      glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
      glutCreateWindow("OpenGL Project - Wave"); // Create a window with the given title
      init();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutKeyboardFunc(keyboardHandler); // Register display callback handler for window re-paint
   glutTimerFunc((unsigned int) frameTime, scheduleUpdate, 1);
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}
