

#include <memory>
#include <vector>


#include <SDL2/SDL.h>

class Entity;
class Keyboard;
class Environment;



class Core
{
	
public:
	static std::shared_ptr<Core> initialize();	

	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();


private:
	std::shared_ptr<Environment> Environment;
	std::shared_ptr<Keyboard> KeyBoard;
	std::vector<std::shared_ptr<Entity>> Entities;
	SDL_Window *window;
	bool running;
	std::weak_ptr<Core> self;

};

