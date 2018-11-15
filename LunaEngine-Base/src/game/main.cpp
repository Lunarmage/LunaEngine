#include <iostream>
#include <SDL2/SDL.h>
#include <GL\glew.h>

#include "engine\BaseInclude.h"





int main(int argc, char *argv[])
{
	//for (int i=0; i<50;i++)
	
	//Pre-load/ initialize things here
	std::shared_ptr<Core> baseCore = Core::initialize();
		
	std::shared_ptr<Entity> testEntity= baseCore->addEntity();
	
	std::shared_ptr<MeshRenderer> testMR = testEntity->addComponent<MeshRenderer>();

	//std::shared_ptr<MeshRenderer> testMR = testEntity->addComponent<MeshRenderer>();
	//std::shared_ptr<Mesh> testMesh = baseCore->getResources()->load<Mesh>("curuthers.obj");
	//begin loop here
	baseCore->start();
	

	

	return 0;
}