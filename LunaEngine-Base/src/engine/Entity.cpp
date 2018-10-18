#include "Entity.h"

void Entity::tick()
{	
	//for each Component in components
	{
		//if not end  increase iterator
		iterator->onTick();
	}
}

