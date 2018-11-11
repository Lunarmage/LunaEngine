#include "GL/glew.h"
#include "Component.h"

class Transform:: public Component
{
Private:
	glm::vec3 localPosition;
	glm::vec3 localRotation;
	glm::vec3 localScale;

Public:
//apply amount to existing local variables
void translate(glm::vec3 amount);
void rotate(glm::vec3 amount);
void scale(glm::vec33 amount);

//set local variable to input
void setLocalPostion(glm::vec3 input);
void setLocalRotation(glm::vec3 input);
void setLocalScale(glm::vec3 input);

}