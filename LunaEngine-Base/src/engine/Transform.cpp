#include "Transform.h"

void Transform::translate(glm::vec3 amount)
{
	localPosition +=amount;
}

void Transform::rotate(glm::vec3 amount)
{
	localRotation +=amount;
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
}
void Transform::setLocalScale(glm::vec3 input)
{
	localScale=input;
}