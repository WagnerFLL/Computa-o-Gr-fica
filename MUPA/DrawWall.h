//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_DRAWWALL_H
#define COMPUTER_GRAPHICS_DRAWWALL_H

void drawOrthoWall(float x, float z, float width, int floor) {
	float relativeX = x + width / 2;
	float relativeY = 1.75 + (floor * (3.5 + floor2_thickness)) + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(relativeX, relativeY, z);
    glColor3ub(223, 213, 208);
	glScalef(width, 3.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

    textureWall(x, z + 0.062, width, floor, 0);
    textureWall(x, z - 0.06, width, floor, 0);
}

void drawParallelWall(float x, float z, float width, int floor) {
	float relativeZ = z + width / 2;
	float relativeY = 1.75 + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(x, relativeY, relativeZ);
	glRotatef(90, 0, 1, 0);
    glColor3ub(223, 213, 208);
	glScalef(width, 3.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

    textureWall(x + 0.06, width + z, width, floor, 1);
    textureWall(x - 0.06, width + z, width, floor, 1);
}

void drawDoorOrtho(float x, float z, float floor) {
	float doorWidth = 1.25;
	float doorHeight = 2.2;
	float relativeX = x + (doorWidth / 2);
	float relativeY = doorHeight / 2
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;


    texture = texture_id[6];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(relativeX - (doorWidth / 2) , 1.2 + 3.7 * floor, z);
    glRotatef(90, 0, 1, 0);
    glRotatef(door_angle, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0, 0.0001, doorWidth);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(doorHeight, 0.0001, doorWidth);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(doorHeight, 0.0001, -0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0, 0.0001, -0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawDoorParallel(float x, float z, float floor) {
	float doorWidth = 1.25;
	float doorHeight = 2.2;
	float relativeZ = z + (doorWidth / 2);
	float relativeY = doorHeight / 2
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

    texture = texture_id[6];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x, 1.2 + 3.7 * floor, z);
    glRotatef(door_angle, 0, 1, 0);
    glRotatef(90, 0, 0, 1);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0, 0.0001, doorWidth);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(doorHeight, 0.0001, doorWidth);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(doorHeight, 0.0001, -0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0, 0.0001, -0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void drawOrthoWallWithDoor(float x, float z, float width, int floor, float doorLocation) {
	float doorHeight = 2.2;
	float doorWidth = 1.25;

	float newWidth = (width / 2) - (doorWidth / 2);
	float width1 = newWidth * doorLocation;
	float width2 = newWidth * (2 - doorLocation);
	float x1 = x;
	float z1 = z;
	float x2 = x + width1 + doorWidth;
	float z2 = z;

	drawOrthoWall(x1, z1, width1, floor); // parede a esquerda da porta
	drawOrthoWall(x2, z2, width2, floor); // parede a direita da porta

	float relativeX = x + width1 + doorWidth / 2; // parede emcima da porta
	float relativeY = 3.5 - ((3.5 - doorHeight) / 2)
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;

	glPushMatrix();
	glTranslatef(relativeX, relativeY, z);
    glColor3ub(223, 213, 208);
	glScalef(doorWidth, 3.5 - doorHeight, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x+width1, 4.7 + (3.7*floor), z+0.062);
    glRotated(90, 1, 0, 0);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.7 - doorHeight, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.7 - doorHeight, 0.0001, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0.0001, 0);
    glEnd();

    glPopMatrix();

    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x+width1, 4.7 + (3.7*floor), z-0.06);
    glRotated(90, 1, 0, 0);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.7 - doorHeight, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.7 - doorHeight, 0.0001, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0.0001, 0);
    glEnd();

    glPopMatrix();

    if (z < 38)
	    drawDoorOrtho(x + width1, z, floor);
}

void drawParallelWallWithDoor(float x, float z, float width, int floor, float doorLocation) {
	float doorHeight = 2.2;
	float doorWidth = 1.25;

	float newWidth = (width / 2) - (doorWidth / 2);
	float width1 = newWidth * doorLocation;
	float width2 = newWidth * (2 - doorLocation);
	float x1 = x;
	float z1 = z;
	float x2 = x;
	float z2 = z + width1 + doorWidth;

	drawParallelWall(x1, z1, width1, floor); // parede a esquerda da porta
	drawParallelWall(x2, z2, width2, floor); // parede a direita da porta

	float relativeZ = z + width1 + doorWidth / 2; // parede emcima da porta
	float relativeY = 3.5 - ((3.5 - doorHeight) / 2)
					  + (floor * (3.5 + floor2_thickness))
					  + wall_height + floor1_height;


	glPushMatrix();
	glTranslatef(x, relativeY, relativeZ);
	glRotatef(90, 0, 1, 0);
    glColor3ub(223, 213, 208);
	glScalef(doorWidth, 3.5 - doorHeight, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

    if(z1 < 21) z1 += 2;
    if(x > 7 && floor == 1) z1 += 5.75;

    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x+0.06, 4.75 + (3.7*floor), z1+doorWidth+1.23);
    glRotated(90, 1, 0, 0);
    glRotated(270, 0, 0, 1);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(doorHeight, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(doorHeight, 0.0001, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0.0001, 0);
    glEnd();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(x-0.06, 4.75 + (3.7*floor), z1+doorWidth+1.23);
    glRotated(90, 1, 0, 0);
    glRotated(270, 0, 0, 1);
    glColor3ub(255, 255, 255);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(doorHeight, 0.0001, doorWidth+0.1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(doorHeight, 0.0001, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0.0001, 0);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

	drawDoorParallel(x, z + width1, floor);
}

#endif //COMPUTER_GRAPHICS_DRAWWALL_H
