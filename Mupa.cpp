#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

/*
 * Adaptado de:
 *   https://github.com/mdrkb/3D-House-using-OpenGL-and-C-/blob/master/main.cpp
*/

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f,z=50.0f;

float door_angle = 0.0f;

// angle for rotating
float angle = 0.0f;

GLUquadricObj *quadratic;

void init(void) {
    // sky color
    quadratic = gluNewQuadric();
    glClearColor(0.0, 0.7, 1.0, 1.0);
}

void draw(){

    // Back side floor
    glPushMatrix();
    glTranslatef(10, 0, 0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(20, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(0, 0, 21.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(0.1, 3.5, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(20, 0, 21.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(0.1, 3.5, 43);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawDoor() {

    glPushMatrix();
		glTranslatef(0, 0, 1.3);
        glRotatef (door_angle, 0,1,0);
        glColor3f(0.7f, 0.7f, 0.7f);
        glScalef(0.6, 2, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

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
    gluPerspective(45.0f, ratio, 0.1f, 1000.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){

    // Para ver os objetos em modo polígono (somente os traços)
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera
    gluLookAt(x, 1.3f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    // Draw ground
    glColor3f(0.0, 0.65, 0.0);
        glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    draw();
    drawDoor();

    glFlush();
    glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
        break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
        break;

        case 27:
            exit(0);
        break;
    }
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

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
