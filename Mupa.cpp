#include <GL/glut.h>
#include <GL/freeglut.h>
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

float cam = 2.0f;

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

void drawOrthoWall(float x, float z, float width, int floor) {
  float relativeX = x + width/2;
  float relativeY = 1.75 + (floor * 3.5);

  glPushMatrix();
  glTranslatef(relativeX, relativeY, z);
      glColor3f(1.0f, 0.5f, 0.0f);
      glScalef(width, 3.5, 0.1);
      glutSolidCube(1.0);
  glPopMatrix();
}

void drawParallelWall(float x, float z, float width, int floor) {
  float relativeZ = z + width/2;
  float relativeY = 1.75 + (floor * 3.5);

  glPushMatrix();
  glTranslatef(x, relativeY, relativeZ);
      glRotatef (90, 0,1,0);
      glColor3f(1.0f, 0.5f, 0.0f);
      glScalef(width, 3.5, 0.1);
      glutSolidCube(1.0);
  glPopMatrix();
}

void drawChair(float x, float  y, float z, int cabeceira, int rotate) {
  glPushMatrix();
  glTranslated(x, y + 0.7, z);
    if(cabeceira)
      glScalef(1,1.15,1);
    glRotatef (rotate*90, 0,1,0);
    if(rotate == 3)
      glTranslated(-0.5, 0, -0.5);
    // costas
    glPushMatrix();
    glTranslatef(0, 0, 0);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.1, 1.2, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, 0.3, 0);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.06, 0.6, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0.3, 0);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.06, 0.6, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0, 0);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.1, 1.2, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.6, 0);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.8, 0.06, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // acento
    glPushMatrix();
    glTranslatef(0.3, 0, 0.38);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.7, 0.06, 0.7);
        glutSolidCube(1.0);
    glPopMatrix();

    // pé da frente
    glPushMatrix();
    glTranslatef(0, -0.3, 0.6);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.1, 0.6, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, -0.3, 0.6);
        glColor3f(0.2f, 0.10f, 0.0f);
        glScalef(0.1, 0.6, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

  glPopMatrix();
}

void drawTable(float x, float z){

  glPushMatrix();
    // tampa
    glPushMatrix();
    glTranslatef(x, 1, z+3);
        glPushMatrix();
          glColor3f(0.3f, 0.2f, 0.1f);
          glScalef(3, 0.05, 6);
          glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x, 1.05, z+3);
        glPushMatrix();
          glColor3f(0.35f, 0.3f, 0.2f);
          glScalef(2.8, 0.05, 5.8);
          glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    // pés
    glPushMatrix();
    glTranslatef(x-1.45, 0.5, z+0.05);
        glPushMatrix();
          glColor3f(0.3f, 0.2f, 0.1f);
          glScalef(0.1, 1, 0.1);
          glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x-1.45, 0.5, z+6-0.05);
        glPushMatrix();
          glColor3f(0.3f, 0.2f, 0.1f);
          glScalef(0.1, 1, 0.1);
          glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+1.45, 0.5, z+0.05);
        glPushMatrix();
          glColor3f(0.3f, 0.2f, 0.1f);
          glScalef(0.1, 1, 0.1);
          glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x+1.45, 0.5, z+6-0.05);
        glPushMatrix();
          glColor3f(0.3f, 0.2f, 0.1f);
          glScalef(0.1, 1, 0.1);
          glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();
  glPopMatrix();

}

void drawStar(float z) {
  glPushMatrix();
    glTranslated(4.5, 1.1, z);
    glRotated(90, 1, 0, 0);
    glColor3f(1.0f, 0.75f, 0.0f);
    glBegin(GL_POLYGON);
      glVertex3f(-0.60, 0.77, 0);
      glVertex3f(-0.68, 0.77, 0);
      glVertex3f(-0.7, 0.68, 0);
      glVertex3f(-0.64, 0.63, 0);
      glVertex3f(-0.58, 0.68, 0);
    glEnd();
  glPopMatrix();
}

void drawDetail(float x) {
  glPushMatrix();
  glTranslatef(x + 0.25, 9.3, 43);
      glColor3f(1.0f, 0.5f, 0.0f);
      glScalef(0.5, 0.6, 0.1);
      glutSolidCube(1.0);
  glPopMatrix();
}

void draw(){
//Primeiro andar
    // Back side floor
    glPushMatrix();
    glTranslatef(10, 4.5, 0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(20, 9, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(0,4.5, 21.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(0.1, 9, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(20, 4.5, 21.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(0.1, 9, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    // salao despacho com gabinete e jardim
    drawParallelWall(7.5, 0, 19.5, 0);

    // salão de despacho com direitoria
    drawOrthoWall(0,13.5, 6, 0);

    // diretoria com corredor
    drawParallelWall(6, 13.5, 6, 0);

    // diretoria com atelier
    drawOrthoWall(0, 19.5, 6, 0);

    // atelier com corredor
    drawParallelWall(6, 19.5, 6, 0);

    // atelier com sala protocolo
    drawOrthoWall(0, 25.5, 6, 0);

    // jardim com costas da escada
    drawOrthoWall(7.5, 19.5, 6.3, 0);

    // por tras da recpção
    drawParallelWall(13.8, 19.5, 6, 0);

    // sec. cult com elevador
    drawOrthoWall(13.8, 25.5, 6.2, 0);

    // elevador com reserva técnica
    drawOrthoWall(13.5, 28, 6.5, 0);

    // reserva téc. com salão
    drawParallelWall(13.8, 28, 7, 0);

    // sala protocolo com exposicao 1
    drawOrthoWall(0, 28, 6.5, 0);

    // exposicao1 com salao
    drawParallelWall(6, 28, 7, 0);

    // mini auditorio com salao
    drawParallelWall(13.8, 35, 8, 0);

    // exposicao 2 com salao
    drawParallelWall(6, 35, 8, 0);

// floor 1
    // Back
    glPushMatrix();
    glTranslatef(10, 3.6, 10.75);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(20, 0.2, 21.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // Front
    glPushMatrix();
    glTranslatef(10, 3.6, 34);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(20, 0.2, 18.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right
    glPushMatrix();
    glTranslatef(3.8, 3.6, 22.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(7.6, 0.2, 6);
        glutSolidCube(1.0);
    glPopMatrix();

    // Left
    glPushMatrix();
    glTranslatef(15.8, 3.6, 22.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(7.6, 0.2, 6);
        glutSolidCube(1.0);
    glPopMatrix();

    // floor 0
    glPushMatrix();
    glTranslatef(10, 0.1, 21.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(20, 0.2, 44);
        glutSolidCube(1.0);
    glPopMatrix();

    // lage
    glPushMatrix();
    glTranslatef(10, 7.1, 21.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(20, 0.2, 43.5);
        glutSolidCube(1.0);
    glPopMatrix();

// ESCADA
    float zBase = 25.5, yBase = 0.25;

    for (int i = 0; i < 21; i++, zBase -= 0.2, yBase += 0.1){
      glPushMatrix();
      glTranslatef(9.9, yBase, zBase);
          glColor3f(0.78f, 0.823f, 0.824f);
          glScalef(2.5, 0.175, 0.2);
          glutSolidCube(1.0);
      glPopMatrix();
    }

    // floor escada
    glPushMatrix();
    glTranslatef(9.9, 2.2, 20.5);
        glColor3f(0.5f, 0.5f, 0.5f);
        glScalef(4.7, 0.2, 2);
        glutSolidCube(1.0);
    glPopMatrix();

    zBase = 21.5;
    yBase = 2.25;

    for (int i = 0; i < 12; i++, zBase += 0.334, yBase += 0.12){
      glPushMatrix();
      glTranslatef(11.6, yBase, zBase);
          glColor3f(0.78f, 0.823f, 0.824f);
          glScalef(1, 0.15, 0.35);
          glutSolidCube(1.0);
      glPopMatrix();
    }

    zBase = 21.5;
    yBase = 2.25;

    for (int i = 0; i < 12; i++, zBase += 0.334, yBase += 0.12){
      glPushMatrix();
      glTranslatef(8.1, yBase, zBase);
          glColor3f(0.78f, 0.823f, 0.824f);
          glScalef(1, 0.15, 0.35);
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

    // middle
    glPushMatrix();
    glTranslatef(9.85, 9.62, 43);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(1.25, 1.25, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // details
    drawDetail(0);
    drawDetail(5.75);
    drawDetail(13.75);
    drawDetail(19.5);

// CADEIRA
    drawChair(3.5, 0, 2, 1, 0);
    drawChair(1.5, 0, 3.5, 0, 1);
    drawChair(1.5, 0, 4.5, 0, 1);
    drawChair(1.5, 0, 5.5, 0, 1);
    drawChair(1.5, 0, 6.5, 0, 1);
    drawChair(1.5, 0, 7.5, 0, 1);
    drawChair(1.5, 0, 8.5, 0, 1);
    drawChair(5, 0, 3.5, 0, 3);
    drawChair(5, 0, 4.5, 0, 3);
    drawChair(5, 0, 5.5, 0, 3);
    drawChair(5, 0, 6.5, 0, 3);
    drawChair(5, 0, 7.5, 0, 3);

// mesa
    drawTable(3.8, 2.5);
    drawStar(3);
    drawStar(6.75);
    drawStar(4.75);
    
//Segundo andar
    // exposição cima com salão
    glPushMatrix();
    glTranslatef(13.8, 5.25, 35.25);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(14.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    //exposição cima com elevador
    glPushMatrix();
    glTranslatef(16.75, 5.25, 28);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    //elevador com vazio
    glPushMatrix();
    glTranslatef(16.9, 5.25, 25.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.2, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    //vazio com circulacao
    glPushMatrix();
    glTranslatef(13.8, 5.25, 22.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
    glColor3f(1, 0, 0);

    // exposição baixo com salão
    glPushMatrix();
    glTranslatef(6, 5.25, 35.25);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(14.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    //exposição baixo com corredor baixo
    glPushMatrix();
    glTranslatef(3.25, 5.25, 28);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6.5, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // corredor baixo com gabinete
    glPushMatrix();
    glTranslatef(3, 5.25, 25.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // gabinete com sala de jantar
    glPushMatrix();
    glTranslatef(3, 5.25, 19.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // gabinete com circulacao
    glPushMatrix();
    glTranslatef(6, 5.25, 22.5);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(6, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // sala de jantar com jardim
    glPushMatrix();
    glTranslatef(8, 5.25, 14);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(11, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // jardim com circulacao
    glPushMatrix();
    glTranslatef(10.9, 5.25, 19.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(5.8, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // sala de jantar com sala de visita
    glPushMatrix();
    glTranslatef(6.9, 5.25, 8.5);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(13.8, 3.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // sala de visita com emcima
    glPushMatrix();
    glTranslatef(13.8, 5.25, 4.25);
        glRotatef (90, 0,1,0);
        glColor3f(1.0f, 0.5f, 0.0f);
        glScalef(8.5, 3.5, 0.1);
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
              x+lx, cam , z+lz, // pra onde
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
        case GLUT_KEY_PAGE_UP :
            cam += 0.5;
        break;
        case GLUT_KEY_PAGE_DOWN :
            cam -= 0.5;
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
