#include <memory>
#include <vector>
#include "Environment.h"
#include "Keyboard.h"
#include <SDL2/SDL.h>

class Core
{
public:
	std::shared_ptr<Cire> initialize();	

	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();


private:
	std::shared_ptr<Environment> Environment;
	std::shared_ptr<Keyboard> KeyBoard;
	std::vector<std::shared_ptr<Entity>> Entities;
	SDL_Window *window;
	bool running;
};

