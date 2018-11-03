#include "Entity.h"

void Entity::tick()
{	
	for_each(components.begin(), components.end(), doTick);
}

void Entity::display()
{	
	/*
	//for each Component in components
	{
		//if not end  increase iterator
		iterator->onDisplay();
	}
	*/
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

void doTick(std::shared_ptr<Component> thing)
{
	if (!(thing->began))
	{
		thing->onBegin();
		thing->began=true;	
	}
	thing->onTick();
}