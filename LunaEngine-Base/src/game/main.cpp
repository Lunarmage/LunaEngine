#include <iostream>
#include <SDL2/SDL.h>
#include <GL\glew.h>
#include <string>
#include "engine\BaseInclude.h"






int main(int argc, char *argv[])
{
	//for (int i=0; i<50;i++)
	
	//Pre-load/ initialize things here
	std::shared_ptr<Core> baseCore = Core::initialize();
		
	std::shared_ptr<Entity> testEntity= baseCore->addEntity();
	
	std::shared_ptr<MeshRenderer> testMR = testEntity->addComponent<MeshRenderer>();


	std::shared_ptr<Mesh> testMesh = baseCore->getResources()->load<Mesh>("../curuthers.obj");
	std::shared_ptr<Texture> testTex = baseCore->getResources()->load<Texture>("../Skull.bmp");
	std::shared_ptr<Material> baseMat = std::make_shared<Material>();

	baseMat->setValue("blank", testTex);
	std::shared_ptr<Shader> testShad = baseCore->getResources()->load<Shader>("TestShader");
	testShad->create("../simple.vert", "../simple.frag");
	baseMat->setShader(testShad);
	//begin loop here
	testMR->setMesh(testMesh);
	testMR->setMaterial(baseMat);
	baseCore->start();
	

	

	return 0;

}