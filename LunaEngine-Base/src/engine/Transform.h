#pragma once

#include "glm/glm.hpp"
#include "Component.h"



class Transform: public Component
{
private:
	//I named everything local because I'm a bit stupid. Local Position is in fact world position for the purposes of graphics
	glm::vec3 localPosition;
	glm::vec3 localRotation;
	glm::vec3 localScale;

public:
//apply amount to existing local variables
void translate(glm::vec3 amount);
void rotate(glm::vec3 amount);
void scale(glm::vec3 amount);

//set local variable to input
void setLocalPosition(glm::vec3 input);
void setLocalRotation(glm::vec3 input);
void setLocalScale(glm::vec3 input);

//return variables
glm::vec3 getPosition();
glm::vec3 getRotation();
glm::vec3 getScale();

glm::mat4 getRenderData();
};

