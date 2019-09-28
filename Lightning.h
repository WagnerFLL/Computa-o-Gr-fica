//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_LIGHTNING_H
#define COMPUTER_GRAPHICS_LIGHTNING_H

void lightsSetup()
{
	GLfloat lightSpotCutoff = 180, attenuation = 0.60, exponent = 30;
	GLfloat materialAmbientAndDiffuse[] = {1, 1, 1, 1};
	GLfloat materialSpecular[] = {1, 1, 1, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialAmbientAndDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 70);

	GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 0.6};
	GLfloat lightDiffuse[] = {1.0, 1.0, 1.0, 1};
	GLfloat lightSpecular[] = {1.0, 1.0, 1.0, 1};
	GLfloat lightDirection[] = {0, -1, 0};

	GLfloat light0Position[] = {3.75, 3.3 + 1.0, 6.75, 1};
	GLfloat light1Position[] = {10, 3.3 + 1.0, 31.25, 1};
	GLfloat light2Position[] = {2.6, 7.0 + 1.0 + 0.2, 36.25, 1};
	GLfloat light3Position[] = {10, 7.0 + 1.0 + 0.2, 31.25, 1};
	GLfloat light4Position[] = {17, 7.0 + 1.0 + 0.2, 36.25, 1};
	GLfloat light5Position[] = {10, 7.0 + 1.0 + 0.2, 24, 1};

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, exponent);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);

	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, exponent);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT1, GL_POSITION, light1Position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection);

	glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, exponent);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT2, GL_POSITION, light2Position);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightDirection);

	glLightfv(GL_LIGHT3, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, exponent);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT3, GL_POSITION, light3Position);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, lightDirection);

	glLightfv(GL_LIGHT4, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, exponent);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT4, GL_POSITION, light4Position);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, lightDirection);

	glLightfv(GL_LIGHT5, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT5, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, exponent);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT5, GL_POSITION, light5Position);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, lightDirection);
	drawLamp(50, 50, 0.5, light0Position[0], light0Position[1] + 0.5, light0Position[2]);
	drawLamp(50, 50, 0.5, light1Position[0], light1Position[1] + 0.5, light1Position[2]);
	drawLamp(50, 50, 0.5, light2Position[0], light2Position[1] + 0.5, light2Position[2]);
	drawLamp(50, 50, 0.5, light3Position[0], light3Position[1] + 0.5, light3Position[2]);
	drawLamp(50, 50, 0.5, light4Position[0], light4Position[1] + 0.5, light4Position[2]);
	drawLamp(50, 50, 0.5, light5Position[0], light5Position[1] + 0.5, light5Position[2]);

}


#endif //COMPUTER_GRAPHICS_LIGHTNING_H
