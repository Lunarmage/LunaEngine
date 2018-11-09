#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>
#include <algorithm>


int WINDOW_WIDTH =800;
int  WINDOW_HEIGHT =600;

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> newEnt = std::make_shared<Entity>();
	Entities.push_back(newEnt);
	newEnt->setSelf(newEnt);
	newEnt->setCore(self);

	return newEnt;

}


std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> BaseCore =std::make_shared<Core>();
	BaseCore->running =false;
	BaseCore->self=BaseCore;
	
	//Initialise Visuals/graphics first

	if(SDL_Init(SDL_INIT_VIDEO) <0)
	{
	//throw except
	}

	BaseCore->window = SDL_CreateWindow("LunaEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL);
	
	if (!SDL_GL_CreateContext(BaseCore->window))
	{
		throw std::exception();
	//throw except
	}

	//do all other inits
	if (glewInit() != GLEW_OK)
	{	//throw except
		throw std::exception();
	}
	//initialise audio




	return BaseCore;
}

void Core::start()
{
	running=true;
	
	while(running)
	//usual SDL loop here
	{
		SDL_Event event = { 0 };
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
			{running=false;}
		}
	}
		//loop every entity tick 
	
		for (std::vector<std::shared_ptr<Entity> >::iterator it = Entities.begin();
			it != Entities.end(); it++)
		{
			(*it)->tick();
		}

		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//loop every entity display
		for (std::vector<std::shared_ptr<Entity> >::iterator it = Entities.begin();
			it != Entities.end(); it++)
		{
			(*it)->display();
		}

		SDL_GL_SwapWindow(window);
	

}



void Core::stop()
{
running=false;

}