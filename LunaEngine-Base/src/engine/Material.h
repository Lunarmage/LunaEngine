#include "Shader.h"
#include "MaterialAttribute.h"
#include <memory>
#include <string>

class Material{
public:
void setShader(std::weak_ptr<Shader> newShader);
std::shared_ptr<Shader> getShader();
void setValue(std::string name, std::weak_Ptr<Texture> value);
void setValue(std::string name, float value);
private:
std::weak_ptr<Shader> shader;
std::vector<MaterialAttributes> attributes;

}