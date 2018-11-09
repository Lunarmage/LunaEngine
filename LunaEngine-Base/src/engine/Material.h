#include "MaterialAttribute.h"
#include <memory>
#include <string>


class Shader;
class Texture;

class Material{
public:
void setShader(std::weak_ptr<Shader> newShader);
std::shared_ptr<Shader> getShader();
void setValue(std::string name, std::weak_ptr<Texture> value);
void setValue(std::string name, float value);
private:
std::weak_ptr<Shader> shader;
std::vector<MaterialAttribute> attributes;

};