//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_TEXTURE_H
#define COMPUTER_GRAPHICS_TEXTURE_H


GLuint loadTexture(const char *filename, int width, int height, int mode) {

	GLuint texture;

	unsigned char *data;

	FILE *file;

	file = fopen(filename, "rb");

	if (file == NULL) return 0;

	data = (unsigned char *) malloc(width * height * 3);
	//int size = fseek(file,);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	for (int i = 0; i < width * height; ++i) {
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;

	void FreeTexture( GLuint texture )
	{
		glDeleteTextures( 1, &texture ); //  Delete our texture, simple enough.
	}

	void loadTextures() {
		texture_id[0] = loadTexture("resources/teto.bmp", 532, 532, 0);
		texture_id[1] = loadTexture("resources/estrela.bmp", 331, 277, 0);
		texture_id[2] = loadTexture("resources/piso_carrara1.bmp", 574, 522, 1);
		texture_id[3] = loadTexture("resources/sample.bmp", 400, 225, 0);
		texture_id[4] = loadTexture("resources/escuro_mesa.bmp", 800, 500, 0);
	}


	void textureWall(float x, float z, float width, int floor, int parallel) {

		float y = (0.2 + floor1_height) + 3.5 + ((3.5 + floor2_height) * (floor));


		texture = texture_id[0];
		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotated(90, 1, 0, 0);
		glRotated(270, 0, 0, parallel);
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, texture);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0, 0.0001, 3.5);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(width, 0.0001, 3.5);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(width, 0.0001, 0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0, 0.0001, 0);
		glEnd();

		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	void textureFloor() {
		texture = texture_id[2];
		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslatef(0, 1.2, -0.5);
		glColor3ub(255, 255, 255);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0, 0.0001, 44);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(20, 0.0001, 44);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(20, 0.0001, -0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0, 0.0001, -0);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}
#endif //COMPUTER_GRAPHICS_TEXTURE_H
