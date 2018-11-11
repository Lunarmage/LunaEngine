

#include <memory>
#include <vector>


#include <SDL2/SDL.h>

class Entity;
class Keyboard;
class Environment;

class Resources;


class Core
{
	
public:
	static std::shared_ptr<Core> initialize();	
	
	std::shared_ptr<Resources> getResources();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	void cleanUP();


private:
	std::shared_ptr<Environment> Environment;
	std::shared_ptr<Keyboard> KeyBoard;
	std::vector<std::shared_ptr<Entity>> Entities;

	std::shared_ptr<Resources> resources;
	SDL_Window *window;
	bool running;
	std::weak_ptr<Core> self;

};

