#include <iostream>
#include <SDL2/SDL.h>
#include <GL\glew.h>

#include "engine\BaseInclude.h"





int main()
{
	for (int i=0; i<50;i++)
	{
	//Pre-load/ initialize things here
	std::shared_ptr<Core> baseCore = Core::initialize();
		
	std::shared_ptr<Entity> testEntity= baseCore->addEntity();
	
	//std::shared_ptr<MeshRenderer> testMR = testEntity->addComponent<MeshRenderer>();
	
	//begin loop here
	baseCore->start();
	baseCore->cleanUP();

	baseCore = NULL;
	}

	return 0;
}