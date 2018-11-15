#include "Entity.h"
#include <algorithm>
#include "Core.h"


/*template <typename T>
std::shared_ptr<T> Entity::getComponent()
{
	for (int i = 0; i<components.size(); i++)
	{
		std::shared_ptr<T> TargetComponent = std::dynamic_pointer_cast<T>(components.at(i));
			if (TargetComponent)
			{
				return TargetComponent
			}
	}

	//throw exception here, ie component not found
}*/
/*
template <typename T>
std::shared_ptr<T> Entity::addComponent()
{
	std::shared_ptr<T> NewComp = std::make_shared<T>();
	NewComp->HostEntity = self;
	components.pushback(NewComp);
	NewComp->onInit();
	return NewComp;
}*/


std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

void Entity::tick()
{
	for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
		it != components.end(); it++)
	{
		(*it)->onTick();
	}
}
void Entity::display()
{
	for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
		it != components.end(); it++)
	{
		(*it)->onDisplay();
	}

}


void Entity::setSelf(std::weak_ptr<Entity> ref)
{
	self = ref;
}

void Entity::setCore(std::weak_ptr<Core> ref)
{
	core = ref;
}
