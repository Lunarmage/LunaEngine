#include <iostream>
#include <SDL2/SDL.h>
#include <GL\glew.h>

#include "engine\BaseInclude.h"





int main()
{
	//Pre-load/ initialize things here
	std::shared_ptr<Core> baseCore = Core::initialize();
		
	std::shared_ptr<Entity> testEntity= baseCore->addEntity();

	//std::shared_ptr<MeshRenderer> testMR = testEntity->addComponent<MeshRenderer>();
	
	//begin loop here
	baseCore->start();
	

	return 0;
}