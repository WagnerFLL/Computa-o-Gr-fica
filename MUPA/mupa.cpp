#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <math.h>
#include "texture.cpp"

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=10.0f,z=50.0f;

// angle for rotating
float angle = 0.0f;

float door_angle = 0.0f;

float fovy = 70.0f;

float cam = 2.0f;

GLUquadricObj *quadratic;

void ilumination (void) {}

void init(void) {
    quadratic = gluNewQuadric();
    glClearColor(0.0, 0.7, 1.0, 1.0);
    loadTextures();
    glEnable (GL_DEPTH_TEST);
}

void drawColumn(float x) {
  glPushMatrix();
   glTranslatef(x, 0, 43);
   glRotatef(-90, 1,0,0);
      glColor3f(0.78f, 0.823f, 0.824f);
      gluCylinder(quadratic, 0.28, 0.28, 7, 30, 30);
  glPopMatrix();
}

void textureWall(float x, float z, float width, int floor, int parallel) {
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
    glTranslatef(x, 3.5 + (3.5 * floor), z);
    glRotated(90, 1, 0, 0);
    glRotated(270, 0, 0, parallel);
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D, texture_id[6]);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(0, 0.0001, 3.5);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(width, 0.0001, 3.5);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(width, 0.0001, 0);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(0,0.0001, 0);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void drawOrthoWall(float x, float z, float width, int floor) {
  float relativeX = x + width/2;
  float relativeY = 1.75 + (floor * 3.5);

  glPushMatrix();
  glTranslatef(relativeX, relativeY, z);
      glColor3f(0.7f, 0.7f, 0.7f);
      glScalef(width, 3.5, 0.1);
      glutSolidCube(1.0);
  glPopMatrix();

  textureWall(x, z+0.05, width, floor, 0);
  textureWall(x, z-0.06, width, floor, 0);
}

void drawParallelWall(float x, float z, float width, int floor) {
  float relativeZ = z + width/2;
  float relativeY = 1.75 + (floor * 3.5);

  glPushMatrix();
  glTranslatef(x, relativeY, relativeZ);
      glRotatef (90, 0,1,0);
      glColor3f(0.7f, 0.7f, 0.7f);
      glScalef(width, 3.5, 0.1);
      glutSolidCube(1.0);
  glPopMatrix();

  textureWall(x+0.06, width+z, width, floor, 1);
  textureWall(x-0.06, width+z, width, floor, 1);
}

void drawChair(float x, float  y, float z, int cabeceira, int rotate) {
  glPushMatrix();
  glTranslated(x, y + 0.7, z);
    if(cabeceira)
      glScalef(1,1.5,1);
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
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
    glTranslatef(3.8, 1.11, z);
    glRotated(90, 0, 1, 0);
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D, texture_id[4]);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-0.07, 0.0001, 0.07);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(0.07, 0.0001, 0.07);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(0.07, 0.0001, -0.07);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-0.07,0.0001, -0.07);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void textureFloor() {
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
    glTranslatef(0, 0.2, -0.5);
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D, texture_id[5]);
    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-0, 0.0001, 44);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(20, 0.0001, 44);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(20, 0.0001, -0);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-0,0.0001, -0);
    glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void drawDetail(float x) {
  glPushMatrix();
  glTranslatef(x + 0.25, 9.3, 43);
      glColor3f(0.43f, 0.50f, 0.56f);
      glScalef(0.5, 0.6, 0.1);
      glutSolidCube(1.0);
  glPopMatrix();
}

void drawDoorOrtho(float x, float z, float floor) {
    float doorWidth = 1.25;
    float doorHeight = 2.2;
    float relativeX = x + (doorWidth/2);
    float relativeY = doorHeight/2 + (floor*3.5);
    glPushMatrix();
        glTranslatef(relativeX + ((doorWidth/2) * -1), relativeY, z);
        glRotatef(door_angle, 0,1,0);
        glTranslatef((doorWidth/2), 0, 0);
        glColor3f(0.5f, 0.25f, 0.0);
        glScalef(doorWidth, doorHeight, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
}

void drawDoorParallel(float x, float z, float floor) {
    float doorWidth = 1.25;
    float doorHeight = 2.2;
    float relativeZ = z + (doorWidth/2);
    float relativeY = doorHeight/2 + (floor*3.5);
    glPushMatrix();
        glTranslatef(x, relativeY, relativeZ + ((doorWidth/2) * -1));
        glRotatef(door_angle, 0,1,0);
        glTranslatef(0, 0, (doorWidth/2));
        glRotatef(90, 0,1,0);
        glColor3f(0.5f, 0.25f, 0.0);
        glScalef(doorWidth, doorHeight, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
}

void drawOrthoWallWithDoor(float x, float z, float width, int floor, float doorLocation) {
    float doorHeight = 2.2;
    float doorWidth = 1.25;

    float newWidth = (width/2) - (doorWidth/2);
    float width1 = newWidth * doorLocation;
    float width2 = newWidth * (2 - doorLocation);
    float x1 = x;
    float z1 = z;
    float x2 = x + width1 + doorWidth;
    float z2 = z;

    drawOrthoWall(x1, z1, width1, floor); // parede a esquerda da porta
    drawOrthoWall(x2, z2, width2, floor); // parede a direita da porta

    float relativeX = x + width1 + doorWidth/2; // parede emcima da porta
    float relativeY = 3.5 - ((3.5 - doorHeight)/2) + (floor * 3.5);
    glPushMatrix();
    glTranslatef(relativeX, relativeY, z);
        glColor3f(0.7f, 0.7f, 0.7f);
        glScalef(doorWidth, 3.5 - doorHeight, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    drawDoorOrtho(x + width1, z, floor);
}

void drawParallelWallWithDoor(float x, float z, float width, int floor, float doorLocation) {
    float doorHeight = 2.2;
    float doorWidth = 1.25;

    float newWidth = (width/2) - (doorWidth/2);
    float width1 = newWidth * doorLocation;
    float width2 = newWidth * (2 - doorLocation);
    float x1 = x;
    float z1 = z;
    float x2 = x;
    float z2 = z + width1 + doorWidth;

    drawParallelWall(x1, z1, width1, floor); // parede a esquerda da porta
    drawParallelWall(x2, z2, width2, floor); // parede a direita da porta

    float relativeZ = z + width1 + doorWidth/2; // parede emcima da porta
    float relativeY = 3.5 - ((3.5 - doorHeight)/2) + (floor * 3.5);
    glPushMatrix();
    glTranslatef(x, relativeY, relativeZ);
        glRotatef (90, 0,1,0);
        glColor3f(0.7f, 0.7f, 0.7f);
        glScalef(doorWidth, 3.5 - doorHeight, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    drawDoorParallel(x, z + width1, floor);


}

void draw(){

    // quadro fundo
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
      glTranslatef(4, 2, 0.6);
      glRotated(90, 1, 0, 0);
      glColor3ub(255,255,255);
      glBindTexture(GL_TEXTURE_2D, texture_id[1]);
      glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-2, 0.0001, 1);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(2, 0.0001, 1);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(2, 0.0001, -1);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-2,0.0001, -1);
      glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //  Mesa parte escura
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
      glTranslatef(3.8, 1.08, 5.5);
      glRotated(90, 0, 1, 0);
      glColor3ub(255,255,255);
      glBindTexture(GL_TEXTURE_2D, texture_id[3]);
      glBegin(GL_QUADS);  // floor
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-2.9, 0.0001, 1.4);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(2.9, 0.0001, 1.4);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(2.9, 0.0001, -1.4);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-2.9,0.0001, -1.4);
      glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

//Primeiro andar
    // Back side floor
    glPushMatrix();
    glTranslatef(10, 4.5, 0);
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(20, 9, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(0,4.5, 21.5);
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(0.1, 9, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right side floor
    glPushMatrix();
    glTranslatef(20, 4.5, 21.5);
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(0.1, 9, 43);
        glutSolidCube(1.0);
    glPopMatrix();

    //varanda com exposicao
    drawOrthoWallWithDoor(6, 39, 2.6666, 0, 1);
    drawOrthoWallWithDoor(8.6666, 39, 2.6666, 0, 1);
    drawOrthoWallWithDoor(11.3333, 39, 2.6666, 0, 1);

    // salao despacho com gabinete e jardim
    drawParallelWall(7.5, 0, 19.5, 0);

    // salão de despacho com direitoria
    drawOrthoWallWithDoor(0,13.5, 6, 0, 1);

    // diretoria com corredor
    drawParallelWallWithDoor(6, 13.5, 6, 0, 1);

    // diretoria com atelier
    drawOrthoWallWithDoor(0, 19.5, 6, 0, 1);

    // atelier com corredor
    drawParallelWallWithDoor(6, 19.5, 6, 0, 1);

    // atelier com sala protocolo
    drawOrthoWallWithDoor(0, 25.5, 6, 0, 0.8);

    // jardim com costas da escada
    drawOrthoWall(7.5, 19.5, 6.3, 0);

    // por tras da recpção
    drawParallelWall(13.8, 19.5, 6, 0);

    // sec. cult com elevador
    drawOrthoWallWithDoor(13.8, 25.5, 6.2, 0, 1.1);

    // elevador com reserva técnica
    drawOrthoWallWithDoor(13.5, 28, 6.5, 0, 1.1);

    // sala protocolo com exposicao 1
    drawOrthoWallWithDoor(0, 28, 6.5, 0, 0.8);

    // exposicao1 com salao
    drawParallelWallWithDoor(6, 28, 7, 0, 0.1);

    // exposicao1 com exposicao2
    drawOrthoWallWithDoor(0, 35, 6, 0, 1);

    // exposicao 2 com salao
    drawParallelWallWithDoor(6, 35, 8, 0, 0.1);

    // mini auditorio com salao
    drawParallelWallWithDoor(13.8, 35, 8, 0, 0.1);

    // mini auditorio com reserva tecnica
    drawOrthoWallWithDoor(13.8, 35, 6, 0, 1);

    // reserva téc. com salão
    drawParallelWallWithDoor(13.8, 28, 7, 0, 0.1);


// floor 1
    // Back
    glPushMatrix();
    glTranslatef(10, 3.6, 10.75);
        glColor3f(0.8f, 0.823f, 0.824f);
        glScalef(20, 0.2, 21.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // Front
    glPushMatrix();
    glTranslatef(10, 3.6, 34);
        glColor3f(0.8f, 0.823f, 0.824f);
        glScalef(20, 0.2, 18.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right
    glPushMatrix();
    glTranslatef(3.8, 3.6, 22.5);
        glColor3f(0.8f, 0.823f, 0.824f);
        glScalef(7.6, 0.2, 6);
        glutSolidCube(1.0);
    glPopMatrix();

    // Left
    glPushMatrix();
    glTranslatef(15.8, 3.6, 22.5);
        glColor3f(0.8f, 0.823f, 0.824f);
        glScalef(7.6, 0.2, 6);
        glutSolidCube(1.0);
    glPopMatrix();

    // piso
    glPushMatrix();
    glTranslatef(10, 0.1, 21.5);
        glColor3f(0.8f, 0.823f, 0.824f);
        glScalef(20, 0.2, 44);
        glutSolidCube(1.0);
    glPopMatrix();
    textureFloor();

    // lage
    glPushMatrix();
    glTranslatef(10, 7.1, 21.5);
        glColor3f(0.8f, 0.823f, 0.824f);
        glScalef(20, 0.2, 43.5);
        glutSolidCube(1.0);
    glPopMatrix();

// ESCADA
    float zBase = 25.5, yBase = 0.25;

    for (int i = 0; i < 21; i++, zBase -= 0.2, yBase += 0.1){
      glPushMatrix();
      glTranslatef(9.9, yBase, zBase);
          glColor3f(1.0f, 0.85f, 0.8f);
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
          glColor3f(1.0f, 0.85f, 0.8f);
          glScalef(1, 0.15, 0.35);
          glutSolidCube(1.0);
      glPopMatrix();
    }

    zBase = 21.5;
    yBase = 2.25;

    for (int i = 0; i < 12; i++, zBase += 0.334, yBase += 0.12){
      glPushMatrix();
      glTranslatef(8.1, yBase, zBase);
          glColor3f(1.0f, 0.85f, 0.8f);
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
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(6, 7, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17, 3.5, 43);
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(6, 7, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // Top
    glPushMatrix();
    glTranslatef(10, 8, 43);
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(20, 2, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // middle
    glPushMatrix();
    glTranslatef(9.85, 9.62, 43);
        glColor3f(0.43f, 0.50f, 0.56f);
        glScalef(1.25, 1.25, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.85, 10.1, 43);
    glRotated(45,0,0,1);
    glColor3f(0.43f, 0.50f, 0.56f);
    glScalef(1.25, 1.25, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // details
    drawDetail(0);
    drawDetail(5.75);
    drawDetail(13.75);
    drawDetail(19.5);

    // grade
    float px = 6.4;
    for (int i = 0; i < 74; i++, px += 0.1 ){
      glPushMatrix();
      glTranslatef(px, 4, 43);
          glColor3f(0.5f, 0.6f, 0.6f);
          glScalef(0.02, 0.8, 0.02);
          glutSolidCube(1.0);
      glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(12.1, 4.4, 43);
        glColor3f(0.5f, 0.6f, 0.6f);
        glScalef(12, 0.02, 0.02);
        glutSolidCube(1.0);
    glPopMatrix();

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
    drawStar(3.75);
    drawStar(7.5);
    drawStar(5.5);

//Segundo andar

    //varanda com exposicao
    drawOrthoWallWithDoor(6, 39, 2.6666, 1, 1);
    drawOrthoWallWithDoor(8.6666, 39, 2.6666, 1, 1);
    drawOrthoWallWithDoor(11.3333, 39, 2.6666, 1, 1);

    // exposição cima com salão
    drawParallelWallWithDoor(13.8, 28, 15, 1, 1);

    //exposição cima com elevador
    drawOrthoWallWithDoor(13.5, 28, 6.5, 1, 1);

    //elevador com vazio
    drawOrthoWall(13.8, 25.5, 6.2, 1);

    // atras da escada
    drawOrthoWall(6, 19.5, 2, 1);

    //vazio com circulacao
    drawParallelWall(13.8, 19.5, 6, 1);

    // exposição baixo com salão
    drawParallelWallWithDoor(6, 28, 15, 1, 0.1);

    //exposição baixo com corredor baixo
    drawOrthoWallWithDoor(0, 28, 6.5, 1, 0.9);

    // corredor baixo com gabinete
    drawOrthoWallWithDoor(0, 25.5, 6, 1, 0.9);

    // gabinete com sala de jantar
    drawOrthoWallWithDoor(0, 19.5, 6, 1, 0.1);

    // gabinete com circulacao
    drawParallelWall(6, 19.5, 6, 1);

    // sala de jantar com jardim
    drawParallelWall(8, 8.5, 11, 1);

    // jardim com circulacao
    drawOrthoWall(8, 19.5, 5.8, 1);

    // sala de jantar com sala de visita
    drawOrthoWallWithDoor(0, 8.5, 13.8, 1, 0.6);

    // sala de visita com emcima
    drawParallelWall(13.8, 0, 8.5, 1);

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
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    ilumination();
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
    // drawDoor();

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

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
