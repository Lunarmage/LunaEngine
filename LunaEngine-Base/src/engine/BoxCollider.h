#include "Collider.h"
#include  "glm/glm.hpp"

class BoxCollider:public Collider
{
private:
	glm::vec3 size;
public:
	void setSize(glm::vec3);
	void setSize(int x, int y, int z);
	glm::vec3 getSize();
};