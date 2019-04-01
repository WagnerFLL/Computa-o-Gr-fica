//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_LIGHTNING_H
#define COMPUTER_GRAPHICS_LIGHTNING_H

void lightsSetup()
{
	GLfloat lightSpotCutoff = 90, attenuation = 0.25;
	GLfloat materialAmbientAndDiffuse[] = {1, 1, 1, 1};
	GLfloat materialSpecular[] = {1, 1, 1, 1};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbientAndDiffuse); // Defines objects reflection to ambient and diffuse light
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular); // Defines objects reflection to specular light
	glMaterialf(GL_FRONT, GL_SHININESS, 50); // Defines objects level of reflection (0 to 128)

	GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 1};
	GLfloat lightDiffuse[] = {1.0, 1.0, 1.0, 1};
	GLfloat lightSpecular[] = {1.0, 1.0, 1.0, 1};
	GLfloat lightPosition[] = {10, 7, 23, 1};
	GLfloat lightDirection[] = {0, -1, 0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, attenuation);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);

	glPushMatrix();
		glColor3ub(255, 255, 0);
		glTranslatef(lightPosition[0], lightPosition[1] + 1.1, lightPosition[2]);
		glutSolidSphere(0.5, 100, 100);
	glPopMatrix();
}

void ilumination (void) {
	GLfloat ambientLight[4]={0.3,0.3,0.3,0.2};
	GLfloat diffuseLight[4]={0.3,0.3,0.3,0.2};
	GLfloat specularLight[4]={0.3,0.3,0.3,0.2};
	GLfloat lightPosition[4]={0.0, 1.0, 0.0, 0.2};
	GLfloat specularity[4]={0.1,0.1,0.1,1};

	glMaterialfv(GL_FRONT,GL_SPECULAR, specularity);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight );
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight );
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition );
	//glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, lightSpotCutoff);
}


#endif //COMPUTER_GRAPHICS_LIGHTNING_H
