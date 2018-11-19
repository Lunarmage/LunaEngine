#include <iostream>
#include <SDL2/SDL.h>
#include <GL\glew.h>
#include <string>
#include "engine\BaseInclude.h"

#include "glm\glm.hpp"
#include <glm/ext.hpp>




int main(int argc, char *argv[])
{
	//for (int i=0; i<50;i++)
	
	//Pre-load/ initialize things here
	std::shared_ptr<Core> baseCore = Core::initialize();
		
	std::shared_ptr<Entity> testEntity= baseCore->addEntity();
	
	std::shared_ptr<MeshRenderer> testMR = testEntity->addComponent<MeshRenderer>();


	std::shared_ptr<Mesh> testMesh = baseCore->getResources()->load<Mesh>("../curuthers.obj");
	std::shared_ptr<Texture> testTex = baseCore->getResources()->load<Texture>("../curuthers_diffuse.png");
	std::shared_ptr<Material> baseMat = std::make_shared<Material>();
	std::shared_ptr<Transform> baseTrans = testEntity->addComponent<Transform>();
	baseTrans->setLocalPosition(glm::vec3(0.0f, -2.0f, -10.0f));

	baseMat->setValue("blank", testTex);
	std::shared_ptr<Shader> testShad = baseCore->getResources()->load<Shader>("TestShader");
	testShad->create("../simple.vert", "../simple.frag");
	baseMat->setShader(testShad);
	
	testMR->setMesh(testMesh);
	testMR->setMaterial(baseMat);

	//perspective matrix
	testShad->setUniform("in_Projection", glm::perspective(glm::radians(45.0f), (float)(800 / 600), 0.1f, 1000.0f));

	//test camera
	//in practice we'd seek out the camera component in all entities and grab that (possible to make a list of cameras in core to make it easier to aquire?)
	glm::mat4 camera(1.0f);
	camera = glm::translate(camera, glm::vec3(-5.0f, 0, 0));
	camera = glm::rotate(camera, glm::radians(0.0f), glm::vec3(0, 1.0f, 0));
	testShad->setUniform("in_View", glm::inverse(camera));

	//begin loop here
	baseCore->start();
	

	

	return 0;

}