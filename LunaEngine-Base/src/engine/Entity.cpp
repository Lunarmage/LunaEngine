#include "Entity.h"
#include <algorithm>
#include "Core.h"





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



void Entity::setSelf(std::weak_ptr<Entity> ref)
{
	self = ref;
}

void Entity::setCore(std::weak_ptr<Core> ref)
{
	core = ref;
}
