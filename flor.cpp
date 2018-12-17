#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;
int direction= 1;

int frames = 0;

int petals = 5;

void trocaDirecao(int bt, int st, int x, int y) {
	if (bt == GLUT_LEFT_BUTTON)
		if(st == GLUT_DOWN)direction= 1;

	if (bt == GLUT_RIGHT_BUTTON)
		if (st == GLUT_DOWN)	direction= -1;
}

void florzinha() {

	glColor3ub(81, 60, 59);
	glBegin(GL_POLYGON);
		glVertex2f(-0.05f, 0);
		glVertex2f(0.05f, 0);
		glVertex2f(0.02f, 3);
		glVertex2f(-0.02f, 3);
	glEnd();

	glTranslatef(0, 3, 0);

	glRotated((direction * (frames * (180.0/70))), 0, 0, 1);

	glColor3ub(2, 255, 107);
	for(int i = 0; i < petals; i++) {
		glColor3ub(25*i, 5*i, 45*i);
		glRotated(72, 0, 0, 1);
		glBegin(GL_POLYGON);
			glVertex2f(0,0);
			glVertex2f(0.5f, 0.4f);
			glVertex2f(1.5f,0);
			glVertex2f(0.5f, -0.4f);
		glEnd();
	}

}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslated(3.5,-1,1);

	glutMouseFunc(trocaDirecao);

	florzinha();
	glPopMatrix();
	glutSwapBuffers();

}

void stepFrame(int v) {
    frames++;
		petals++;
    glutPostRedisplay();
    glutTimerFunc(20,stepFrame,0);
}


void init() {
	glClearColor(1.0f, 1.0f, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1120,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Flor de abril");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(20,stepFrame,0);

    glutMainLoop();
    return 0;
}
