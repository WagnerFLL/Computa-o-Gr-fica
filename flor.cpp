#include <GL/glut.h>

static int year = 0, day = 0;


void init(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 10.0 };
  GLfloat light_position[] = { 10.0, 0.0, 1.0, 1};
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
}

// Funcao callback chamada para fazer o desenho
void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);

  glPushMatrix();
      glRotatef((GLfloat) year, 1.0, 0.0, 0.0);
      glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
      glColor3d(255,215,0);
      glutSolidSphere(1.0, 20, 16);    /* desenha o sol */
  glPopMatrix();

  glPushMatrix();
      glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
      glTranslatef(2.0, 0.0, 0.0);

      glPushMatrix();

          glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
          glColor3ub(30,144,255);
          glutSolidSphere(0.2, 10, 8); /* planeta 1 */
      glPopMatrix();

      glPushMatrix();
          glColor3ub(255, 0, 0);
          glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
          glTranslatef(0.5, 0.0, 0.0);
          glutSolidSphere(0.05, 10, 8); /* lua 1 */
      glPopMatrix();

      glPushMatrix();
          glColor3ub(255,127,80);
          glRotatef((GLfloat) day, 0.0, 1.0, 1.0);
          glTranslatef(0.4, 0, 0);
          glutSolidSphere(0.025, 10, 8); /* lua 2 */
      glPopMatrix();

      glColor3ub(255, 255, 255);
  glPopMatrix();

  glPushMatrix();
      glColor3ub(255,127,80);
      glRotatef((GLfloat) year, 0.0, (GLfloat) -1.0, 0.0);
      glTranslatef((GLfloat) -3.0, 0.0, 0.0);        /* translada a partir do novo sistema de coordenadas resultante da Rotacao */
      glRotatef((GLfloat) day, 0.0, (GLfloat) -1.0, 0.0);
      glutSolidSphere(0.2, 10, 8); /* desenha o segundo planeta */
  glPopMatrix();

  glPushMatrix();
      glColor3ub(100,207,180);
      glRotatef((GLfloat) year, 0.0, (GLfloat) -1.0, 0.0);
      glTranslatef((GLfloat) -5.0, 0.0, 0.0);        /* translada a partir do novo sistema de coordenadas resultante da Rotacao */
      glRotatef((GLfloat) day, 0.0, (GLfloat) -1.0, 0.0);
      glutSolidSphere(0.2, 10, 8); /* desenha o segundo planeta */
  glPopMatrix();

  glPushMatrix();
      glColor3ub(135,127,80);
      glRotatef((GLfloat) year, 0.0, (GLfloat) -1.0, 0.0);
      glTranslatef((GLfloat) 2.0, 0.0, 0.0);        /* translada a partir do novo sistema de coordenadas resultante da Rotacao */
      glRotatef((GLfloat) day, 0.0, (GLfloat) -1.0, 0.0);
      glutSolidSphere(0.2, 10, 8); /* desenha o segundo planeta */
  glPopMatrix();

  //executa os comandos
  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
  gluLookAt(0.0, 5.0, 7.4, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // posicao da camera
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'y':
        day = (day + 10) % 360;    // % valor do resto
        year = (year + 5) % 360;
        glutPostRedisplay();
        break;
    case 'Y':
        day = (day - 10) % 360;
        year = (year - 5) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
    default:
        break;
  }
}


int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(700, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Rotacao de planetas");

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}
