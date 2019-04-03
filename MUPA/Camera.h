#ifndef COMPUTER_GRAPHICS_CAMERA_H
#define COMPUTER_GRAPHICS_CAMERA_H

glm::mat4 view;
glm::vec3 cameraPos   = glm::vec3(10.0f, 3.0f,  50.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
glm::vec3 temp = cameraPos + cameraFront;
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame
bool light = true;

void mouseMovement(int x, int y) {
	mouseX = x;
	mouseY = y;
}

void disableLight() {
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

}

void enableLight() {
    if (light) {
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void mouseMotion(int x, int y) {
	if (xOrigin >= 0) {
		deltaAngle = (x - xOrigin) * 0.01f;
		cameraFront[0] = sin(angle + deltaAngle);
		cameraFront[2] = -cos(angle + deltaAngle);
	}
}


void processCamera() {
	temp = cameraPos + cameraFront;
	glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	gluLookAt(cameraPos[0], cameraPos[1] , cameraPos[2],  // de onde
              temp[0], temp[1],temp[2], // pra onde
			  cameraUp[0], cameraUp[1], cameraUp[2]); // como
}

void processNormalKeys(unsigned char key, int x, int y) {
	float cameraSpeed = 0.12f;
	switch(key) {
		case 'w':
			cameraPos += cameraSpeed * cameraFront;
			break;

		case 's':
			cameraPos -= cameraSpeed * cameraFront;
			break;

		case 'a':
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			break;

		case 'd':
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			break;

		case 32:
			if(cameraPos[1] < 8)
				cameraPos += cameraSpeed * cameraUp;
			break;

		case 'f':
			if(cameraPos[1] > 0.5)
				cameraPos -= cameraSpeed * cameraUp;
			printf("x = %f, y = %f, z = %f\n", cameraPos[0], cameraPos[1] , cameraPos[2]);
			break;

		case 'o':
			if (door_angle <= 118.0f) door_angle += 2.0f;
			glutPostRedisplay();
			break;

		case 'c':
			if (door_angle >= 2.0f) door_angle -= 2.0f;
			glutPostRedisplay();
			break;

		case 27:
			exit(0);
			break;

		case 'l':
		    if (light)
                light = false;
            else
                light = true;

			break;
	}
}
#endif //COMPUTER_GRAPHICS_CAMERA_H
