#include "Resources.h"

#include <memory>
#include <vector>


#include <SDL2/SDL.h>

class Entity;
class Keyboard;
class Environment;

//class Resources;


class Core
{
	
public:
	~Core();
	static std::shared_ptr<Core> initialize();	
	
	std::shared_ptr<Resources> getResources();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment()
		;

private:
	std::shared_ptr<Environment> environment;
	std::shared_ptr<Keyboard> keyBoard;
	std::vector<std::shared_ptr<Entity>> Entities;

	std::shared_ptr<Resources> resources;
	SDL_Window *window;
	bool running;
	std::weak_ptr<Core> self;

};

