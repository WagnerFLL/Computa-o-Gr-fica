#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define TELHA    1.0, 0.5, 0.31
#define TELHA2   1.0, 0.39, 0.28
#define CHAO   1.0, 0.86, 0.35

/*
    1º deslocamento em x  =  largura
    2º deslocamento em y  =  altura
    3º deslocamento em z  =  profundidade
*/

int coss[400], sinn[400], lk = 0;



static GLfloat vertices[100]={
  0.0,  20.0, 25.0, /* 0 */
  30.0, 20.0, 25.0, /* 1 no-trash*/
  30.0, 20.0, 15.0, /* 2 trash*/
  30.0,  0.0, 25.0, /* 3 */
  0.0,   0.0, 25.0, /* 4 */
  0.0,  20.0,  -15.0, /* 5 */
  30.0, 20.0,  -15.0, /* 6 */
  30.0,  0.0,  -15.0, /* 7 */
  0.0,   0.0,  -15.0, /* 8 */
  30.0, 30.0, 5.0,  /* 9 trash*/
  -10.0,   20.0,  30.0, /* 10 */
  -10.0,   20.0,  -20.0, /* 11 */
  15.0,   30.0,  30.0, /* 12 */
  40.0,   20.0,  30.0, /* 13 */
  15.0,   30.0,  -20.0, /* 14 */
  40.0,   20.0,  -20.0, /* 15 */
  200.0,   0.0,  -200.0, /* 16 */
  -200.0,   0.0,  200.0, /* 17 */
  200.0,   0.0, -200.0, /* 18 */
  200.0,   0.0,  200.0, /* 19 */

};

static GLubyte frenteIndices[]    = {0,4,3,1};
static GLubyte trasIndices[]      = {5,6,7,8};
static GLubyte esquerdaIndices[]  = {0,5,8,4};
static GLubyte direitaIndices[]   = {1,3,7,6};
static GLubyte topoIndices[]      = {0,1,6,5};
static GLubyte fundoIndices[]     = {3,4,8,7};
static GLubyte telhaEsquerda[]     = {14, 11, 10, 12};
static GLubyte telhaDireita[]     = {12,13, 15,  14};
static GLubyte telhaFrente[]     = {10, 13, 12};
static GLubyte telhaTras[]     = {11, 14, 15};
static GLubyte lage[] = {10, 11, 15, 13};
static GLubyte chao[] = {16, 17, 19, 18};

static int eixoy, eixox;
int largura, altura;
int kx = 15, ky = 40, z = 80;

int ax = 15, az = 0;

int main(int argc, char** argv){
  for (int i = 0; i< 360; i++){
    coss[i] = cos(i) + 25;
    sinn[i] = sin(i) + 25;
  }
  int i;
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (700, 700);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho (-50, 50, -50, 50, -50 , 50);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  largura=w;
  altura=h;
}

void display(void){
  glPushMatrix();
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 3000.0);
  gluLookAt(kx, ky, z, // de onde
            0, 0, 0, //pra onde
            0, 1, 0); // como
  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) eixox, 1.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);


  // glColor3f (CHAO); /* chao */
  // glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, chao);

  glColor3f (AZUL); /* frente */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, frenteIndices);

  glColor3f (AMARELO); /* esquerda */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

  glColor3f (VERMELHO); /* tras */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, trasIndices);

  glColor3f (VERDE); /* direita */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, direitaIndices);

  glColor3f (CYAN); /* topo */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, topoIndices);

  glColor3f (LARANJA); /* fundo */
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, fundoIndices);

  glColor3f (TELHA); /* telhaEsquerda */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, telhaEsquerda);

  glColor3f (TELHA); /* telhaDireita */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, telhaDireita);

  glColor3f (TELHA2); /* telhaFrente */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, telhaFrente);

  glColor3f (TELHA2); /* telhaTras */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, telhaTras);

  glColor3f (TELHA2); /* lage */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, lage);

  glDisableClientState (GL_VERTEX_ARRAY);

  glPopMatrix();
  glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'y':
    eixoy = (eixoy + 5) % 360;
    glutPostRedisplay();
    break;
  case 'Y':
    eixoy = (eixoy - 5) % 360;
    glutPostRedisplay();
    break;
  case 'x':
    eixox = (eixox + 5) % 360;
    glutPostRedisplay();
    break;
  case 'X':
    eixox = (eixox - 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 120.0);
    gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
    break;
  case 'z':
    z += 5;
    glutPostRedisplay();
    break;
  case 'Z':
    z -= 5;
    glutPostRedisplay();
    break;
  case '.':
    kx += 5;
    glutPostRedisplay();
    break;
  case ',':
    kx -= 5;
    glutPostRedisplay();
    break;
  case 'c':
    ky += 5;
    glutPostRedisplay();
    break;
  case 'b':
    ky -= 5;
    if (ky < 25) {
      ky = 25;
    }
    glutPostRedisplay();
    break;
  case 'r':
    lk+=5;
    kx = coss[lk%360];
    ky = sinn[lk%360];
    glutPostRedisplay();
    break;
  case 'o':
    glLoadIdentity();
    glOrtho (-50, 50, -50, 50, -50 , 50);
    glutPostRedisplay();
    break;
  }
}
