#include <memory>

class Component
{
public:
	std::shared_ptr<Entity> getEntity();
	std::shard_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
private:
	std::weak_ptr<Entity> HostEntity
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();

};