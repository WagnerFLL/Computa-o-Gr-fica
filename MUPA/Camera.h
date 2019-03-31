#ifndef COMPUTER_GRAPHICS_CAMERA_H
#define COMPUTER_GRAPHICS_CAMERA_H

glm::mat4 view;
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
glm::vec3 temp = cameraPos + cameraFront;
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

void processCamera()
{
	temp = cameraPos + cameraFront;
	glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	gluLookAt(cameraPos[0], cameraPos[1] , cameraPos[2],  // de onde
              temp[0], temp[1],temp[2], // pra onde
			  cameraUp[0], cameraUp[1], cameraUp[2]); // como
}

void processNormalKeys(unsigned char key, int x, int y) {
	float cameraSpeed = 2.5f * deltaTime;
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
