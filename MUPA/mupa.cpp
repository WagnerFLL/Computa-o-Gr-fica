#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

// #include "texture.cpp"

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
float deltaAngle = 0.0f;
int xOrigin = -1;
// XZ position of the camera
float x=10.0f,z=50.0f;

GLuint texture;

// angle for rotating
float angle = 0.0f;

float door_angle = 0.0f;

float fovy = 70.0f;

float cam = 3.5f;

// heights
float floor2_thickness = 0.2f;
float floor1_height = 1.0f;
float wall_height = 0.2f;
float floor2_height = 0.2f;

bool enable_textures = false;

GLUquadricObj *quadratic;

#include "Camera.h"
#include "Draw.h"
#include "DrawWall.h"
#include "DrawObjects.h"
#include "Texture.h"

void FreeTexture( GLuint texture )
{
	glDeleteTextures( 1, &texture ); //  Delete our texture, simple enough.
}

void ilumination (void) {}

void init(void) {
    quadratic = gluNewQuadric();
    glClearColor(0.0, 0.7, 1.0, 1.0);
    // loadTextures();
    glEnable (GL_DEPTH_TEST);
}

void changeSize(int w, int h){
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;
    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);
    // Reset Matrix
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    // Set the correct perspective.
    gluPerspective(fovy, ratio, 0.1f, 1000.0f);
    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){

	float currentFrame = glutGet(GLUT_ELAPSED_TIME) ;
	printf("%d\n", &currentFrame);
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	// Para ver os objetos em modo polígono (somente os traços)
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    ilumination();
    // Set the camera
	processCamera();

    // Draw ground
    glColor3f(0.0, 0.65, 0.0);
        glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    draw();
    // drawDoor();

    glFlush();
    glutSwapBuffers();
}



void processSpecialKeys(int key, int xx, int yy){

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

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.01f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

int main(int argc, char **argv){

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("House 3D");

    init();

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

    // OpenGL init
    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
