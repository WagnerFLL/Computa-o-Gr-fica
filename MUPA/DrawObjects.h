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
	glTranslatef(3.8, 1.11 + floor1_height, z);
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

void detailColumn(float x, float y, int l) {
    glPushMatrix();
    glTranslatef(x, y, 43);
    glScalef(0.75 - (l * 0.20), 0.2, 0.75 - (l * 0.20));
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawColumn(float x) {
	glPushMatrix();
	glTranslatef(x, 0 + floor1_height, 43);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.78f, 0.823f, 0.824f);
	gluCylinder(quadratic, 0.28, 0.28, 7 + floor2_thickness + floor2_height, 30, 30);
	glPopMatrix();

	detailColumn(x, 4.6, 0);
	detailColumn(x, 4.4, 1);
	detailColumn(x, 1.5, 1);
	detailColumn(x, 1.3, 0);

    detailColumn(x, 8.3, 0);
    detailColumn(x, 8.1, 1);
    detailColumn(x, 5.2, 1);
    detailColumn(x, 5, 0);
}

void drawDetail(float x) {
	glPushMatrix();
	glTranslatef(x + 0.25, 9.3 + floor1_height + floor2_thickness, 43);
	glColor3ub(239, 239, 239);
	glScalef(0.5, 0.6, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

    texture = texture_id[9];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x - 0.01, 9.6 + floor1_height + floor2_thickness , 43.07);
    glRotatef(90, 1, 0, 0);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0, 0.0001, 0.5);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.52, 0.0001, 0.5);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.52, 0.0001, -0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0, 0.0001, -0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void drawLamp(int scaley, int scalex, GLfloat r, float x, float y, float z) {
	glPushMatrix();
		glColor3ub(255, 255, 0);
		glTranslatef(x, y, z);
		glRotatef(180, 1, 0, 0);
		int i, j;
		GLfloat v[scalex*scaley][3];

		for (i=0; i<scalex; ++i) {
			for (j=0; j<scaley; ++j) {
				v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
				v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
				v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
			}
		}

		glBegin(GL_QUADS);
		for (i=0; i<scalex-1; ++i) {
			for (j=0; j<scaley; ++j) {
				glVertex3fv(v[i*scaley+j]);
				glVertex3fv(v[i*scaley+(j+1)%scaley]);
				glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
				glVertex3fv(v[(i+1)*scaley+j]);
			}
		}
		glEnd();
	glPopMatrix();
}

void drawPaintStand(float x, float y, float z, float rotation, int id, float proportion, float flip) {

	float size = 1;
	int standColorR = 106, standColorG = 53, standColorB = 53;

	texturePaint(x, y, z, 15, id, proportion, size, rotation, flip);
	disableLight();
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(10, 1, 0, 0);
	glTranslatef(0, 0, -0.2);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.1, 2, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, 0, 0.3);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.1, 2.2, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(-15, 1, 0, 0);
	glRotatef(-10, 0, 0, 1);
	glTranslatef(-0.3, 0, 0.3);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.1, 2.25, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(-15, 1, 0, 0);
	glRotatef(10, 0, 0, 1);
	glTranslatef(0.3, 0, 0.3);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.1, 2.25, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, 1, 0.3);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.3, 0.3, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.3, 0.5);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(1, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	enableLight();
}

void drawBookStand1(float x, float y, float z, float rotation) {

	int standColorR = 106, standColorG = 53, standColorB = 53;

	//livro
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0,-0.17, 0.08);
	glRotatef(15, 1, 0, 0);
	glColor3ub(223, 213, 208);
	glScalef(0.3, 0.1, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	//apoio do livro
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -0.27, 0.3);
	glRotatef(15, 1, 0, 0);
	glColor3ub(standColorR - 30, standColorG - 10, standColorB - 10);
	glScalef(0.7, 0.03, 0.03);
	glutSolidCube(1.0);
	glPopMatrix();

	//apoio emcima da base
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -0.25, 0);
	glRotatef(15, 1, 0, 0);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.7, 0.1, 0.7);
	glutSolidCube(1.0);
	glPopMatrix();

	//corpo
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -0.65 , 0);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.3, 0.8, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	//base
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -1, 0);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.4, 0.1, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

}

void drawBookStand2(float x, float y, float z, float rotation) {

	int standColorR = 70, standColorG = 70, standColorB = 70;

	//vidro
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -0.05, 0);
	glScalef(0.6, 0.4, 0.6);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutWireCube(1.0);
	glPopMatrix();

	//livro
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0,-0.22, 0);
	glColor3ub(223, 213, 208);
	glScalef(0.3, 0.07, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	//corpo
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -0.65 , 0);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.6, 0.8, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	//base
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(0, -1, 0);
	glColor3ub(standColorR, standColorG, standColorB);
	glScalef(0.7, 0.1, 0.7);
	glutSolidCube(1.0);
	glPopMatrix();

}



#endif //COMPUTER_GRAPHICS_DRAWOBJECTS_H
