#include "Core.h"
#include "Entity.h"
#include GL/glew.h


int WINDOW_WIDTH =800;
int  WINDOW_HEIGHT =600;

std::shared_ptr<Entity> addEntity()
{
	std::shared_ptr<Entity> newEnt = std::make_shared<Entity>;
	entities.pushback(newEnt);
	newEnt->self=newEnt;
	newEnt->core=self;

	return newEnt;

}

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> BaseCore =std::make_shared<Core>();
	BaseCore->running =false;
	BaseCore->self=BaseCore;
	
	//Initialise Visuals/graphics first

	//if(SDL_Init(SDL_INIT_VIDEO) <0)
	{
	//throw except
	}

	BaseCore->window = SDL_CreateWindow("LunaEngine", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWSPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,SDLL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL);
	
	if (!SDL_GL_CreateContext(BaseCore->))
	{
	//throw except
	}

	//do all other inits
	if(glewInit() !=GLEW_OK)
	{//throwexecption}

	//initialise audio

}

void Core::start()
{
	running=true;
	
	while(running)
	//usual SDL loop here
	{
		SDL_Event event=0;
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
			{running=false;}
			}
		}
		//loop every entity tick 
		for_each(Entities.begin(), Entities.end(), doTick);

		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//loop every entity display
		for_each(Entities.begin(), Entities.end(), doDisplay);

		SDL_GL_SwapWindow(window);
	}

}

void doTick(std::shared__ptr<Entity> tarEnt)
{
	tarEnt->tick();
}

void doDisplay(std::shared__ptr<Entity> tarEnt)
{
	tarEnt->display();
}

void Core::stop()
{
running=false;

}