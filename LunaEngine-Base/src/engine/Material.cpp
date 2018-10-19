#include "Material.h"

void Material::setValue(std::string name, std::weak_Ptr<Texture> value)
{
	attributes.name=name;
	attributes.textureValue=value;
}

void Material::setValue(std::string name, float value)
{
	attributes.name=name;
	attributes.floatValue=value;
}


std::shared_ptr<Shader> Material::getShader()
{
 return shader;

}

void Material::setShader(std::weak_ptr<Shader> newShader);
{
	shader= newShader
}
