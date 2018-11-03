#include "MeshRenderer.h"



void MeshRenderer::onInit()
{

}

void MeshRenderer::onDisplay()
{

}

void MeshRenderer::setMesh(std::weak_ptr<Mesh> inputMesh)
{	
	mesh=inputMesh;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> inputMaterial;
{
	material=inputMaterial;
}

std::weak_ptr<Mesh> MeshRenderer::getMesh();
{
	return mesh;
}

std::shared_ptr<Material> MeshRenderer::getMaterial();
{
	return material;
}