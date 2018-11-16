#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

class Entity;
class Core;

class Environment;
class Keyboard;

class Component
{
	friend class Entity;
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	//std::shared_ptr<Resources> getResources();
protected:
	std::weak_ptr<Entity> HostEntity;
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();

	bool began = false;
};

#endif