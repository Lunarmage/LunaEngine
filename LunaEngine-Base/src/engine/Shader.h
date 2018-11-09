#include <string>
#include <memory>

#include "GL/glew.h"
#include "glm\glm.hpp"

#include "VertexBuffer.h"

class Texture;

#include "Resource.h"

class Shader: public Resource
{
public:
void create(std::string vert, std::string frag);

void setUniform(std::string name, float value);
void setUniform(std::string name, std::weak_ptr<Texture> value);
void setUniform(std::string name, glm::vec3 value);

GLuint getID();
private:


GLuint id;
};