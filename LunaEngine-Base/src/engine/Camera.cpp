#include "Camera.h"
#include "glm\ext.hpp"
#include "Transform.h"
#include "Entity.h"

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 cam= glm::mat4(1.0f);
	glm::vec3 truePosition = (getEntity()->getComponent<Transform>()->getPosition()) +cameraOffset;
	cam = glm::translate(cam, truePosition);



	return cam;
}

void Camera::setOffset(glm::vec3 input)
{
	cameraOffset = input;
}
void Camera::setRotation(glm::vec3 input)
{
	cameraRotate = input;
}