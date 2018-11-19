#include "Transform.h"
#include "Environment.h"
#include <glm/ext.hpp>

glm::mat4 Transform::getRenderData()
{
	glm::mat4 temp(1.0f);
	temp = glm::translate(temp, localPosition);
	temp = glm::rotate(temp, localRotation.x, glm::vec3(1, 0, 0));
	temp = glm::rotate(temp, localRotation.y, glm::vec3(0, 1, 0));
	temp = glm::rotate(temp, localRotation.z, glm::vec3(0, 0, 1));
	return temp;
}

void Transform::translate(glm::vec3 amount)
{
	localPosition +=amount;
}

void Transform::rotate(glm::vec3 amount)
{
	localRotation +=amount;
	while (localRotation.x > 360)
	{
		localRotation.x -= 360;
	}
	while (localRotation.y > 360)
	{
		localRotation.y -= 360;
	}
	while (localRotation.z > 360)
	{
		localRotation.z -= 360;
	}
}

void Transform::scale(glm::vec3 amount)
{
	localScale +=amount;
}

void Transform::setLocalPosition(glm::vec3 input)
{
	localPosition=input;
}
void Transform::setLocalRotation(glm::vec3 input)
{
	localRotation=input;
	while (localRotation.x > 360)
	{
		localRotation.x -= 360;
	}
	while (localRotation.y > 360)
	{
		localRotation.y -= 360;
	}
	while (localRotation.z > 360)
	{
		localRotation.z -= 360;
	}
}
void Transform::setLocalScale(glm::vec3 input)
{
	localScale=input;
}

glm::vec3 Transform::getPosition()
{
	return localPosition;
}

glm::vec3 Transform::getRotation()
{
	return localRotation;
}

glm::vec3 Transform::getScale()
{
	return localScale;
}

