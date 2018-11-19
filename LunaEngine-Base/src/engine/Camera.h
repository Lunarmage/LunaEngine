#include "Component.h"
#include "Transform.h"

class Camera: public Component
{
public:
	glm::mat4 getViewMatrix();
	void setOffset(glm::vec3 input);
	void setRotation(glm::vec3 input);
private:
	glm::vec3 cameraOffset;
	glm::vec3 cameraRotate;

};