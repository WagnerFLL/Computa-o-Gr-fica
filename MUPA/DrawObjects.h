//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_DRAWOBJECTS_H
#define COMPUTER_GRAPHICS_DRAWOBJECTS_H

void drawChair(float x, float y, float z, int cabeceira, int rotate) {

	glPushMatrix();

	glTranslated(x, y + 0.7 + floor1_height, z);
	if (cabeceira)
		glScalef(1, 1.5, 1);
	glRotatef(rotate * 90, 0, 1, 0);
	if (rotate == 3)
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

void drawTable(float x, float z) {

	glPushMatrix();
	// tampa
	glPushMatrix();
	glTranslatef(x, 1 + floor1_height, z + 3);
	glPushMatrix();
	glColor3f(0.3f, 0.2f, 0.1f);
	glScalef(3, 0.05, 6);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, 1.05 + floor1_height, z + 3);
	glPushMatrix();
	glColor3f(0.35f, 0.3f, 0.2f);
	glScalef(2.8, 0.05, 5.8);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	// pés
	glPushMatrix();
	glTranslatef(x - 1.45, 0.5 + floor1_height, z + 0.05);
	glPushMatrix();
	glColor3f(0.3f, 0.2f, 0.1f);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x - 1.45, 0.5 + floor1_height, z + 6 - 0.05);
	glPushMatrix();
	glColor3f(0.3f, 0.2f, 0.1f);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 1.45, 0.5 + floor1_height, z + 0.05);
	glPushMatrix();
	glColor3f(0.3f, 0.2f, 0.1f);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 1.45, 0.5 + floor1_height, z + 6 - 0.05);
	glPushMatrix();
	glColor3f(0.3f, 0.2f, 0.1f);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}

void drawStar(float z) {

	texture = texture_id[1];

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(3.8, 1.11 + floor1_height + floor2_thickness, z);
	glRotated(90, 0, 1, 0);
	glColor3ub(255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.07, 0.0001, 0.07);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.07, 0.0001, 0.07);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.07, 0.0001, -0.07);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.07, 0.0001, -0.07);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void drawColumn(float x) {
	glPushMatrix();
	glTranslatef(x, 0 + floor1_height, 43);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.78f, 0.823f, 0.824f);
	gluCylinder(quadratic, 0.28, 0.28, 7 + floor2_thickness + floor2_height, 30, 30);
	glPopMatrix();
}

void drawDetail(float x) {
	glPushMatrix();
	glTranslatef(x + 0.25, 9.3 + floor1_height + floor2_thickness, 43);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(0.5, 0.6, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
}

#endif //COMPUTER_GRAPHICS_DRAWOBJECTS_H
