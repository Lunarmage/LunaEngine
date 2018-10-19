#include string
#include memory
#include "Resource.h"
#include GL/glew.h


class Shader: public Resource
{
Public:
void setUniform(std::string name, float value);
void setUniform(std::string name, std::weak_ptr<Texture> value);
void setUniform(std::string name, mat4 value);
void setUniform(std::string name, vec3 value);
Private:
std::shared_ptr<Shader> load(std::string path)
};