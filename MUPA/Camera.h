#ifndef COMPUTER_GRAPHICS_CAMERA_H
#define COMPUTER_GRAPHICS_CAMERA_H

glm::mat4 view;
glm::vec3 cameraPos   = glm::vec3(10.0f, 3.0f,  50.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
glm::vec3 temp = cameraPos + cameraFront;
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

void mouseMovement(int x, int y)
{
	printf("x = %d\n", x);
	printf("y = %d\n", y);
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

void mouseMove(int x, int y) {
	if (xOrigin >= 0) {
		deltaAngle = (x - xOrigin) * 0.01f;
		cameraFront[0] = sin(angle + deltaAngle);
		cameraFront[2] = -cos(angle + deltaAngle);
	}
}


void processCamera()
{
	temp = cameraPos + cameraFront;
	glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	gluLookAt(cameraPos[0], cameraPos[1] , cameraPos[2],  // de onde
              temp[0], temp[1],temp[2], // pra onde
			  cameraUp[0], cameraUp[1], cameraUp[2]); // como
	//	gluLookAt(x, cam , z,  // de onde
	//			  x+lx, cam, z+lz, // pra onde
	//			  0.0f, 1.0f, 0.0f); // como
}

void processNormalKeys(unsigned char key, int x, int y) {
	float cameraSpeed = 0.2f * deltaTime;
	switch(key){
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
			printf("ola");
			cameraPos += cameraSpeed * cameraUp;
			break;

		case 'f':
			printf("ola");
			cameraPos -= cameraSpeed * cameraUp;
			break;

		case 'o':
			if(door_angle <= 118.0f) door_angle += 2.0f;
			glutPostRedisplay();
			break;

		case 'c':
			if(door_angle >= 2.0f) door_angle -= 2.0f;
			glutPostRedisplay();
			break;

		case 27:
			exit(0);
			break;
	}
}
#endif //COMPUTER_GRAPHICS_CAMERA_H
