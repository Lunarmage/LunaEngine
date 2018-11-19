#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>
#include <algorithm>
#include "Environment.h"

//#include "Resources.h"


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

std::shared_ptr<Resources> Core::getResources()
{
	return resources;
}

std::shared_ptr<Keyboard> Core::getKeyboard()
{
	return keyBoard;
}

std::shared_ptr<Environment> Core::getEnvironment()
{
	return environment;
}

std::shared_ptr<Core> Core::initialize()
{
	
	std::shared_ptr<Resources> Sresources = std::make_shared<Resources>();
	std::shared_ptr<Core> BaseCore =std::make_shared<Core>();
	BaseCore->running =false;
	BaseCore->self=BaseCore;
	BaseCore->resources = Sresources;
	std::shared_ptr<Environment> sEnvironment = std::make_shared<Environment>();
	BaseCore->environment = sEnvironment;
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

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);



	return BaseCore;
}

void Core::start()
{
	float last = SDL_GetTicks();
	running=true;
	

	while (running)
		//usual SDL loop here
	{
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		//loop every entity tick 
		float current=  SDL_GetTicks();
		environment->setDeltaTime(current - last);


		for (std::vector<std::shared_ptr<Entity> >::iterator it = Entities.begin();
			it != Entities.end(); it++)
		{
			if ((*it)->isKill())
			{
				//clear out it
				//Entities.erase(it--);

			}
			else
			{
				(*it)->tick();
			}
		}

		glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		glClearColor(12.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		//loop every entity display
		for (std::vector<std::shared_ptr<Entity> >::iterator it = Entities.begin();
			it != Entities.end(); it++)
		{
			(*it)->display();
		}

		SDL_GL_SwapWindow(window);

		
	}

	
}


void Core::stop()
{
	running = false;
}



Core::~Core()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}