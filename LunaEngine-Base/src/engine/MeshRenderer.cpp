#include "MeshRenderer.h"
#include "Mesh.h"
#include"Shader.h"


void MeshRenderer::onInit()
{

}

void MeshRenderer::onDisplay()
{

	//assign shaderProgram
	glUseProgram(material->getShader()->getID());


	//assign texture
	glActiveTexture(GL_TEXTURE0 +1);
	glBindTexture(GL_TEXTURE_2D, material->getTexID());
	
	//draw mesh
	glBindVertexArray(mesh.lock()->returnID());
	glDrawArrays(GL_TRIANGLES, 0, mesh.lock()->getVertexCount());
	glBindVertexArray(0);

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