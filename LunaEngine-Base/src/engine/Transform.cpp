#include "Transform.h"

void Transform:translate(EngineVec3 amount)
{
	localPosition +=amount;
}

void Transform:rotate(EngineVec3 amount)
{
	localRotation +=amount;
}

void Transform:scale(EngineVec3 amount)
{
	localScale +=amount;
}

void Transform:setLocalPosition(EngineVec3 amount)
{
	localPosition=amount;
}
void Transform:setLocalRotation(EngineVec3 amount)
{
	localRotation=amount;
}
void Transform:setLocalScale(EngineVec3 amount)
{
	localScale=amount;
}