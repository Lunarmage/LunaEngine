#include "Shader.h"
#include "Texture.h"
#include "Material.h"

void Material::setValue(std::string name, std::weak_ptr<Texture> value)
{
	attributes.textureValue=value;
}

void Material::setValue(std::string name, float value)
{
	attributes.floatValue=value;
}


std::shared_ptr<Shader> Material::getShader()
{
 return shader.lock();

}

void Material::setShader(std::weak_ptr<Shader> newShader)
{
	shader= newShader;
}
GLuint Material::getTexID()
{
	return attributes.textureValue.lock()->getID();
}
