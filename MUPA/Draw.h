//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_DRAW_H
#define COMPUTER_GRAPHICS_DRAW_H


void draw() {

	// quadro fundo
	texture = texture_id[3];
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(4, 2 + floor1_height, 0.6);
	glRotated(90, 1, 0, 0);
	glColor3ub(255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2, 0.0001, -1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2, 0.0001, -1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2, 0.0001, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2, 0.0001, 1);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//  Mesa parte escura
	texture = texture_id[4];
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(3.8, 1.08 + floor1_height, 5.5);
	glRotated(90, 0, 1, 0);
	glColor3ub(255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);  // floor
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2.9, 0.0001, 1.4);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.9, 0.0001, 1.4);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.9, 0.0001, -1.4);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2.9, 0.0001, -1.4);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

//Primeiro andar
	// Back side floor
	glPushMatrix();
	glTranslatef(10, 4.5 + floor1_height, 0);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(20, 9, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	// Right side floor
	glPushMatrix();
	glTranslatef(0, 4.5 + floor1_height, 21.5);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(0.1, 9, 43);
	glutSolidCube(1.0);
	glPopMatrix();

	// Right side floor
	glPushMatrix();
	glTranslatef(20, 4.5 + floor1_height, 21.5);
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
	drawOrthoWallWithDoor(0, 13.5, 6, 0, 1);

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
	drawOrthoWallWithDoor(13.8, 35, 6.2, 0, 1);

	// reserva téc. com salão
	drawParallelWallWithDoor(13.8, 28, 7, 0, 0.1);

	//mini parede salão com escada esquerda
	drawOrthoWall(8, 28, 1, 0);

	//mini parede salão com escada direita
	drawOrthoWall(11, 28, 1, 0);

	glPushMatrix();
	glTranslatef(10, 3.1 + wall_height + floor1_height, 28);
	glColor3f(0.7f, 0.7f, 0.7f);
	glScalef(7, 0.8, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();


// floor 1
	// Back
	glPushMatrix();
	glTranslatef(10, 3.6 + floor1_height + floor2_height, 10.75);
	glColor3f(0.8f, 0.823f, 0.824f);
	glScalef(20, 0.2, 21.5);
	glutSolidCube(1.0);
	glPopMatrix();

	// Front
	glPushMatrix();
	glTranslatef(10, 3.6 + floor1_height + floor2_height, 34);
	glColor3f(0.8f, 0.823f, 0.824f);
	glScalef(20, 0.2, 18.5);
	glutSolidCube(1.0);
	glPopMatrix();

	// Right
	glPushMatrix();
	glTranslatef(3.8, 3.6 + floor1_height + floor2_height, 22.5);
	glColor3f(0.8f, 0.823f, 0.824f);
	glScalef(7.6, 0.2, 6);
	glutSolidCube(1.0);
	glPopMatrix();

	// Left
	glPushMatrix();
	glTranslatef(15.8, 3.6 + floor1_height + floor2_height, 22.5);
	glColor3f(0.8f, 0.823f, 0.824f);
	glScalef(7.6, 0.2, 6);
	glutSolidCube(1.0);
	glPopMatrix();

	// piso
	glPushMatrix();
	glTranslatef(10, 0.1 + floor1_height / 2, 21.5);
	glColor3f(0.8f, 0.823f, 0.824f);
	glScalef(20, 0.2 + floor1_height, 44);
	glutSolidCube(1.0);
	glPopMatrix();

	textureFloor();

	// lage
	glPushMatrix();
	glTranslatef(10, 7.1 + floor1_height + floor2_height + floor2_thickness, 21.5);
	glColor3f(0.8f, 0.823f, 0.824f);
	glScalef(20, 0.2, 43.5);
	glutSolidCube(1.0);
	glPopMatrix();

// ESCADA
	float zBase = 25.5, yBase = 0.45;

	for (int i = 0; i < 21; i++, zBase -= 0.2, yBase += 0.1) {
		glPushMatrix();
		glTranslatef(9.85, yBase + floor1_height, zBase);
		glColor3f(1.0f, 0.85f, 0.8f);
		glScalef(2, 0.175, 0.2);
		glutSolidCube(1.0);
		glPopMatrix();
	}

	// floor escada
	glPushMatrix();
	glTranslatef(9.9, 2.2 + floor1_height, 20.5);
	glColor3f(0.5f, 0.5f, 0.5f);
	glScalef(4.5, 0.2, 2);
	glutSolidCube(1.0);
	glPopMatrix();

	zBase = 21.5;
	yBase = 2.45;

	for (int i = 0; i < 12; i++, zBase += 0.334, yBase += 0.12) {
		glPushMatrix();
		glTranslatef(11.6, yBase + floor1_height, zBase);
		glColor3f(1.0f, 0.85f, 0.8f);
		glScalef(1, 0.15, 0.35);
		glutSolidCube(1.0);
		glPopMatrix();
	}

	zBase = 21.5;
	yBase = 2.45;

	for (int i = 0; i < 12; i++, zBase += 0.334, yBase += 0.12) {
		glPushMatrix();
		glTranslatef(8.1, yBase + floor1_height, zBase);
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
	glTranslatef(3, 3.5 + floor1_height + floor2_thickness + floor2_height, 43);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(6, 7 + floor2_thickness, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17, 3.5 + floor1_height + floor2_thickness + floor2_height, 43);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(6, 7 + floor2_thickness, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	// Top
	glPushMatrix();
	glTranslatef(10, 8 + floor1_height + floor2_thickness + floor2_height + 0.1f, 43);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(20, 2, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	// middle
	glPushMatrix();
	glTranslatef(9.85, 9.62 + floor1_height + floor2_thickness, 43);
	glColor3f(0.43f, 0.50f, 0.56f);
	glScalef(1.25, 1.25, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.85, 10.1 + floor1_height + floor2_thickness, 43);
	glRotated(45, 0, 0, 1);
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
	for (int i = 0; i < 74; i++, px += 0.1) {
		glPushMatrix();
		glTranslatef(px, 4 + floor1_height + floor2_thickness, 43);
		glColor3f(0.5f, 0.6f, 0.6f);
		glScalef(0.02, 0.8, 0.02);
		glutSolidCube(1.0);
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(12.1, 4.4 + floor1_height + floor2_thickness, 43);
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

#endif //COMPUTER_GRAPHICS_DRAW_H