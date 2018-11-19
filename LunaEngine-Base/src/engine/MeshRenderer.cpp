#include "MeshRenderer.h"
#include "Mesh.h"
#include"Shader.h"
#include "Entity.h"
#include "Transform.h"


#include <glm/ext.hpp>

void MeshRenderer::onInit()
{

}

void MeshRenderer::onDisplay()
{
	

	//get position in worldspace
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, HostEntity.lock()->getComponent<Transform>()->getPosition());
	model = HostEntity.lock()->getComponent<Transform>()->getRenderData();
	material->getShader()->setUniform("in_Model",model);

	material->getShader()->setUniform("in_Texture", 0);
	

	//assign texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, material->getTexID());
	
	material->getShader()->setUniform("in_Texture", 0);

	
	//assign shaderProgram
	glUseProgram(material->getShader()->getID());
	//draw mesh
	glBindVertexArray(mesh.lock()->returnID());
	glDrawArrays(GL_TRIANGLES, 0, mesh.lock()->getVertexCount());
	glBindVertexArray(0);
	glUseProgram(0);

}

void MeshRenderer::setMesh(std::weak_ptr<Mesh> inputMesh)
{	
	mesh=inputMesh;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> inputMaterial)
{
	material=inputMaterial;
}

std::weak_ptr<Mesh> MeshRenderer::getMesh()
{
	return mesh;
}

std::shared_ptr<Material> MeshRenderer::getMaterial()
{
	return material;
}