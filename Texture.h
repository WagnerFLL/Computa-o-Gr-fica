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

    if (file == NULL)
        return 0;

    data = (unsigned char *) malloc(width * height * 3);
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
}

void FreeTexture(GLuint texture) {
    glDeleteTextures(1, &texture);
}

void loadTextures() {
    texture_id[0] = loadTexture("resources/teto.bmp", 532, 532, 0);
    texture_id[1] = loadTexture("resources/estrela.bmp", 331, 277, 0);
    texture_id[2] = loadTexture("resources/piso_carrara1.bmp", 574, 522, 1);
    texture_id[3] = loadTexture("resources/sample.bmp", 400, 225, 0);
    texture_id[4] = loadTexture("resources/escuro_mesa.bmp", 800, 500, 0);
    texture_id[5] = loadTexture("resources/escada_tapete.bmp", 700, 208, 0);
    texture_id[6] = loadTexture("resources/porta.bmp", 1258, 526, 0);
    texture_id[7] = loadTexture("resources/brasao.bmp", 651, 477, 0);
    texture_id[8] = loadTexture("resources/estatua.bmp", 508, 400, 0);
    texture_id[9] = loadTexture("resources/fachada_parede.bmp", 754, 385, 0);
	texture_id[10] = loadTexture("resources/fachada_parede_superior.bmp", 754, 203, 0);
    texture_id[11] = loadTexture("resources/quadro1.bmp", 795, 687, 0);
	texture_id[12] = loadTexture("resources/quadro2.bmp", 820, 600, 0);
	texture_id[13] = loadTexture("resources/quadro3.bmp", 1067, 676, 0);
	texture_id[14] = loadTexture("resources/quadro4.bmp", 1088, 783, 0);
	texture_id[15] = loadTexture("resources/quadro5.bmp", 1016, 689, 0);
	texture_id[16] = loadTexture("resources/quadro6.bmp", 659, 516, 0);
	texture_id[17] = loadTexture("resources/quadro7.bmp", 1133, 919, 0);
	texture_id[18] = loadTexture("resources/quadro8.bmp", 807, 637, 0);
	texture_id[19] = loadTexture("resources/quadro9.bmp", 703, 593, 0);
	texture_id[20] = loadTexture("resources/quadro10.bmp", 620, 530, 0);
	texture_id[21] = loadTexture("resources/quadro11.bmp", 860, 688, 0);
	texture_id[22] = loadTexture("resources/quadro12.bmp", 256, 206, 0);
	texture_id[23] = loadTexture("resources/quadro13.bmp", 516, 428, 0);
	texture_id[24] = loadTexture("resources/quadro14.bmp", 580, 429, 0);
	texture_id[25] = loadTexture("resources/quadro15.bmp", 944, 748, 0);
	texture_id[26] = loadTexture("resources/quadro16.bmp", 1112, 956, 0);
	texture_id[27] = loadTexture("resources/quadro17.bmp", 580, 429, 0);
	texture_id[28] = loadTexture("resources/quadro18.bmp", 1200, 984, 0);
	texture_id[29] = loadTexture("resources/quadro19.bmp", 660, 555, 0);
	texture_id[30] = loadTexture("resources/capa_livro1.bmp", 339, 262, 0);
	texture_id[31] = loadTexture("resources/capa_livro2.bmp", 598, 444, 0);
	texture_id[32] = loadTexture("resources/capa_livro3.bmp", 472, 324, 0);
	texture_id[33] = loadTexture("resources/capa_livro4.bmp", 432, 296, 0);
	texture_id[34] = loadTexture("resources/capa_livro5.bmp", 435, 299, 0);
	texture_id[35] = loadTexture("resources/capa_livro6.bmp", 621, 424, 0);
	texture_id[36] = loadTexture("resources/quadro_donzela.bmp", 668, 400, 0);

}

void textureEscutcheon() {
    texture = texture_id[7];
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
        glTranslatef(9.4, 11.4, 43.08);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.8);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(0.9, 0.0001, 0.8);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(0.9, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void textureHigherFacade(float x){
    texture = texture_id[10];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, 10.46, 43.09);
        glRotatef(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 1.9);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(6, 0.0001, 1.9);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(6, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureFacade(float x, float y) {
    texture = texture_id[9];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, y, 43.08);
        glRotatef(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 3.7);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(6, 0.0001, 3.7);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(6, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureWall(float x, float z, float width, int floor, int parallel) {

    float y = (0.2 + floor1_height) + 3.5 + ((3.5 + floor2_height) * (floor));
    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotated(90, 1, 0, 0);
        if (parallel)
            glRotated(270, 0, 0, 1);
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

void textureStatue(float x) {
    texture = texture_id[8];
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
        glTranslatef(x - 0.3, 10.8, 43.08);
        glRotatef(-90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.8);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(1, 0.0001, 0.8);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(1, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void textureInnerOrthoWallFront(float x, float floor) {

    float side = 42.92;

    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, 3.7 * floor + 4 + 0.8, side);
        glRotated(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0, 0.0001, 0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(6, 0.0001, 0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(6, 0.0001, 3.8);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, 0.0001, 3.8);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureInnerOrthoWall(float x, float floor, float side) {
    if(side == 0) side = 0.07;
    else side = 42.92;

    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, 3.7 * floor + 4 + 0.8, side);
        glRotated(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0, 0.0001, 0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(4, 0.0001, 0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(4, 0.0001, 3.8);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, 0.0001, 3.8);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureInnerWall(float z, float floor, float side) {
    if(side == 0) side = 0.07;
    else side = 19.92;

    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(side, 3.7 * floor + 4 + 0.8, z);
        glRotated(90, 1, 0, 0);
        glRotated(90, 0, 0, 1);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0, 0.0001, 0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(4.3, 0.0001, 0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(4.3, 0.0001, 3.8);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, 0.0001, 3.8);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureFail(float floor, int p) {
    texture = texture_id[0];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(6.5, (3.7 *(floor + 1)) + wall_height + floor1_height - 0.2, 28 + 0.062 * p);
        glRotated(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0, 0.0001, 0);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(7, 0.0001, 0);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(7, 0.0001, 0.8);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, 0.0001, 0.8);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureFloor() {
    texture = texture_id[2];
    glEnable(GL_TEXTURE_2D);
    for (int j = 0; j < 88 ; ++j) {
        glPushMatrix();
        glTranslatef(0, 1.202, -0.5 + 0.5*j);
        for (int i = 0; i < 40; ++i) {
            glPushMatrix();
                glTranslatef(0.5*i, 0, 0);
                glColor3ub(255, 255, 255);
                glBindTexture(GL_TEXTURE_2D, texture);
                glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex3f(-0, 0.0001, 0.5);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex3f(0.5, 0.0001, 0.5);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex3f(0.5, 0.0001, -0);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex3f(-0, 0.0001, -0);
                glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);
}

void textureFloor2() {
    texture = texture_id[2];
    glEnable(GL_TEXTURE_2D);
    for (int j = 0; j < 87 ; ++j) {
        glPushMatrix();
        glTranslatef(0, 1.2 + 3.71, -0.5 + 0.5*j);
        for (int i = 0; i < 40; ++i) {
            if((-0.5 + 0.5*j) > 21 && (-0.5 + 0.5*j) < 24.6)
                if((0.5*i) > 7.2  && (0.5*i) < 12)
                    continue;
            glPushMatrix();
                glTranslatef(0.5*i, 0, 0);
                glColor3ub(255, 255, 255);
                glBindTexture(GL_TEXTURE_2D, texture);
                glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex3f(-0, 0.0001, 0.5);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex3f(0.5, 0.0001, 0.5);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex3f(0.5, 0.0001, -0);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex3f(-0, 0.0001, -0);
                glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);
}

void textureStair(float y, float z) {
    y += 0.09;
    texture = texture_id[5];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(8.85, y+0.003, z - 0.095);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.20);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(2, 0.0001, 0.20);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(2, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    texture = texture_id[5];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(8.85, y, z + 0.103);
        glRotatef(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.19);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(2, 0.0001, 0.19);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(2, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureStairL(float position, float y, float z) {
    y += 0.09;
    texture = texture_id[5];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(position, y - 0.01, z - 0.18);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.34);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(1, 0.0001, 0.34);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(1, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    texture = texture_id[5];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(position, y - 0.01, z - 0.177);
        glRotatef(90, 1, 0, 0);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.19);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(1, 0.0001, 0.19);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(1, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureBook2(float x, float y, float z, float rotation, int id) {
    texture = texture_id[id + 32];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(rotation, 0, 1, 0);
        glColor3ub(255, 255, 255);
        glTranslatef(-0.15, -0.17, -0.2);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.4);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(0.3, 0.0001, 0.4);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(0.3, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void textureBook1(float x, float y, float z, float rotation, int id) {
    texture = texture_id[id + 29];
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(rotation, 0, 1, 0);
        glColor3ub(255, 255, 255);
        glTranslatef(-0.14,-0.07, -0.1);
        glRotatef(15, 1, 0, 0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, 0.4);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(0.3, 0.0001, 0.4);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(0.3, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void texturePaint(float x, float y, float z, float inclination, int id, float proportion, float size, float rotation, float flip) {
	texture = texture_id[id];
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(rotation, 0, 1, 0);
        glTranslatef(0.5, 0.8, 0.30);
        glRotated(90, 1, 0, 0);
        glRotated(flip, 0, 1, 0);
        glRotated(inclination, 0, 0, 1);

        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-0, 0.0001, size * proportion);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(size, 0.0001, size * proportion);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(size, 0.0001, -0);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-0, 0.0001, -0);
        glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

#endif //COMPUTER_GRAPHICS_TEXTURE_H
