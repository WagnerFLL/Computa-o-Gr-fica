#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <time.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

GLuint texture_id[40];

// Direção da camera
float lx = 0.0f, lz = -1.0f;
float deltaAngle = 0.0f;
int xOrigin = -1;

// XZ posição
float x = 10.0f, z = 50.0f;
int mouseX, mouseY;
GLuint texture;

// Ângulos
float angle = 0.0f;
float door_angle = 0.0f;
float fovy = 70.0f;
float cam = 3.5f;

// Alturas
float floor2_thickness = 0.2f;
float floor1_height = 1.0f;
float wall_height = 0.2f;
float floor2_height = 0.2f;

GLUquadricObj *quadratic;


#include "Camera.h"
#include "Texture.h"
#include "DrawObjects.h"
#include "DrawWall.h"
#include "Draw.h"
#include "Lightning.h"

float currentFrame;

void init(void) {
    quadratic = gluNewQuadric();
    glClearColor(0.0, 0.7, 1.0, 1.0);
    loadTextures();
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glShadeModel(GL_SMOOTH);
}

void changeSize(int w, int h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(fovy, ratio, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
	currentFrame = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	processCamera();
	lightsSetup();
    draw();
    glFlush();
    glutSwapBuffers();
}

void processSpecialKeys(int key, int xx, int yy) {
    float fraction = 0.5f;
    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
        case GLUT_KEY_PAGE_UP :
            cam += 0.1;
            break;
        case GLUT_KEY_PAGE_DOWN :
            cam -= 0.1;
            break;
    }
}


int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA  | GLUT_ALPHA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 600);
    glutCreateWindow("MUPA");

    init();

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(mouseMovement);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    glutMainLoop();

    return 1;
}
