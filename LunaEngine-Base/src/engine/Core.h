#include <memory>
#include <vector>
#include "Environment.h"
#include "Keyboard.h"

class Core
{
public:
	Core();
	~Core();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();


private:
	std::shared_ptr<Environment> Environment;
	std::shared_ptr<Keyboard> KeyBoard;
	std::vector<std::shared_ptr<Entity>> Entities;
	bool running;
};

