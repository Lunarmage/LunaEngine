#include "MaterialAttribute.h"
#include <memory>
#include <string>
#include <GL\glew.h>

class Shader;
class Texture;

class Material{
public:
void setShader(std::weak_ptr<Shader> newShader);
GLuint getTexID();
std::shared_ptr<Shader> getShader();
void setValue(std::string name, std::weak_ptr<Texture> value);
void setValue(std::string name, float value);
private:
std::weak_ptr<Shader> shader;
MaterialAttribute attributes;

};