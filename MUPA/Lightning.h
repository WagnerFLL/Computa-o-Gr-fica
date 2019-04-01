//
// Created by lucas on 3/31/2019.
//

#ifndef COMPUTER_GRAPHICS_LIGHTNING_H
#define COMPUTER_GRAPHICS_LIGHTNING_H

void lightsSetup()
{
	GLfloat materialAmbientAndDiffuse[] = {1, 1, 1, 1};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbientAndDiffuse); // Defines objects reflection to ambient and diffuse light
	GLfloat materialSpecular[] = {1, 1, 1, 1};
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular); // Defines objects reflection to specular light
	glMaterialf(GL_FRONT, GL_SHININESS, 50); // Defines objects level of reflection (0 to 128)
	GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 1}; glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	GLfloat lightDiffuse[] = {1.0, 1.0, 1.0, 1}; glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	GLfloat lightSpecular[] = {1.0, 1.0, 1.0, 1}; glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	// glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lightSpotCutoff);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, attenuation);
	GLfloat lightPosition[] = {0, 0, 0, 1};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}


#endif //COMPUTER_GRAPHICS_LIGHTNING_H
