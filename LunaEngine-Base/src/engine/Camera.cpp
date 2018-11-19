#include "Camera.h"
#include "glm\ext.hpp"
#include "Transform.h"
#include "Entity.h"

void Camera::onInit()
{
	//gets this component from the entity
	getEntity()->getComponent<Camera>();
	//put that reference into Core::addCamera()
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 cam= glm::mat4(1.0f);
	glm::vec3 truePosition = (getEntity()->getComponent<Transform>()->getPosition()) +cameraOffset;

	cam = glm::translate(cam, truePosition);
	glm::vec3 trueRotation = (getEntity()->getComponent<Transform>()->getRotation() + cameraRotate);
	while (trueRotation.x > 360)
	{
		trueRotation.x -= 360;
	}
	while (trueRotation.y > 360)
	{
		trueRotation.y -= 360;
	}
	while (trueRotation.z > 360)
	{
		trueRotation.z -= 360;
	}
	cam = glm::rotate(cam, glm::radians(trueRotation.x), glm::vec3(1, 0, 0));
	cam = glm::rotate(cam, glm::radians(trueRotation.y), glm::vec3(0, 1, 0));
	cam = glm::rotate(cam, glm::radians(trueRotation.z), glm::vec3(0, 0, 1));

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