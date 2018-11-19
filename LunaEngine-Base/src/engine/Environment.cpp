#include "Environment.h"
#include "SDL2\SDL.h"
float Environment::getDeltaTime()
{
	return deltaTime;
}

void Environment::setDeltaTime(float diff)
{
	deltaTime = diff/1000.0f;
	if (deltaTime < (1 / 60))
	{
		SDL_Delay(((1 / 60) - deltaTime)*1000.0f);
	}
}

Environment::Environment()
{

}

Environment::~Environment()
{

}