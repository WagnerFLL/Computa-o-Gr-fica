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

float fovy = 80.0f;

float cam = 3.0f;

GLUquadricObj *quadratic;

void init(void) {
    // sky color
    quadratic = gluNewQuadric();
    glClearColor(0.0, 0.7, 1.0, 1.0);
}

void drawColumn(float x) {
  glPushMatrix();
   glTranslatef(x, 0, 43);
   glRotatef(-90, 1,0,0);
      glColor3f(0.78f, 0.823f, 0.824f);
      gluCylinder(quadratic, 0.28, 0.28, 7, 30, 30);
  glPopMatrix();
}

void draw(){

    // Back side floor
    glPushMatrix();
    glTranslatef(10, 1.75, 0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(20, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(0, 1.75, 21.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(0.1, 3.5, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(20, 1.75, 21.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(0.1, 3.5, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    // salao despacho com gabinete e jardim
    glPushMatrix();
    glTranslatef(7.5, 1.75, 9.75);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(19.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // salão de despacho com direitoria
    glPushMatrix();
    glTranslatef(3, 1.75, 13.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // diretoria com corredor
    glPushMatrix();
    glTranslatef(6, 1.75, 16.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // diretoria com atelier
    glPushMatrix();
    glTranslatef(3, 1.75, 19.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // atelier com corredor
    glPushMatrix();
    glTranslatef(6, 1.75, 22.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // atelier com sala protocolo
    glPushMatrix();
    glTranslatef(3, 1.75, 25.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // jardim com costas da escada
    glPushMatrix();
    glTranslatef(10.65, 1.75, 19.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.3, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // por tras da recpção
    glPushMatrix();
    glTranslatef(13.8, 1.75, 22.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // sec. cult com elevador
    glPushMatrix();
    glTranslatef(16.9, 1.75, 25.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.2, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // elevador com reserva técnica
    glPushMatrix();
    glTranslatef(16.75, 1.75, 28);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // reserva téc. com salão
    glPushMatrix();
    glTranslatef(13.8, 1.75, 31.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(7, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // sala protocolo com exposicao 1
    glPushMatrix();
    glTranslatef(3.25, 1.75, 28);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // exposicao1 com salao
    glPushMatrix();
    glTranslatef(6, 1.75, 31.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(7, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // mini auditorio com salao
    glPushMatrix();
    glTranslatef(13.8, 1.75, 39);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(8, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // exposicao 2 com salao
    glPushMatrix();
    glTranslatef(6, 1.75, 39);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(8, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // lage
    glPushMatrix();
    glTranslatef(10, 3.6, 21.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(20, 0.2, 44);
        glutSolidCube(1.0);
    glPopMatrix();

    // floor
    glPushMatrix();
    glTranslatef(10, 0.1, 21.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(20, 0.2, 44);
        glutSolidCube(1.0);
    glPopMatrix();

// ESCADA
    float zBase = 25.5, yBase = 0.25;

    for (int i = 0; i < 20; i++, zBase -= 0.2, yBase += 0.1){
      glPushMatrix();
      glTranslatef(9.9, yBase, zBase);
          glColor3f(0.78f, 0.823f, 0.824f);
          glScalef(2.5, 0.175, 0.2);
          glutSolidCube(1.0);
      glPopMatrix();
    }

    // floor escada
    glPushMatrix();
    glTranslatef(9.9, 2.3, 20.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(4.5, 0.2, 2);
        glutSolidCube(1.0);
    glPopMatrix();

    zBase = 21.5;
    yBase = 2.25;

    for (int i = 0; i < 12; i++, zBase += 0.2, yBase += 0.1){
      glPushMatrix();
      glTranslatef(11.6, yBase, zBase);
          glColor3f(0.78f, 0.823f, 0.824f);
          glScalef(1, 0.175, 0.2);
          glutSolidCube(1.0);
      glPopMatrix();
    }

    zBase = 21.5;
    yBase = 2.25;

    for (int i = 0; i < 12; i++, zBase += 0.2, yBase += 0.1){
      glPushMatrix();
      glTranslatef(8.1, yBase, zBase);
          glColor3f(0.78f, 0.823f, 0.824f);
          glScalef(1, 0.175, 0.2);
          glutSolidCube(1.0);
      glPopMatrix();
    }

// FACHADA
    drawColumn(6);
    drawColumn(8.6);
    drawColumn(11.2);
    drawColumn(14);

    // sides
    glPushMatrix();
    glTranslatef(3, 3.5, 43);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 7, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17, 3.5, 43);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 7, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // Top
    glPushMatrix();
    glTranslatef(10, 8, 43);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(20, 2, 0.1);
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
    gluPerspective(fovy, ratio, 0.1f, 1000.0f);

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
    gluLookAt(x, cam , z,  // de onde
              x+lx, cam, z+lz, // pra onde
              0.0f, 1.0f, 0.0f); // como

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
        case 'w' :
            cam += 0.3f;
        break;
        case 's' :
            cam -= 0.3f;
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
